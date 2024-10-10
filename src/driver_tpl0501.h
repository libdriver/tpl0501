/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_tpl0501.h
 * @brief     driver tpl0501 header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2024-10-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2024/10/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_TPL0501_H
#define DRIVER_TPL0501_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup tpl0501_driver tpl0501 driver function
 * @brief    tpl0501 driver modules
 * @{
 */

/**
 * @addtogroup tpl0501_base_driver
 * @{
 */

/**
 * @brief tpl0501 handle structure definition
 */
typedef struct tpl0501_handle_s
{
    uint8_t (*spi_init)(void);                                  /**< point to a spi_init function address */
    uint8_t (*spi_deinit)(void);                                /**< point to a spi_deinit function address */
    uint8_t (*spi_write_cmd)(uint8_t *buf, uint16_t len);       /**< point to a spi_write_cmd function address */
    void (*delay_ms)(uint32_t ms);                              /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);            /**< point to a debug_print function address */
    uint8_t inited;                                             /**< inited flag */
} tpl0501_handle_t;

/**
 * @brief tpl0501 information structure definition
 */
typedef struct tpl0501_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} tpl0501_info_t;

/**
 * @}
 */

/**
 * @defgroup tpl0501_link_driver tpl0501 link driver function
 * @brief    tpl0501 link driver modules
 * @ingroup  tpl0501_driver
 * @{
 */

/**
 * @brief     initialize tpl0501_handle_t structure
 * @param[in] HANDLE points to a tpl0501 handle structure
 * @param[in] STRUCTURE is tpl0501_handle_t
 * @note      none
 */
#define DRIVER_TPL0501_LINK_INIT(HANDLE, STRUCTURE)               memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link spi_init function
 * @param[in] HANDLE points to a tpl0501 handle structure
 * @param[in] FUC points to a spi_init function address
 * @note      none
 */
#define DRIVER_TPL0501_LINK_SPI_INIT(HANDLE, FUC)                (HANDLE)->spi_init = FUC

/**
 * @brief     link spi_deinit function
 * @param[in] HANDLE points to a tpl0501 handle structure
 * @param[in] FUC points to a spi_deinit function address
 * @note      none
 */
#define DRIVER_TPL0501_LINK_SPI_DEINIT(HANDLE, FUC)              (HANDLE)->spi_deinit = FUC

/**
 * @brief     link spi_write_cmd function
 * @param[in] HANDLE points to a tpl0501 handle structure
 * @param[in] FUC points to a spi_write_cmd function address
 * @note      none
 */
#define DRIVER_TPL0501_LINK_SPI_WRITE_COMMAND(HANDLE, FUC)       (HANDLE)->spi_write_cmd = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to a tpl0501 handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_TPL0501_LINK_DELAY_MS(HANDLE, FUC)                (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to a tpl0501 handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_TPL0501_LINK_DEBUG_PRINT(HANDLE, FUC)             (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup tpl0501_base_driver tpl0501 base driver function
 * @brief    tpl0501 base driver modules
 * @ingroup  tpl0501_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info points to a tpl0501 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t tpl0501_info(tpl0501_info_t *info);

/**
 * @brief     initialize the chip
 * @param[in] *handle points to a tpl0501 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 spi initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 * @note      none
 */
uint8_t tpl0501_init(tpl0501_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle points to a tpl0501 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t tpl0501_deinit(tpl0501_handle_t *handle);

/**
 * @brief     write data
 * @param[in] *handle points to a tpl0501 handle structure
 * @param[in] raw is the set data
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t tpl0501_write(tpl0501_handle_t *handle, uint8_t raw);

/**
 * @brief      convert the percentage to the register raw data
 * @param[in]  *handle points to a tpl0501 handle structure
 * @param[in]  percentage is the set percentage
 * @param[out] *reg points to a register raw buffer
 * @param[out] *wl_ohm points to a wl ohm buffer
 * @param[out] *hw_ohm points to a hw ohm buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t tpl0501_percentage_convert_to_register(tpl0501_handle_t *handle, 
                                               float percentage, uint8_t *reg,
                                               float *wl_ohm, float *hw_ohm);

/**
 * @brief      convert the register raw data to percentage
 * @param[in]  *handle points to a tpl0501 handle structure
 * @param[in]  reg is the register raw data
 * @param[out] *percentage points to a percentage buffer
 * @param[out] *wl_ohm points to a wl ohm buffer
 * @param[out] *hw_ohm points to a hw ohm buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t tpl0501_percentage_convert_to_data(tpl0501_handle_t *handle, 
                                           uint8_t reg, float *percentage, 
                                           float *wl_ohm, float *hw_ohm);

/**
 * @}
 */

/**
 * @defgroup tpl0501_extern_driver tpl0501 extern driver function
 * @brief    tpl0501 extern driver modules
 * @ingroup  tpl0501_driver
 * @{
 */

/**
 * @brief     set the chip register
 * @param[in] *handle points to a tpl0501 handle structure
 * @param[in] raw is the set data
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t tpl0501_set_reg(tpl0501_handle_t *handle, uint8_t raw);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
