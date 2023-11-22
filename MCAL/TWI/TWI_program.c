/*
 * TWI_program.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Lenovo
 */

#include"../../Std_Types.h"
#include"../../Bit_Math.h"
#include"TWI_interface.h"
#include"TWI_private.h"
#include"TWI_register.h"

void TWI_InitMaster(uint8_t Copy_u8Add)
{
	if((Copy_u8Add<128)&&(Copy_u8Add>0))
	{
		TWAR_reg = Copy_u8Add<<1;
	}

	// Set Prescaller = 1 >> Set Freq. = 400KHZ
	TWBR_reg = 12;
	CLR_BIT(TWSR_reg,TWPS0);
	CLR_BIT(TWSR_reg,TWPS1);

	// Enable ACK
	SET_BIT(TWCR_reg,TWEA);

	// Enable TWI peripheral
	SET_BIT(TWCR_reg,TWEN);
}


void TWI_send_start_condition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_reg,TWSTA);

	// Clear flag to start current job
	SET_BIT(TWCR_reg,TWINT);

	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_reg,TWINT));

	// Check ACK = SC ACK
	while(TWI_STATUS_VALUE != TWI_START_CONDITION_ACK);
}


void TWI_send_repeated_start_condition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_reg,TWSTA);

	// Clear flag to start current job
	SET_BIT(TWCR_reg,TWINT);

	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_reg,TWINT));

	// Check ACK = Repeated SC ACK
	while(TWI_STATUS_VALUE != TWI_REP_START_CONDITION_ACK);
}


void TWI_stop_condition(void)
{
	// Request Stop Condition
	SET_BIT(TWCR_reg,TWSTO);

	// Clear flag to start current job
	SET_BIT(TWCR_reg,TWINT);
}


void TWI_send_slave_addressWithWrite(uint8_t Copy_u8SlaveAdd)
{
	if(Copy_u8SlaveAdd<128)
	{
		TWDR_reg = Copy_u8SlaveAdd<<1;

		// Select write operation
		CLR_BIT(TWDR_reg,0);

		// Clear Start Condition bit
		CLR_BIT(TWCR_reg,TWSTA);

		// Clear flag to start current job
		SET_BIT(TWCR_reg,TWINT);

		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_reg,TWINT));

		// Check ACK = Master transmit ( slave address + Write request ) ACK
		while(TWI_STATUS_VALUE != TWI_SLAVE_ADDRESS_WRITE_ACK);
	}
}


void TWI_send_slave_addressWithRead(uint8_t Copy_u8SlaveAdd)
{
	if(Copy_u8SlaveAdd<128)
	{
		TWDR_reg = Copy_u8SlaveAdd<<1;

		// Select read operation
		SET_BIT(TWDR_reg,0);

		// Clear Start Condition bit
		CLR_BIT(TWCR_reg,TWSTA);

		// Clear flag to start current job
		SET_BIT(TWCR_reg,TWINT);

		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_reg,TWINT));

		// Check ACK = Master transmit ( slave address + Read request ) ACK
		while(TWI_STATUS_VALUE != TWI_SLAVE_ADDRESS_READ_ACK);
	}
}


void TWI_WriteMasterDataByte(uint8_t Copy_u8TxData)
{
	TWDR_reg = Copy_u8TxData;

	// Clear flag to start current job
    SET_BIT(TWCR_reg,TWINT);

	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_reg,TWINT));

	// Check ACK = Master transmit data ACK
	while(TWI_STATUS_VALUE != TWI_MASTER_DATA_TRANSMIT_ACK);
}


void TWI_ReadMasterDataByte(uint8_t* Copy_pu8RxData)
{
	if(Copy_pu8RxData != NULL)
	{
		// Clear flag to start current job
        SET_BIT(TWCR_reg,TWINT);

	    // Busy Wait for the flag
	    while(0 == GET_BIT(TWCR_reg,TWINT));

	    // Check ACK = Master received data with ACK
	    while(TWI_STATUS_VALUE != TWI_MASTER_DATA_RECIEVE_ACK);

		// Read Data from data register
		*Copy_pu8RxData = TWDR_reg;
	}
}


