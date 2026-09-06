
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
 * name:
 *      desc:
 *      params:
 *      returns:
 */
void error_show_msgbox(char* msg);
void error_show_msgbox_from_lvgl_task(char* msg);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  //_ERROR_HANDLER_H_
