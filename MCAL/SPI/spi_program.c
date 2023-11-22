/*
 * spi_program.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Lenovo
 */

#include"../../Bit_Math.h"
#include"../../Std_Types.h"
#include"spi_register.h"
#include"spi_interface.h"
#include"spi_register.h"
#include"spi_cfg.h"
#include"spi_private.h"
#include"../../MCAL/Dio/Dio.h"



static void (*ptrCallBack)(uint8_t)=NULL;
void spi_void_Init(void)
{

 #if SPI_MODE == MASTER_MODE
    // select Master Mode
    SET_BIT(SPI_ptr->SPCR_reg,MSTR);

	// select CLK Rate = FCPU/16 (1 MHZ)
	SET_BIT(SPI_ptr->SPCR_reg,SPR0);
	CLR_BIT(SPI_ptr->SPCR_reg,SPR1);
    CLR_BIT(SPI_ptr->SPSR_reg,SPI2X);
    Dio_SetChannel_Dir(PB_4, OUTPUT);
    Dio_SetChannel_Dir(PB_5, OUTPUT);
    Dio_SetChannel_Dir(PB_6, INPUT);
    Dio_SetChannel_Dir(PB_7, OUTPUT);

 #elif SPI_MODE == SLAVE_MODE
    // select Slave Mode
    CLR_BIT(SPI_ptr->SPCR_reg,MSTR);
 #endif

	//select Data Order LSB transmitted first
	SET_BIT(SPI_ptr->SPCR_reg,DORD);

    // select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPI_ptr->SPCR_reg,CPOL);
	SET_BIT(SPI_ptr->SPCR_reg,CPHA);

	// Enable SPI
	SET_BIT(SPI_ptr->SPCR_reg,SPE);



}
void spi_transieve(uint8_t TXdata, uint8_t* ptrRX)
{
	if(ptrRX!=NULL)
	{
		while(GET_BIT(SPI_ptr->SPSR_reg,WCOL)==1);
		SPI_ptr->SPDR_reg=TXdata;
		while(GET_BIT(SPI_ptr->SPSR_reg,SPIF)==0);
		*ptrRX=SPI_ptr->SPDR_reg;
	}

}

void spi_transmit_Asynch(uint8_t TXData, void (*ptrToFun)(uint8_t RXData))
{
	if(ptrToFun!=NULL)
	{
		//enable spi interrupt
		SET_BIT(SPI_ptr->SPCR_reg,SPIE);
		ptrCallBack=ptrToFun;
		while(GET_BIT(SPI_ptr->SPSR_reg,WCOL)==1);
				SPI_ptr->SPDR_reg=TXData;
	}
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if(ptrCallBack!=NULL)
	{
		ptrCallBack(SPI_ptr->SPDR_reg);
	}
}
