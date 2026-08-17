/**********     INCLUDES        **********/
#include <file_system/filesys_helpers.h>
/**********     TYPEDEFS         **********/

/**********		DEFINES		**********/

/**********		EXTERNAL VARIABLE DEFINITIONS		**********/

/**********		STATIC VARIABLES		**********/

/**********		STATIC FUNCTION DECLRATIONS		**********/

/**********		STATIC FUNCTION DEFINITIONS		**********/

/**********		GLOBAL FUNCTION DEFINITIONS		**********/
uint32_t filesys_get_free_space(const char* drive)
{
	DWORD free_clusters = 0;
	FATFS* fs_ptr;
	f_getfree((const TCHAR*)drive, &free_clusters, &fs_ptr);

	uint32_t free_sectors = free_clusters * fs_ptr->csize;
	uint32_t bytes_per_sector = 0;
	disk_ioctl(fs_ptr->pdrv, GET_SECTOR_SIZE, &bytes_per_sector);

	return free_sectors * bytes_per_sector;
}
