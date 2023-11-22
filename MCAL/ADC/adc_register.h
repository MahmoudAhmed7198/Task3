/*
 * adc_register.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_
//ADC Registers
#include"../../Std_Types.h"
#define ADMUX_reg  *((volatile uint8_t*)(0x27))
#define ADCSRA_reg *((volatile uint8_t*)(0x26))
#define ADCH_reg   *((volatile uint8_t*)(0x25))
#define ADCL_reg   *((volatile uint8_t*)(0x24))
#define SFIOR_reg  *((volatile uint8_t*)(0x50))

//register bits
//1-ADMUX bits
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7
//2-ADCSRA bits
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7





#endif /* MCAL_ADC_ADC_REGISTER_H_ */
