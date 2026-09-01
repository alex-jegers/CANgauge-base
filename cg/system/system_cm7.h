/*
 * system.h
 *
 *  Created on: May 31, 2024
 *      Author: awjpp
 */



#ifndef CORE_SYSTEM_CM7_SYSTEM_H_
#define CORE_SYSTEM_CM7_SYSTEM_H_


/**********		INCLUDES		**********/
#include "stm32h745xx.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "timers.h"

#include "system_mem.h"

#include "version.h"

/**********		DEFINES		**********/
#define SYS_ENABLE_CACHE		1


/**********     GLOBAL VARIABLE DECLRATIONS     **********/

/**********		GLOBAL FUNCTION DECLRATIONS		**********/
void system_task_init();
void system_init();
void system_init_fpu();
void system_blink_run(const uint32_t delay_time_ms);
void system_blink_set_delay(uint32_t on_ms, uint32_t off_ms);

/**
 * system_blink_stop:
 * desc:
 *      turns the light off, suspends the blink task.
 * returns:
 *      true
 */
bool system_blink_stop();
/**
 * system_set_lcd_backlight:
 * params: 
 *      on: true for on, false for off.
 */
void system_set_lcd_backlight(bool on);
/**
 * system_set_can_transc:
 * desc: enable/disable CAN transceivers.
 * params: 
 *      on: true for on, false for off.
 */
void system_set_can_transc(bool on);
void system_set_ui_init_cb(void (*func)());

#endif /* CORE_SYSTEM_CM7_SYSTEM_H_ */


