
#ifndef _FILESYS_HELPERS_H_
#define _FILESYS_HELPERS_H_

#ifdef __cplusplus
extern "C" {
#endif

/**********     INCLUDES        **********/
#include "file_system/fatfs/ff.h"
#include "file_system/fatfs/diskio.h"
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
uint32_t filesys_get_free_space(const char* drive);



#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  //_TEMPLATE_H_
