/*
 * spi_register.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_
#include"../../Std_Types.h"
typedef struct SPI_regs {
	uint8_t SPCR_reg;
	uint8_t SPSR_reg;
	uint8_t SPDR_reg;
}SPI_regs;

#define SPI_ptr ((volatile SPI_regs*)(0x2D)) //0x2D is base address or address of SPCR


//SPCR bits
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE  6
#define SPIE 7


#define SPI2X 0
#define WCOL  6
#define SPIF  7

#endif /* MCAL_SPI_SPI_REGISTER_H_ */
