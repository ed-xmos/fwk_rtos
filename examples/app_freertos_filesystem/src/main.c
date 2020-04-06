// Copyright (c) 2019, XMOS Ltd, All rights reserved

#include <string.h>
#include <sys/time.h>

#define clock libc_clock
#include <time.h>
#undef clock

/* FreeRTOS headers */
#include "FreeRTOS.h"
#include "task.h"

#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"

#include "ff_headers.h"
#include "ff_stdio.h"

/* Library headers */
#include "soc.h"

/* BSP/bitstream headers */
#include "bitstream_devices.h"
#include "spi_master_driver.h"
#include "gpio_driver.h"
#include "sl_wfx.h"

/* App headers */
#include "sl_wfx_iot_wifi.h"
#include "network.h"
#include "dhcpd.h"

/* FreeRTOS+FAT includes. */
#include "ff_headers.h"
#include "ff_stdio.h"
#include "ff_flashdisk.h"


#define mainFLASH_DISK_SECTOR_SIZE    512UL /* Currently fixed! */
#define mainFLASH_DISK_SECTORS        ( ( 10UL * 1024UL * 1024UL ) / mainFLASH_DISK_SECTOR_SIZE ) /* 10M bytes. */
#define mainIO_MANAGER_CACHE_SIZE   ( 2UL * mainFLASH_DISK_SECTOR_SIZE )
#define mainFLASH_DISK_NAME           "/flash"

static void prvCreateDiskAndExampleFiles( void )
{
FF_Disk_t *pxDisk;

    /* Create the RAM disk. */
    pxDisk = FF_FlashDiskInit( mainFLASH_DISK_NAME, mainFLASH_DISK_SECTORS, mainIO_MANAGER_CACHE_SIZE );
    configASSERT( pxDisk );

    /* Print out information on the disk. */
    FF_FlashDiskShowPartition( pxDisk );

    /* Create a few example files on the disk.  These are not deleted again. */
//    vCreateAndVerifyExampleFiles( mainFLASH_DISK_NAME );

//        vStdioWithCWDTest( mainRAM_DISK_NAME );
}

void soc_tile0_main(
        int tile)
{
    rtos_printf("Hello from tile %d\n", tile);

    xTaskCreate((TaskFunction_t)prvCreateDiskAndExampleFiles, "fs_test", 2000/*portTASK_STACK_DEPTH(prvCreateDiskAndExampleFiles)*/, NULL, 15, NULL);

    vTaskStartScheduler();
}


void vApplicationMallocFailedHook(void)
{
    debug_printf("Malloc failed!\n");
    //configASSERT(0);
}
