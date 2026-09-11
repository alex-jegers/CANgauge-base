/**********     INCLUDES        **********/
#include "file_system/filesys_helpers.h"
#include "file_system/fatfs/ff.h"
#include "file_system/fatfs/diskio.h"
#include <string.h>
#include <stdlib.h>

/**********     TYPEDEFS         **********/

/**********		DEFINES		**********/

/**********		EXTERNAL VARIABLE DEFINITIONS		**********/

/**********		STATIC VARIABLES		**********/

/**********		STATIC FUNCTION DECLRATIONS		**********/

/**********		STATIC FUNCTION DEFINITIONS		**********/


/**********		GLOBAL FUNCTION DEFINITIONS		**********/
uint32_t filesys_get_total_free_space_bytes(const char* drive)
{
	DWORD free_clusters = 0;
	FATFS* fs_ptr;
	f_getfree((const TCHAR*)drive, &free_clusters, &fs_ptr);

	uint32_t free_sectors = free_clusters * fs_ptr->csize;
	uint32_t bytes_per_sector = 0;
	disk_ioctl(fs_ptr->pdrv, GET_SECTOR_SIZE, &bytes_per_sector);

	return free_sectors * bytes_per_sector;
}

uint32_t filesys_get_contiguous_free_space_bytes(const char* drive)
{
	/* Get the sector size and total available space. */
	/* This is basically copy and pasted from filesys_get_total_free_space_bytes
	 * but were calling it again so we can store the sector size in this function
	 * cause we need it later.
	 */
	DWORD free_clusters = 0;
	FATFS* fs_ptr;
	f_getfree((const TCHAR*)drive, &free_clusters, &fs_ptr);
	uint32_t free_sectors = free_clusters * fs_ptr->csize;
	uint32_t bytes_per_sector = 0;
	disk_ioctl(fs_ptr->pdrv, GET_SECTOR_SIZE, &bytes_per_sector);
	uint32_t space = free_sectors * bytes_per_sector;

	FIL file;
	FRESULT res;
	f_chdrive(drive);		//Change the current drive.

	/* Open a temp file and attempt to expand less and less it until we can. */
	res = f_open(&file, "temp.txt", FA_CREATE_NEW | FA_WRITE);
	if (res != FR_OK)
	{
		return 0;
	}
	for (;space > bytes_per_sector; space -= 512)
	{
		res = f_expand(&file, space, 0);
		if (res == FR_OK)
		{
			break;
		}
	}

	/* Close and delete the temp file. */
	f_close(&file);
	f_unlink("temp.txt");
	f_chdrive("0:/");		//Change the drive back to zero.

	return space - bytes_per_sector;		//Always leave 1 sector open.
}
