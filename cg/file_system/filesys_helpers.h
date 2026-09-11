/**
 * @file filesys_helpers.h
 * @author Alex Jegers
 * @brief Contains utility functions that help or enhance the use of the rest of the FatFS API.
 *          Depends on the FatFS API as well as standard library files string.h, stdlib.h, and
 *          stdint.h.
 */
#ifndef _FILESYS_HELPERS_H_
#define _FILESYS_HELPERS_H_

#ifdef __cplusplus
extern "C" {
#endif

/**********     INCLUDES        **********/
#include <stdint.h>
/**********     TYPEDEFS         **********/

/**********     DEFINES      **********/

/**********     GLOBAL VARIABLE DECLRATIONS     **********/

/**********		GLOBAL FUNCTION DECLRATIONS		**********/
/**
 * @brief Gets the total amount of space available in a file system.
 *          This is not necessarily the amount of usable space as it
 *          may not be continuous. Use filesys_get_contiguous_free_space_bytes
 *          for the largest amount of continuous space.
 * @param drive The volume of which to check for the available space of (i.e. "0:/" or "1:/" or "0:").
 * @returns The total available space in bytes on the drive. Will return 0 on
 *          file system error as well.
 */
uint32_t filesys_get_total_free_space_bytes(const char* drive);
uint32_t filesys_get_contiguous_free_space_bytes(const char* drive);



#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  //_TEMPLATE_H_
