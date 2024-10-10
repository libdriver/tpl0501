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
 * @file      driver_tpl0501.c
 * @brief     driver tpl0501 source file
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

#include "driver_tpl0501.h"

/**
 * @brief chip information definition
 */
#define CHIP_NAME                 "Texas Instruments TPL0501"        /**< chip name */
#define MANUFACTURER_NAME         "Texas Instruments"                /**< manufacturer name */
#define SUPPLY_VOLTAGE_MIN        2.7f                               /**< chip min supply voltage */
#define SUPPLY_VOLTAGE_MAX        5.5f                               /**< chip max supply voltage */
#define MAX_CURRENT               5.0f                               /**< chip max current */
#define TEMPERATURE_MIN           -40.0f                             /**< chip min operating temperature */
#define TEMPERATURE_MAX           125.0f                             /**< chip max operating temperature */
#define DRIVER_VERSION            1000                               /**< driver version */

/**
 * @brief     write byte
 * @param[in] *handle points to a tpl0501 handle structure
 * @param[in] data is the set data
 * @return    status code
 *            - 0 success
 *            - 1 spi write failed
 * @note      none
 */
static uint8_t a_tpl0501_spi_write(tpl0501_handle_t *handle, uint8_t data)
{
    uint8_t buf[1];
    
    buf[0] = data;                                 /* set data */
    if (handle->spi_write_cmd(buf, 1) != 0)        /* spi write */
    {
        return 1;                                  /* return error */
    }
    
    return 0;                                      /* success return 0 */
}

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
uint8_t tpl0501_init(tpl0501_handle_t *handle)
{
    if (handle == NULL)                                                 /* check handle */
    {
        return 2;                                                       /* return error */
    }
    if (handle->debug_print == NULL)                                    /* check debug_print */
    {
        return 3;                                                       /* return error */
    }
    if (handle->spi_init == NULL)                                       /* check spi_init */
    {
        handle->debug_print("tpl0501: spi_init is null.\n");            /* spi_init is null */
       
        return 3;                                                       /* return error */
    }
    if (handle->spi_deinit == NULL)                                     /* check spi_deinit */
    {
        handle->debug_print("tpl0501: spi_deinit is null.\n");          /* spi_deinit is null */
       
        return 3;                                                       /* return error */
    }
    if (handle->spi_write_cmd == NULL)                                  /* check spi_write_cmd */
    {
        handle->debug_print("tpl0501: spi_write_cmd is null.\n");       /* spi_read_cmd is null */
       
        return 3;                                                       /* return error */
    }
    if (handle->delay_ms == NULL)                                       /* check delay_ms */
    {
        handle->debug_print("tpl0501: delay_ms is null.\n");            /* delay_ms is null */
       
        return 3;                                                       /* return error */
    }
    
    if (handle->spi_init() != 0)                                        /* spi init */
    {
        handle->debug_print("tpl0501: spi init failed.\n");             /* spi init failed */
        
        return 1;                                                       /* return error */
    }
    handle->inited = 1;                                                 /* flag finish initialization */
    
    return 0;                                                           /* success return 0 */
}

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
uint8_t tpl0501_deinit(tpl0501_handle_t *handle)
{
    uint8_t res;
    
    if (handle == NULL)                                              /* check handle */
    {
        return 2;                                                    /* return error */
    }
    if (handle->inited != 1)                                         /* check handle initialization */
    {
        return 3;                                                    /* return error */
    }
    
    res = handle->spi_deinit();                                      /* spi deinit */
    if (res != 0)                                                    /* check result */
    {
        handle->debug_print("tpl0501: spi deinit failed.\n");        /* spi deinit failed */
       
        return 1;                                                    /* return error */
    }
    handle->inited = 0;                                              /* flag close */
    
    return 0;                                                        /* success return 0 */
}

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
uint8_t tpl0501_write(tpl0501_handle_t *handle, uint8_t raw)
{
    uint8_t res;
    
    if (handle == NULL)                                             /* check handle */
    {
        return 2;                                                   /* return error */
    }
    if (handle->inited != 1)                                        /* check handle initialization */
    {
        return 3;                                                   /* return error */
    }
    
    res =a_tpl0501_spi_write(handle, raw);                          /* set data */
    if (res != 0)                                                   /* check result */
    {
        handle->debug_print("tpl0501: read data failed.\n");        /* read data failed */
       
        return 1;                                                   /* return error */
    }
    
    return 0;                                                       /* success return 0 */
}

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
                                               float *wl_ohm, float *hw_ohm)
{
    if (handle == NULL)                                 /* check handle */
    {
        return 2;                                       /* return error */
    }
    if (handle->inited != 1)                            /* check handle initialization */
    {
        return 3;                                       /* return error */
    }
    
    *reg = (uint8_t)(percentage / 100.0f * 256);        /* convert real data to register data */
    *wl_ohm = 100 * 1000 * (percentage / 100.0f);       /* set wl ohm */
    *hw_ohm = 100 * 1000 - (*wl_ohm);                   /* set hw ohm */
    
    return 0;                                           /* success return 0 */
}

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
                                           float *wl_ohm, float *hw_ohm)
{
    if (handle == NULL)                                          /* check handle */
    {
        return 2;                                                /* return error */
    }
    if (handle->inited != 1)                                     /* check handle initialization */
    {
        return 3;                                                /* return error */
    }
    
    *percentage = (float)((float)(reg) / 256.0f) * 100.0f;       /* convert register data to real data */
    *wl_ohm = 100 * 1000 * ((float)reg / 256.0f);                /* set wl ohm */
    *hw_ohm = 100 * 1000 - (*wl_ohm);                            /* set hw ohm */
    
    return 0;                                                    /* success return 0 */
}

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
uint8_t tpl0501_set_reg(tpl0501_handle_t *handle, uint8_t raw)
{
    if (handle == NULL)                             /* check handle */
    {
        return 2;                                   /* return error */
    }
    if (handle->inited != 1)                        /* check handle initialization */
    {
        return 3;                                   /* return error */
    }
    
    return a_tpl0501_spi_write(handle, raw);        /* write data */
}

/**
 * @brief      get chip's information
 * @param[out] *info points to a tpl0501 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t tpl0501_info(tpl0501_info_t *info)
{
    if (info == NULL)                                               /* check handle */
    {
        return 2;                                                   /* return error */
    }
    
    memset(info, 0, sizeof(tpl0501_info_t));                        /* initialize tpl0501 info structure */
    strncpy(info->chip_name, CHIP_NAME, 32);                        /* copy chip name */
    strncpy(info->manufacturer_name, MANUFACTURER_NAME, 32);        /* copy manufacturer name */
    strncpy(info->interface, "SPI", 8);                             /* copy interface name */
    info->supply_voltage_min_v = SUPPLY_VOLTAGE_MIN;                /* set minimal supply voltage */
    info->supply_voltage_max_v = SUPPLY_VOLTAGE_MAX;                /* set maximum supply voltage */
    info->max_current_ma = MAX_CURRENT;                             /* set maximum current */
    info->temperature_max = TEMPERATURE_MAX;                        /* set minimal temperature */
    info->temperature_min = TEMPERATURE_MIN;                        /* set maximum temperature */
    info->driver_version = DRIVER_VERSION;                          /* set driver version */
    
    return 0;                                                       /* success return 0 */
}
