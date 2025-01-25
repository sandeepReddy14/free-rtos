/*
 * user_app_main.c
 *
 *  Created on: Jan 25, 2025
 *      Author: sandeep
 */


#include "user_app_main.h"
#include "task1.h"
#include "task2.h"
#include "FreeRTOS.h"
#include "task.h"

void user_app_init(void)
{

	task1_init();

	task2_init();

    // Start the real time scheduler.
    vTaskStartScheduler();

}
