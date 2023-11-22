/*
 * EXTI_register.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_EXTI_EXTI_REGISTER_H_
#define MCAL_EXTI_EXTI_REGISTER_H_


#define MCUCR_reg *((volatile uint8_t*)(0x55))//control register(sense control)(control INT0,INT1)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define MCUCSR_reg *((volatile uint8_t*)(0x54))//control and status register(control INT2)
#define ISC2  6



#define GICR_reg *((volatile uint8_t*)(0x5B))//Peripheral Interrupt Enable(PIE)
#define INT0 6
#define INT1 7
#define INT2 5



#define GIFR_reg *((volatile uint8_t*)(0x5A))//Peripheral Interrupt Flag(PIF)
#define INTF0 6
#define INTF1 7
#define INTF2 5





#endif /* MCAL_EXTI_EXTI_REGISTER_H_ */
