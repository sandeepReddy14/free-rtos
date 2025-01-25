/*
 * task1.c
 *
 *  Created on: Jan 25, 2025
 *      Author: sandeep
 */


#include "task1.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"


TaskHandle_t task1_handle;

void task1_handler( void * parameters )
{
	configASSERT(((uint32_t)parameters) == 1);

	for(;;)
	{
		printf("Hello from task1\n");
		vTaskDelay( (TickType_t)(1000 / portTICK_PERIOD_MS) );
	}
}

void task1_init(void)
{

	BaseType_t xReturned;

	xReturned = xTaskCreate(
							task1_handler,
							"task1",
							TASK1_STACK_SIZE / (sizeof(BaseType_t)),
							(void * ) 1,
							TASK1_PRIORITY,
							&task1_handle );

	if(xReturned != pdPASS)
	{
		configASSERT(0);
	}

}
