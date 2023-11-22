/*
 * main.c
 *
 *  Created on: Nov 22, 2023
 *      Author: Lenovo
 */


#include"Std_Types.h"
#include"Bit_Math.h"
#include"MCAL/Dio/Dio.h"
#include"MCAL/GI/GI_interface.h"
#include"Service_layer/OS_Scheduler/RTOS_Interface.h"


void toggle_led1(void);
void toggle_led2(void);
void toggle_led3(void);


int main()
{

	Dio_SetChannel_Dir(PA_0, OUTPUT);
	Dio_SetChannel_Dir(PA_1, OUTPUT);
	Dio_SetChannel_Dir(PA_2, OUTPUT);

	enable_global_int();
	RTOS_CreateTask(toggle_led1, 100, 0,100);//(TaskHandler, Periodicity, periority,FirstDelay)
	RTOS_CreateTask(toggle_led2, 50,  0,50);
	RTOS_CreateTask(toggle_led3, 300, 1,150);
	RTOS_voidStartOS();
	while(1)
	{

	}

	return 0;
}



void toggle_led1(void)
{
	Dio_FlipChannel(PA_0);
}
void toggle_led2(void)
{
	Dio_FlipChannel(PA_1);
}
void toggle_led3(void)
{
	Dio_FlipChannel(PA_2);
}
