// Copyright (c) 2022 XMOS LIMITED. This Software is subject to the terms of the
// XMOS Public License: Version 1

#ifndef PLATFORM_CONF_H_
#define PLATFORM_CONF_H_

/*
 * This file contains defaults to build a basic project targetting the
 * XCORE-AI-EXPLORER board.  Users may create their own app_conf.h to override
 * any default settings.
 *
 * For a different soft tapeout design, it is recommended to create an entirely
 * different board support package.
 */

#if __has_include("app_conf.h")
#include "app_conf.h"
#endif /* __has_include("app_conf.h") */

/*****************************************/
/* Intertile Communication Configuration */
/*****************************************/
#ifndef appconfI2C_MASTER_RPC_PORT
#define appconfI2C_MASTER_RPC_PORT 10
#endif /* appconfI2C_MASTER_RPC_PORT */

#ifndef appconfI2C_MASTER_RPC_PRIORITY
#define appconfI2C_MASTER_RPC_PRIORITY (configMAX_PRIORITIES/2)
#endif /* appconfI2C_MASTER_RPC_PRIORITY */

#ifndef appconfGPIO_T0_RPC_PORT
#define appconfGPIO_T0_RPC_PORT 11
#endif /* appconfGPIO_T0_RPC_PORT */

#ifndef appconfGPIO_T1_RPC_PORT
#define appconfGPIO_T1_RPC_PORT 12
#endif /* appconfGPIO_T1_RPC_PORT */

#ifndef appconfGPIO_RPC_PRIORITY
#define appconfGPIO_RPC_PRIORITY (configMAX_PRIORITIES/2)
#endif /* appconfGPIO_RPC_PRIORITY */

#ifndef appconfMIC_ARRAY_RPC_PORT
#define appconfMIC_ARRAY_RPC_PORT 13
#endif /* appconfMIC_ARRAY_RPC_PORT */

#ifndef appconfMIC_ARRAY_RPC_PRIORITY
#define appconfMIC_ARRAY_RPC_PRIORITY ((configMAX_PRIORITIES/2) + 1)
#endif /* appconfMIC_ARRAY_RPC_PRIORITY */

/*****************************************/
/*  I/O and interrupt cores for Tile 0   */
/*****************************************/
#ifndef appconfI2C_IO_CORE
#define appconfI2C_IO_CORE                      3 /* Must be kept off core 0 with the RTOS tick ISR */
#endif /* appconfI2C_IO_CORE */

#ifndef appconfI2C_INTERRUPT_CORE
#define appconfI2C_INTERRUPT_CORE               0 /* Must be kept off I/O cores. */
#endif /* appconfI2C_INTERRUPT_CORE */

/*****************************************/
/*  I/O and interrupt cores for Tile 1   */
/*****************************************/
#ifndef appconfPDM_MIC_IO_CORE
#define appconfPDM_MIC_IO_CORE                  1 /* Must be kept off I/O cores. Must be kept off core 0 with the RTOS tick ISR */
#endif /* appconfPDM_MIC_IO_CORE */

#ifndef appconfI2S_IO_CORE
#define appconfI2S_IO_CORE                      2 /* Must be kept off core 0 with the RTOS tick ISR */
#endif /* appconfI2S_IO_CORE */

#ifndef appconfPDM_MIC_INTERRUPT_CORE
#define appconfPDM_MIC_INTERRUPT_CORE           3 /* Must be kept off I/O cores. Best kept off core 0 with the tick ISR. */
#endif /* appconfPDM_MIC_INTERRUPT_CORE */

#ifndef appconfI2S_INTERRUPT_CORE
#define appconfI2S_INTERRUPT_CORE               4 /* Must be kept off I/O cores. Best kept off core 0 with the tick ISR. */
#endif /* appconfI2S_INTERRUPT_CORE */

/*****************************************/
/*  I/O and interrupt cores for Tile 1   */
/*****************************************/
#ifndef appconfPDM_CLOCK_FREQUENCY
#define appconfPDM_CLOCK_FREQUENCY      MIC_ARRAY_CONFIG_MCLK_FREQ
#endif /* appconfPDM_CLOCK_FREQUENCY */

#ifndef appconfAUDIO_CLOCK_FREQUENCY
#define appconfAUDIO_CLOCK_FREQUENCY    MIC_ARRAY_CONFIG_PDM_FREQ
#endif /* appconfAUDIO_CLOCK_FREQUENCY */

#ifndef appconfPIPELINE_AUDIO_SAMPLE_RATE
#define appconfPIPELINE_AUDIO_SAMPLE_RATE       16000
#endif /* appconfPIPELINE_AUDIO_SAMPLE_RATE */

#ifndef appconfAUDIO_FRAME_LENGTH
#define appconfAUDIO_FRAME_LENGTH        MIC_ARRAY_CONFIG_SAMPLES_PER_FRAME
#endif /* appconfAUDIO_FRAME_LENGTH */

/*****************************************/
/*  I/O Task Priorities                  */
/*****************************************/
#ifndef appconfSPI_MASTER_TASK_PRIORITY
#define appconfSPI_MASTER_TASK_PRIORITY		    ( configMAX_PRIORITIES - 1 )
#endif /* appconfSPI_MASTER_TASK_PRIORITY */

#ifndef appconfQSPI_FLASH_TASK_PRIORITY
#define appconfQSPI_FLASH_TASK_PRIORITY		    ( configMAX_PRIORITIES - 1 )
#endif /* appconfQSPI_FLASH_TASK_PRIORITY */

#endif /* PLATFORM_CONF_H_ */
