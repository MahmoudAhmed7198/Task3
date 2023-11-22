/*
 * TWI_register.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TWI_TWI_REGISTER_H_
#define MCAL_TWI_TWI_REGISTER_H_


#define TWCR_reg *((volatile uint8_t*)(0x56))
#define TWDR_reg *((volatile uint8_t*)(0x23))
#define TWAR_reg *((volatile uint8_t*)(0x22))
#define TWSR_reg *((volatile uint8_t*)(0x21))
#define TWBR_reg *((volatile uint8_t*)(0x20))


#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7


#define TWGCE   0


#define TWPS0   0
#define TWPS1   1



#endif /* MCAL_TWI_TWI_REGISTER_H_ */
