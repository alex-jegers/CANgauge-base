
#ifndef _ERROR_HANDLER_H_
#define _ERROR_HANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

/**********     INCLUDES        **********/
#include "cangauge.h"
/**********     TYPEDEFS         **********/

/**********     DEFINES      **********/

/**********     GLOBAL VARIABLE DECLRATIONS     **********/

/**********		GLOBAL FUNCTION DECLRATIONS		**********/
/**
 * @brief Creates a message box on lv_layer_top with one button to close the box and
 * the text passed in msg. Use this when displaying a message box from somewhere NOT
 * inside the LVGL timer handler, this function will take the LVGL mutex. When calling
 * from inside the LVGL timer handler use error_show_msgbox_from_lvgl_task.
 *
 * @param msg The text to display in the message box. The text will be copied by the LVGL
 * function so it doesnt need to outlive the message box.
 */
void error_show_msgbox(const char* msg);

/**
 * @brief Creates a message box on lv_layer_top with one button to close the box and
 * the text passed in msg. Use this when displaying a message box from somewhere
 * inside the LVGL timer handler, this function will NOT take the LVGL mutex.
 *
 * @param msg The text to display in the message box. The text will be copied by the LVGL
 * function so it doesnt need to outlive the message box.
 */
void error_show_msgbox_from_lvgl_task(const char* msg);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  //_ERROR_HANDLER_H_
