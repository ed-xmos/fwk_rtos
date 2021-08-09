// Copyright (c) 2021 XMOS LIMITED. This Software is subject to the terms of the
// XMOS Public License: Version 1

#ifndef DRIVER_INSTANCES_H_
#define DRIVER_INSTANCES_H_

#include "rtos/drivers/intertile/api/rtos_intertile.h"
#include "rtos/drivers/qspi_flash/api/rtos_qspi_flash.h"

#if USE_SWMEM
#if ON_TILE(1)
#include "rtos/drivers/swmem/api/rtos_swmem.h"
#include "xcore_device_memory.h"
#endif
#endif

#define FLASH_TILE_NO      0

extern rtos_intertile_t *intertile_ctx;
extern rtos_qspi_flash_t *qspi_flash_ctx;

#endif /* DRIVER_INSTANCES_H_ */
