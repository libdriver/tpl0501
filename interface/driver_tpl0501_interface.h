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
 * @file      driver_tpl0501_interface.h
 * @brief     driver tpl0501 interface header file
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

#ifndef DRIVER_TPL0501_INTERFACE_H
#define DRIVER_TPL0501_INTERFACE_H

#include "driver_tpl0501.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup tpl0501_interface_driver tpl0501 interface driver function
 * @brief    tpl0501 interface driver modules
 * @ingroup  tpl0501_driver
 * @{
 */

/**
 * @brief  interface spi bus init
 * @return status code
 *         - 0 success
 *         - 1 spi init failed
 * @note   none
 */
uint8_t tpl0501_interface_spi_init(void);

/**
 * @brief  interface spi bus deinit
 * @return status code
 *         - 0 success
 *         - 1 spi deinit failed
 * @note   none
 */
uint8_t tpl0501_interface_spi_deinit(void);

/**
 * @brief     interface spi bus write command
 * @param[in] *buf pointer to a data buffer
 * @param[in] len length of data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t tpl0501_interface_spi_write_cmd(uint8_t *buf, uint16_t len);

/**
 * @brief     interface delay ms
 * @param[in] ms time
 * @note      none
 */
void tpl0501_interface_delay_ms(uint32_t ms);

/**
 * @brief     interface print format data
 * @param[in] fmt format data
 * @note      none
 */
void tpl0501_interface_debug_print(const char *const fmt, ...);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
