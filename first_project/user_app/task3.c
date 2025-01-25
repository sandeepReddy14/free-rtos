/*
 * task3.c
 *
 *  Created on: Jan 25, 2025
 *      Author: sandeep
 */


#include "task3.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"


StackType_t task3_stack[TASK3_STACK_SIZE];
StaticTask_t task3_tcb_buffer;
TaskHandle_t task3_handle;

void task3_handler( void * parameters)
{
	configASSERT(((uint32_t) parameters) == 1);

	uint8_t task3_log_count = 0;

	for(;;)
	{
		printf("Hello from task3\n");
		task3_log_count += 1;
		vTaskDelay( (TickType_t)(1000 / portTICK_PERIOD_MS) );

		if(task3_log_count == 10)
			break;
	}

	/* Delete task3 */
	vTaskDelete(task3_handle);

}
void task3_init(void)
{
	task3_handle = NULL;
	task3_handle = xTaskCreateStatic(
									task3_handler,
									"task3",
									TASK3_STACK_SIZE,
									( void *) 1,
									TASK3_PRIORITY,
									task3_stack,
									&task3_tcb_buffer);

	if(task3_handle == NULL)
	{
		configASSERT(!(task3_handle == NULL));
	}

}
