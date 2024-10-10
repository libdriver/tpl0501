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
 * @file      driver_tpl0501_basic.c
 * @brief     driver tpl0501 basic source file
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

#include "driver_tpl0501_basic.h"

static tpl0501_handle_t gs_handle;        /**< tpl0501 handle */

/**
 * @brief  basic example init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t tpl0501_basic_init(void)
{
    uint8_t res;

    /* link functions */
    DRIVER_TPL0501_LINK_INIT(&gs_handle, tpl0501_handle_t);
    DRIVER_TPL0501_LINK_SPI_INIT(&gs_handle, tpl0501_interface_spi_init);
    DRIVER_TPL0501_LINK_SPI_DEINIT(&gs_handle, tpl0501_interface_spi_deinit);
    DRIVER_TPL0501_LINK_SPI_WRITE_COMMAND(&gs_handle, tpl0501_interface_spi_write_cmd);
    DRIVER_TPL0501_LINK_DELAY_MS(&gs_handle, tpl0501_interface_delay_ms);
    DRIVER_TPL0501_LINK_DEBUG_PRINT(&gs_handle, tpl0501_interface_debug_print);
    
    /* tpl0501 init */
    res = tpl0501_init(&gs_handle);
    if (res != 0)
    {
        tpl0501_interface_debug_print("tpl0501: init failed.\n");
        
        return 1;
    }
    
    return 0;
}

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t tpl0501_basic_deinit(void)
{
    /* close tpl0501 */
    if (tpl0501_deinit(&gs_handle) != 0)
    {
        return 1;
    }
    
    return 0;
}

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
uint8_t tpl0501_basic_write(float percentage, float *wl_ohm, float *hw_ohm)
{
    uint8_t res;
    uint8_t raw;
    
    /* percentage convert to register */
    res = tpl0501_percentage_convert_to_register(&gs_handle, percentage, &raw, wl_ohm, hw_ohm);
    if (res != 0)
    {
        return 1;
    }
    
    /* write data */
    res = tpl0501_write(&gs_handle, raw);
    if (res != 0)
    {
        return 1;
    }
    
    return 0;
}
