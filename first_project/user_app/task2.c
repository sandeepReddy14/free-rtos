/*
 * task2.c
 *
 *  Created on: Jan 25, 2025
 *      Author: sandeep
 */


#include "task2.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"


TaskHandle_t task2_handle;

void task2_handler( void * parameters )
{
	configASSERT(((uint32_t)parameters) == 1);

	for(;;)
	{
		printf("Hello from task2\n");
		vTaskDelay( (TickType_t)(1000 / portTICK_PERIOD_MS) );

	}
}

void task2_init(void)
{

	BaseType_t xReturned;

	xReturned = xTaskCreate(
							task2_handler,
							"task2",
							TASK2_STACK_SIZE / (sizeof(BaseType_t)),
							(void * ) 1,
							TASK2_PRIORITY,
							&task2_handle );

	if(xReturned != pdPASS)
	{
		configASSERT(0);
	}

}
