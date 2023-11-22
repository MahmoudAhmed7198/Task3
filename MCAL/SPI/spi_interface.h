/*
 * spi_interface.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
void spi_void_Init(void); //#if mode==master #elif mode==slave
void spi_transieve(uint8_t TXdata, uint8_t* ptrRX);
void spi_transmit_Asynch(uint8_t TXData, void (*ptrToFun)(uint8_t));



#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
