


#ifndef _CST830_TOUCH_H_
#define _CST830_TOUCH_H_

#ifdef __cplusplus
extern "C" {
#endif

/**********     INCLUDES        **********/
#include "lvgl_port_def.h"
#include <stdint.h>
#include <stdbool.h>

/**********     DEFINES      **********/

/**********     GLOBAL VARIABLE DECLRATIONS     **********/

/**********		GLOBAL VARIABLE DEFINITIONS		**********/

/**********		GLOBAL FUNCTION DECLRATIONS		**********/
/*
 * @brief Takes a pointer to a touch_info_t struct where it writes touch data to
 * every so often as specified by CST830_REFRESH_RATE.
 * */
void touch_scr_run(touch_info_t* p_touch_data);

/**
 * @brief Requests for the touch screen task to be deleted. will block the calling task for
 * block_time_ms until the task is deleted.
 *
 * @returns true if the task is deleted/not running. False if the task is still active.
 */
bool touch_scr_stop(uint32_t block_time_ms);

/**
 * @brief Adds a function callback that will be called when the screen is touched.
 */
void touch_scr_set_touched_cb(void (*func)());

/**
 * @brief Removes the function callback that is called when the screen is touched.
 */
void touch_scr_clear_touched_cb(void (*func)());




#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  //_CST830_TOUCH_H_


