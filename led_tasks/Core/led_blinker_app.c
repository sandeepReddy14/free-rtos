/*
 * led_blinker_app.c
 *
 *  Created on: Feb 17, 2025
 *      Author: sandeep
 */

#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"
#include "main.h"

#define LED_GREEN_PIN LD4_Pin
#define LED_ORANGE_PIN LD3_Pin
#define LED_RED_PIN LD5_Pin
TaskHandle_t led_green_task_handle;
TaskHandle_t led_orange_task_handle;
TaskHandle_t led_red_task_handle;

void led_green_handler( void * parameters )
{
	configASSERT(((uint32_t)parameters) == 1);

	for(;;)
	{
		printf("Hello from green task\n");
		HAL_GPIO_TogglePin(GPIOD, LED_GREEN_PIN);
		vTaskDelay( (TickType_t)(1000 / portTICK_PERIOD_MS) );
	}
}

void led_orange_handler( void * parameters )
{
	configASSERT(((uint32_t)parameters) == 1);

	for(;;)
	{
		printf("Hello from orange task\n");
		HAL_GPIO_TogglePin(GPIOD, LED_ORANGE_PIN);
		vTaskDelay( (TickType_t)(800 / portTICK_PERIOD_MS) );
	}
}

void led_red_handler( void * parameters )
{
	configASSERT(((uint32_t)parameters) == 1);

	for(;;)
	{
		printf("Hello from red task\n");
		HAL_GPIO_TogglePin(GPIOD, LED_RED_PIN);
		vTaskDelay( (TickType_t)(400 / portTICK_PERIOD_MS) );
	}
}

void led_blinker_app_init(void)
{

	/* Create Task for green LED */
	BaseType_t xReturned;

	xReturned = xTaskCreate(
							led_green_handler,
							"led_green_task",
							configMINIMAL_STACK_SIZE,
							(void * ) 1,
							tskIDLE_PRIORITY,
							&led_green_task_handle );

	if(xReturned != pdPASS)
	{
		configASSERT(0);
	}

	/* Create Task for orange LED */

	xReturned = xTaskCreate(
							led_orange_handler,
							"led_orange_task",
							configMINIMAL_STACK_SIZE,
							(void * ) 1,
							tskIDLE_PRIORITY,
							&led_orange_task_handle );

	if(xReturned != pdPASS)
	{
		configASSERT(0);
	}

	/* Create Task for red LED */

	xReturned = xTaskCreate(
							led_red_handler,
							"led_red_task",
							configMINIMAL_STACK_SIZE,
							(void * ) 1,
							tskIDLE_PRIORITY,
							&led_red_task_handle );

	if(xReturned != pdPASS)
	{
		configASSERT(0);
	}


	/* Start the scheduler */
	vTaskStartScheduler();

}
