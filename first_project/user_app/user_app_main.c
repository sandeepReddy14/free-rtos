/*
 * user_app_main.c
 *
 *  Created on: Jan 25, 2025
 *      Author: sandeep
 */

#include "FreeRTOS.h"
#include "task.h"

#include "user_app_main.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"

void user_app_init(void)
{

	task1_init();

	task2_init();

	task3_init();

    // Start the real time scheduler.
    vTaskStartScheduler();

}
