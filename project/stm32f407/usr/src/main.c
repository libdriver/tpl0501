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
 * @file      main.c
 * @brief     main source file
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
#include "driver_tpl0501_basic.h"
#include "shell.h"
#include "clock.h"
#include "delay.h"
#include "uart.h"
#include "getopt.h"
#include <stdlib.h>

/**
 * @brief global var definition
 */
uint8_t g_buf[256];        /**< uart buffer */
volatile uint16_t g_len;   /**< uart buffer length */

/**
 * @brief     tpl0501 full function
 * @param[in] argc arg numbers
 * @param[in] **argv arg address
 * @return    status code
 *            - 0 success
 *            - 1 run failed
 *            - 5 param is invalid
 * @note      none
 */
uint8_t tpl0501(uint8_t argc, char **argv)
{
    int c;
    int longindex = 0;
    const char short_options[] = "hipe:t:";
    const struct option long_options[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"information", no_argument, NULL, 'i'},
        {"port", no_argument, NULL, 'p'},
        {"example", required_argument, NULL, 'e'},
        {"test", required_argument, NULL, 't'},
        {"times", required_argument, NULL, 1},
        {"percentage", required_argument, NULL, 2},
        {NULL, 0, NULL, 0},
    };
    char type[33] = "unknown";
    float percentage = 50.0f;
    uint32_t times = 3;

    /* if no params */
    if (argc == 1)
    {
        /* goto the help */
        goto help;
    }

    /* init 0 */
    optind = 0;

    /* parse */
    do
    {
        /* parse the args */
        c = getopt_long(argc, argv, short_options, long_options, &longindex);

        /* judge the result */
        switch (c)
        {
            /* help */
            case 'h' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "h");

                break;
            }

            /* information */
            case 'i' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "i");

                break;
            }

            /* port */
            case 'p' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "p");

                break;
            }

            /* example */
            case 'e' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "e_%s", optarg);

                break;
            }

            /* test */
            case 't' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "t_%s", optarg);

                break;
            }

            /* running times */
            case 1 :
            {
                /* set the times */
                times = atol(optarg);

                break;
            }

            /* rpercentage */
            case 2 :
            {
                /* percentage */
                percentage = (float)atof(optarg);

                break;
            }

            /* the end */
            case -1 :
            {
                break;
            }

            /* others */
            default :
            {
                return 5;
            }
        }
    } while (c != -1);

    /* run the function */
    if (strcmp("t_write", type) == 0)
    {
        uint8_t res;

        /* run the write test */
        res = tpl0501_write_test(times);
        if (res != 0)
        {
            return 1;
        }

        return 0;
    }
    else if (strcmp("e_write", type) == 0)
    {
        uint8_t res;
        float wl_ohm;
        float hw_ohm;

        /* init */
        res = tpl0501_basic_init();
        if (res != 0)
        {
            return 1;
        }

        /* write data */
        res = tpl0501_basic_write(percentage, &wl_ohm, &hw_ohm);
        if (res != 0)
        {
            (void)tpl0501_basic_deinit();

            return 1;
        }

        /* output */
        tpl0501_interface_debug_print("tpl0501: percentage is %0.2f%%.\n", percentage);
        tpl0501_interface_debug_print("tpl0501: wl is %0.2fohm.\n", wl_ohm);
        tpl0501_interface_debug_print("tpl0501: hw is %0.2fohm.\n", hw_ohm);

        /* delay 1000ms */
        tpl0501_interface_delay_ms(1000);

        /* deinit */
        (void)tpl0501_basic_deinit();

        return 0;
    }
    else if (strcmp("h", type) == 0)
    {
        help:
        tpl0501_interface_debug_print("Usage:\n");
        tpl0501_interface_debug_print("  tpl0501 (-i | --information)\n");
        tpl0501_interface_debug_print("  tpl0501 (-h | --help)\n");
        tpl0501_interface_debug_print("  tpl0501 (-p | --port)\n");
        tpl0501_interface_debug_print("  tpl0501 (-t write | --test=write) [--times=<num>]\n");
        tpl0501_interface_debug_print("  tpl0501 (-e write | --example=write) [--percentage=<percentage>]\n");
        tpl0501_interface_debug_print("\n");
        tpl0501_interface_debug_print("Options:\n");
        tpl0501_interface_debug_print("  -e <write>, --example=<write>      Run the driver example.\n");
        tpl0501_interface_debug_print("  -h, --help                         Show the help.\n");
        tpl0501_interface_debug_print("  -i, --information                  Show the chip information.\n");
        tpl0501_interface_debug_print("  -p, --port                         Display the pin connections of the current board.\n");
        tpl0501_interface_debug_print("      --percentage                   Set input percentage.([default: 50.0])\n");
        tpl0501_interface_debug_print("  -t <write>, --test=<write>         Run the driver test.\n");
        tpl0501_interface_debug_print("      --times=<num>                  Set the running times.([default: 3])\n");

        return 0;
    }
    else if (strcmp("i", type) == 0)
    {
        tpl0501_info_t info;

        /* print tpl0501 info */
        tpl0501_info(&info);
        tpl0501_interface_debug_print("tpl0501: chip is %s.\n", info.chip_name);
        tpl0501_interface_debug_print("tpl0501: manufacturer is %s.\n", info.manufacturer_name);
        tpl0501_interface_debug_print("tpl0501: interface is %s.\n", info.interface);
        tpl0501_interface_debug_print("tpl0501: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        tpl0501_interface_debug_print("tpl0501: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        tpl0501_interface_debug_print("tpl0501: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        tpl0501_interface_debug_print("tpl0501: max current is %0.2fmA.\n", info.max_current_ma);
        tpl0501_interface_debug_print("tpl0501: max temperature is %0.1fC.\n", info.temperature_max);
        tpl0501_interface_debug_print("tpl0501: min temperature is %0.1fC.\n", info.temperature_min);

        return 0;
    }
    else if (strcmp("p", type) == 0)
    {
        /* print pin connection */
        tpl0501_interface_debug_print("tpl0501: SCK connected to GPIOA PIN5.\n");
        tpl0501_interface_debug_print("tpl0501: MOSI connected to GPIOA PIN7.\n");
        tpl0501_interface_debug_print("tpl0501: CS connected to GPIOA PIN4.\n");

        return 0;
    }
    else
    {
        return 5;
    }
}

/**
 * @brief main function
 * @note  none
 */
int main(void)
{
    uint8_t res;

    /* stm32f407 clock init and hal init */
    clock_init();

    /* delay init */
    delay_init();

    /* uart init */
    uart_init(115200);

    /* shell init && register tpl0501 function */
    shell_init();
    shell_register("tpl0501", tpl0501);
    uart_print("tpl0501: welcome to libdriver tpl0501.\n");

    while (1)
    {
        /* read uart */
        g_len = uart_read(g_buf, 256);
        if (g_len != 0)
        {
            /* run shell */
            res = shell_parse((char *)g_buf, g_len);
            if (res == 0)
            {
                /* run success */
            }
            else if (res == 1)
            {
                uart_print("tpl0501: run failed.\n");
            }
            else if (res == 2)
            {
                uart_print("tpl0501: unknown command.\n");
            }
            else if (res == 3)
            {
                uart_print("tpl0501: length is too long.\n");
            }
            else if (res == 4)
            {
                uart_print("tpl0501: pretreat failed.\n");
            }
            else if (res == 5)
            {
                uart_print("tpl0501: param is invalid.\n");
            }
            else
            {
                uart_print("tpl0501: unknown status code.\n");
            }
            uart_flush();
        }
        delay_ms(100);
    }
}
