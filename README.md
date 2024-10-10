[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver TPL0501

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/tpl0501/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

The TPL0501 device is a single-channel, linear-taper, digital potentiometer with 256 wiper positions. This device can be used as a three-terminal potentiometer or as a two-terminal rheostat. The TPL0501 is currently offered with end-to-end resistance of 100 kΩ. The internal registers of the TPL0501 can be accessed using a SPI-compatible interface. The TPL0501 has a nominal temperature coefficient of 35 ppm/°C.

LibDriver TPL0501 is the full function driver of TPL0501 launched by LibDriver.It provides digital potentiometer function. LibDriver is MISRA compliant.

### Table of Contents

  - [Instruction](#Instruction)
  - [Install](#Install)
  - [Usage](#Usage)
    - [example basic](#example-basic)
  - [Document](#Document)
  - [Contributing](#Contributing)
  - [License](#License)
  - [Contact Us](#Contact-Us)

### Instruction

/src includes LibDriver TPL0501 source files.

/interface includes LibDriver TPL0501 SPI platform independent template.

/test includes LibDriver TPL0501 driver test code and this code can test the chip necessary function simply.

/example includes LibDriver TPL0501 sample code.

/doc includes LibDriver TPL0501 offline document.

/datasheet includes TPL0501 datasheet.

/project includes the common Linux and MCU development board sample code. All projects use the shell script to debug the driver and the detail instruction can be found in each project's README.md.

/misra includes the LibDriver MISRA code scanning results.

### Install

Reference /interface SPI platform independent template and finish your platform SPI driver.

Add the /src directory, the interface driver for your platform, and your own drivers to your project, if you want to use the default example drivers, add the /example directory to your project.

### Usage

You can refer to the examples in the /example directory to complete your own driver. If you want to use the default programming examples, here's how to use them.

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

### Document

Online documents: [https://www.libdriver.com/docs/tpl0501/index.html](https://www.libdriver.com/docs/tpl0501/index.html).

Offline documents: /doc/html/index.html.

### Contributing

Please refer to CONTRIBUTING.md.

### License

Copyright (c) 2015 - present LibDriver All rights reserved



The MIT License (MIT) 



Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions: 



The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software. 



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE. 

### Contact Us

Please send an e-mail to lishifenging@outlook.com.