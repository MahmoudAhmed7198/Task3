/*
 * TWI_interface.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

void TWI_InitMaster           (uint8_t Copy_u8Add);
void TWI_send_start_condition   (void);
void TWI_send_repeated_start_condition(void);
void TWI_stop_condition    (void);
void TWI_send_slave_addressWithWrite(uint8_t Copy_u8SlaveAdd);
void TWI_send_slave_addressWithRead (uint8_t Copy_u8SlaveAdd);
void TWI_WriteMasterDataByte  (uint8_t Copy_u8TxData);
void TWI_ReadMasterDataByte   (uint8_t* Copy_pu8RxData);

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
