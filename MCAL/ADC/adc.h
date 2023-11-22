/*
 * adc.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include"../../Std_Types.h"
#include"../../Bit_Math.h"
#include"adc_cfg.h"
#include"adc_register.h"
#include"adc_private.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

u16 ADC_ReadChannel(uint8_t channel);



#endif /* MCAL_ADC_ADC_H_ */
