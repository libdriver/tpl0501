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
 * @file      driver_tpl0501_basic.h
 * @brief     driver tpl0501 basic include file
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

#ifndef DRIVER_TPL0501_BASIC_H
#define DRIVER_TPL0501_BASIC_H

#include "driver_tpl0501_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup tpl0501_example_driver tpl0501 example driver function
 * @brief    tpl0501 example driver modules
 * @ingroup  tpl0501_driver
 * @{
 */

/**
 * @brief  basic example init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t tpl0501_basic_init(void);

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t tpl0501_basic_deinit(void);

/**
 * @brief      basic example write
 * @param[in]  percentage is the set percentage
 * @param[out] *wl_ohm points to a wl ohm buffer
 * @param[out] *hw_ohm points to a hw ohm buffer
 * @return     status code
 *             - 0 success
 *             - 1 write failed
 * @note       none
 */
uint8_t tpl0501_basic_write(float percentage, float *wl_ohm, float *hw_ohm);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
