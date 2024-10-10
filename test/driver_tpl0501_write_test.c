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
 * @file      driver_tpl0501_write_test.c
 * @brief     driver tpl0501 write test source file
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
 
#include "driver_tpl0501_write_test.h"
#include <stdlib.h>

static tpl0501_handle_t gs_handle;        /**< tpl0501 handle */

/**
 * @brief     write test
 * @param[in] times is the test times
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t tpl0501_write_test(uint32_t times)
{
    uint8_t res;
    uint32_t i;
    float percentage;
    float wl_ohm;
    float hw_ohm;
    float percentage_check;
    float wl_ohm_check;
    float hw_ohm_check;
    tpl0501_info_t info;
    
    /* link functions */
    DRIVER_TPL0501_LINK_INIT(&gs_handle, tpl0501_handle_t);
    DRIVER_TPL0501_LINK_SPI_INIT(&gs_handle, tpl0501_interface_spi_init);
    DRIVER_TPL0501_LINK_SPI_DEINIT(&gs_handle, tpl0501_interface_spi_deinit);
    DRIVER_TPL0501_LINK_SPI_WRITE_COMMAND(&gs_handle, tpl0501_interface_spi_write_cmd);
    DRIVER_TPL0501_LINK_DELAY_MS(&gs_handle, tpl0501_interface_delay_ms);
    DRIVER_TPL0501_LINK_DEBUG_PRINT(&gs_handle, tpl0501_interface_debug_print);
    
    /* tpl0501 info */
    res = tpl0501_info(&info);
    if (res != 0)
    {
        tpl0501_interface_debug_print("tpl0501: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        tpl0501_interface_debug_print("tpl0501: chip is %s.\n", info.chip_name);
        tpl0501_interface_debug_print("tpl0501: manufacturer is %s.\n", info.manufacturer_name);
        tpl0501_interface_debug_print("tpl0501: interface is %s.\n", info.interface);
        tpl0501_interface_debug_print("tpl0501: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        tpl0501_interface_debug_print("tpl0501: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        tpl0501_interface_debug_print("tpl0501: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        tpl0501_interface_debug_print("tpl0501: max current is %0.2fmA.\n", info.max_current_ma);
        tpl0501_interface_debug_print("tpl0501: max temperature is %0.1fC.\n", info.temperature_max);
        tpl0501_interface_debug_print("tpl0501: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* tpl0501 init */
    res = tpl0501_init(&gs_handle);
    if (res != 0)
    {
        tpl0501_interface_debug_print("tpl0501: init failed.\n");
       
        return 1;
    }
    
    /* start write test */
    tpl0501_interface_debug_print("tpl0501: start write test.\n");
    
    for (i = 0; i < times; i++)
    {
        uint8_t raw;
        
        percentage = (float)(rand() % 0xFFFFUL) / 65536.0f * 100.0f;
        /* percentage convert to register */
        res = tpl0501_percentage_convert_to_register(&gs_handle, percentage, &raw, &wl_ohm, &hw_ohm);
        if (res != 0)
        {
            tpl0501_interface_debug_print("tpl0501: percentage convert to register failed.\n");
            (void)tpl0501_deinit(&gs_handle);
            
            return 1;
        }
        
        /* percentage convert to data */
        res = tpl0501_percentage_convert_to_data(&gs_handle, raw, &percentage_check, &wl_ohm_check, &hw_ohm_check);
        if (res != 0)
        {
            tpl0501_interface_debug_print("tpl0501: percentage convert to data failed.\n");
            (void)tpl0501_deinit(&gs_handle);
            
            return 1;
        }
        
        /* write data */
        res = tpl0501_write(&gs_handle, raw);
        if (res != 0)
        {
            tpl0501_interface_debug_print("tpl0501: write failed.\n");
            (void)tpl0501_deinit(&gs_handle);
            
            return 1;
        }
        
        /* output */
        tpl0501_interface_debug_print("tpl0501: percentage is %0.2f%%.\n", percentage);
        tpl0501_interface_debug_print("tpl0501: wl is %0.2fohm.\n", wl_ohm);
        tpl0501_interface_debug_print("tpl0501: hw is %0.2fohm.\n", hw_ohm);
        tpl0501_interface_debug_print("tpl0501: percentage check is %0.2f%%.\n", percentage_check);
        tpl0501_interface_debug_print("tpl0501: wl check is %0.2fohm.\n", wl_ohm_check);
        tpl0501_interface_debug_print("tpl0501: hw check is %0.2fohm.\n", hw_ohm_check);
        
        /* delay 5000ms */
        tpl0501_interface_delay_ms(5000);
    }
    
    /* finish write test */
    tpl0501_interface_debug_print("tpl0501: finish write test.\n");  
    (void)tpl0501_deinit(&gs_handle);
    
    return 0;
}
