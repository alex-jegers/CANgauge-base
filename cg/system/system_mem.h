/**
 * @file: basic control of the memory containers on CANgauge.
 */
#ifndef _SYSTEM_MEM_H_
#define _SYSTEM_MEM_H_

#ifdef __cplusplus
extern "C" {
#endif

/**********     INCLUDES        **********/
#include "stm32h745xx.h"
#include "stdbool.h"
#include "file_system/fatfs/ff.h"
#include "file_system/fatfs/diskio.h"

/**********     DEFINES      **********/
#define SYS_MEM_REGION_EXTERN_RAM			__attribute__((__section__(".ext_mem_ram")))
#define SYS_MEM_REGION_RAM_D1				__attribute__((__section__(".ram_d1")))
#define SYS_MEM_REGION_RAM_EXE				__attribute__((__section__(".itcm"), long_call))

#define SYSTEM_MEM_CONFIG_LENGTH_BYTES			0x100

#define SECTOR_SIZE_RAM			512
#define BLOCK_SIZE_RAM			1
#define NUM_SECTORS_RAM			0x2000

#define SECTOR_SIZE_EEPROM		512
#define BLOCK_SIZE_EEPROM		1
#define NUM_SECTORS_EEPROM		0x1FFFF / SECTOR_SIZE_EEPROM

#define FILE_MNGR_CONFIG_FILE_PATH		"0:/System Data.txt"        //TODO: move to application code.

/**********     GLOBAL VARIABLE DECLRATIONS     **********/

/**********		GLOBAL FUNCTION DECLRATIONS		**********/
/**
 * sys_mem_create_eeprom_fs
 * 		desc: initializes a blank filesystem in EEPROM.
 * 		returns: FR_OK on success, something else on failure.
 */
FRESULT sys_mem_create_eeprom_fs();

/**
 * sys_mem_create_ram_fs
 * 		desc: initializes a blank filesystem in external RAM.
 * 		returns: true on success, false on failure.
 */
FRESULT sys_mem_create_ram_fs();

/**
 * sys_mem_get_eeprom_fs
 * 		desc: tries to mount the EEPROM file system. Can be used to check validity of the
 * 			file system.
 * 		returns: FR_OK if the file system exists and init succeeded.
 */
FRESULT sys_mem_init_eeprom_fs();

/**
 * sys_mem_get_ram_fs
 * 		desc: tries to mount the RAM file system. Can be used to check validity of the
 * 			file system.
 * 		returns: FR_OK if the file system exists and init succeeded.
 */
FRESULT sys_mem_init_ram_fs();

/**
 * sys_mem_get_ram_fs_ptr:
 * 		desc: returns a pointer of the physical address to the start of the file
 * 			system in RAM. This is used to calculate other physical addresses
 * 			when only the block address is supplied during USB communication
 * 			and what not.
 */
uint8_t* sys_mem_get_ram_fs_ptr();

/**
 * sys_mem_flash_write_sector
 * 		desc: write to an area in flash.
 * 		params:
 * 			p: the sector number.
 * 			src: pointer to the data to write into the sector, must be 0x20000 bytes.
 */
void sys_mem_flash_write_sector(uint8_t sector, void* src);






#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  //_SYSTEM_MEM_H_
