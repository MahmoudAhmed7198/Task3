/*
 * RTOS_program.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Lenovo
 */

#include"../../Std_Types.h"
#include"../../Bit_Math.h"
#include"../../MCAL/Timer_0/Timer0_interface.h"
#include"RTOS_Interface.h"
#include"RTOS_Cfg.h"
#include"RTOS_Private.h"



Task SystemTasks[MAX_NUM_OF_TASKS];
uint8_t TaskTiming [MAX_NUM_OF_TASKS];
//Task Empty = 0;

void RTOS_CreateTask(void (*PTF)(void),u16 periodicity,uint8_t priority,uint8_t FirstDelay)
{
	//verify that the priority within the range
	if(priority<MAX_NUM_OF_TASKS)
	{
		if(SystemTasks[priority].TaskHandler==0)
		{
			SystemTasks[priority].TaskHandler=PTF;
			SystemTasks[priority].periodicity=periodicity;
			TaskTiming [priority]=FirstDelay;
			SystemTasks[priority].TaskRunState=Running;
		}
	}
}
void scheduler(void)
{
	uint8_t Local_Counter=0;
	for (Local_Counter =0; Local_Counter < MAX_NUM_OF_TASKS; Local_Counter++)
		{
			/* Is there a registered task ... ? */
			if (SystemTasks[Local_Counter].TaskHandler != 0)
			{
				//if this is your time(task time) to run
					if (TaskTiming[Local_Counter] == 0)
					{
						/* Run the task */
						SystemTasks[Local_Counter].TaskHandler();
						/* Reload the periodicity */
						TaskTiming[Local_Counter]=SystemTasks[Local_Counter].periodicity;
					}

					else
					{
						TaskTiming[Local_Counter]--;
					}
			}
		}
}
/*void RTOS_DeleteTask(uint8_t priority)

{
	if(SystemTasks[priority].PTF!=0)
	{
		SystemTasks[priority]=Empty;
	}
}*/
void RTOS_voidStartOS(void)
{
	Timer0_init();
	Timer0_setCallBack(scheduler);
	Timer0_start();
}
void RTOS_SuspendTask(uint8_t priority)
{
	if(SystemTasks[priority].TaskHandler!=0)
	{
		SystemTasks[priority].TaskRunState=Suspended;
	}
}
void RTOS_ResumeTask(uint8_t priority)
{
	if(SystemTasks[priority].TaskHandler!=0)
	{
		SystemTasks[priority].TaskRunState=Running;
	}
}

