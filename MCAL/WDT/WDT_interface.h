/*
 * WDT_interface.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_


#define WDT_TIME_16_3  1
#define WDT_TIME_32_3  2
#define WDT_TIME_65    3
#define WDT_TIME_0_13  4
#define WDT_TIME_0_26  5
#define WDT_TIME_0_52  6
#define WDT_TIME_1     7
#define WDT_TIME_2_1   8


void WDT_Enable (uint8_t overflow_time);
void WDT_Disable();


#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
