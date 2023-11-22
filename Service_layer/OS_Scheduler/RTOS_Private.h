/*
 * RTOS_Private.h
 *
 *  Created on: Nov 18, 2023
 *      Author: Lenovo
 */

#ifndef SERVICE_LAYER_OS_SCHEDULER_RTOS_PRIVATE_H_
#define SERVICE_LAYER_OS_SCHEDULER_RTOS_PRIVATE_H_
//enum for task states
typedef enum
{
	Suspended,
	Running
}RunState;

//struct that define each parameter of task
typedef struct {
	uint8_t periodicity;
	void (*TaskHandler)(void);
	uint8_t FirstDelay;
	RunState TaskRunState;
}Task;


#endif /* SERVICE_LAYER_OS_SCHEDULER_RTOS_PRIVATE_H_ */
