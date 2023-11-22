/*
 * Port_Cfg.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_PORT_PORT_CFG_H_
#define MCAL_PORT_PORT_CFG_H_
#include"../Dio/Dio.h"
#define MAX_ACTIVATED_PINS 33
typedef struct PinCfg{
	Dio_PortType port;
	Dio_PinType pin;
	Dio_DirctionType dir;
}PinCfg;


#endif /* MCAL_PORT_PORT_CFG_H_ */
