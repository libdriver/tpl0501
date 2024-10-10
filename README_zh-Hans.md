[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver TPL0501

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/tpl0501/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

TPL0501器件是一款单通道线性锥形数字电位器，带有256个游标位置。该器件可用作三端电位器或者两端变阻器。TPL0501现配有100kΩ的端到端电阻。可使用SPI兼容接口存取TPL0501的内部寄存器。TPL050的标称温度系数为35ppm/°C。

LibDriver TPL0501是LibDriver推出的TPL0501全功能驱动，该驱动提供数字电位器功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver TPL0501的源文件。

/interface目录包含了LibDriver TPL0501与平台无关的SPI总线模板。

/test目录包含了LibDriver TPL0501驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver TPL0501编程范例。

/doc目录包含了LibDriver TPL0501离线文档。

/datasheet目录包含了TPL0501数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的SPI总线模板，完成指定平台的SPI总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

#### example basic

```C
#include "driver_tpl0501_basic.h"

uint8_t res;
float wl_ohm;
float hw_ohm;
float percentage = 50.0f;

/* init */
res = tpl0501_basic_init();
if (res != 0)
{
    return 1;
}

...
    
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

...
    
/* deinit */
(void)tpl0501_basic_deinit();

return 0;
```

### 文档

在线文档: [https://www.libdriver.com/docs/tpl0501/index.html](https://www.libdriver.com/docs/tpl0501/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。