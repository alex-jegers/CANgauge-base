
#ifndef _CANGAUGE_H_
#define _CANGAUGE_H_

#ifdef __cplusplus
extern "C" {
#endif

/**********     INCLUDES        **********/
/**
 * This brings FreeRTOS, standard C libs, and system_mem.
 */
#include "system/system_cm7.h"

#include "ui_helpers/ui_helpers.h"

/**
 * This brings the touch screen and display related stuff.
 * Need to look into cleaning up the internal includes here,
 * lots of circular/unecessary includes.
 */
#include "lvgl_port/lvgl_port_def.h"

/**
 * FatFS file system functions and types.
 */
#include "file_system/fatfs/ff.h"
#include "file_system/filesys_helpers.h"

/**
 * Hardware level drivers.
 */
#include "drivers/drivers.h"

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



#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  //_CANGAUGE_H_
