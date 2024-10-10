### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

SPI Pin: SCK/MOSI/CS  PA5/PA7/PA4.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. TPL0501

#### 3.1 Command Instruction

1. Show tpl0501 chip and driver information.

   ```shell
   tpl0501 (-i | --information)
   ```

2. Show tpl0501 help.

   ```shell
   tpl0501 (-h | --help)
   ```

3. Show tpl0501 pin connections of the current board.

   ```shell
   tpl0501 (-p | --port)
   ```

4. Run tpl0501 write test, num is the test times. 

   ```shell
   tpl0501 (-t write | --test=write) [--times=<num>]
   ```

5. Run tpl0501 write function, percentage is the set percentage. 

   ```shell
   tpl0501 (-e write | --example=write) [--percentage=<percentage>]
   ```

#### 3.2 Command Example

```shell
tpl0501 -i

tpl0501: chip is Texas Instruments TPL0501.
tpl0501: manufacturer is Texas Instruments.
tpl0501: interface is SPI.
tpl0501: driver version is 1.0.
tpl0501: min supply voltage is 2.7V.
tpl0501: max supply voltage is 5.5V.
tpl0501: max current is 5.00mA.
tpl0501: max temperature is 125.0C.
tpl0501: min temperature is -40.0C.
```

```shell
tpl0501 -p

tpl0501: SCK connected to GPIOA PIN5.
tpl0501: MOSI connected to GPIOA PIN7.
tpl0501: CS connected to GPIOA PIN4.
```

```shell
tpl0501 -t write --times=3

tpl0501: chip is Texas Instruments TPL0501.
tpl0501: manufacturer is Texas Instruments.
tpl0501: interface is SPI.
tpl0501: driver version is 1.0.
tpl0501: min supply voltage is 2.7V.
tpl0501: max supply voltage is 5.5V.
tpl0501: max current is 5.00mA.
tpl0501: max temperature is 125.0C.
tpl0501: min temperature is -40.0C.
tpl0501: start write test.
tpl0501: percentage is 96.47%.
tpl0501: wl is 96470.64ohm.
tpl0501: hw is 3529.36ohm.
tpl0501: percentage check is 96.09%.
tpl0501: wl check is 96093.75ohm.
tpl0501: hw check is 3906.25ohm.
tpl0501: percentage is 57.54%.
tpl0501: wl is 57536.32ohm.
tpl0501: hw is 42463.68ohm.
tpl0501: percentage check is 57.42%.
tpl0501: wl check is 57421.88ohm.
tpl0501: hw check is 42578.12ohm.
tpl0501: percentage is 85.49%.
tpl0501: wl is 85493.47ohm.
tpl0501: hw is 14506.53ohm.
tpl0501: percentage check is 85.16%.
tpl0501: wl check is 85156.25ohm.
tpl0501: hw check is 14843.75ohm.
tpl0501: finish write test.
```

```shell
tpl0501 -e write --percentage=56.12

tpl0501: percentage is 56.12%.
tpl0501: wl is 56120.00ohm.
tpl0501: hw is 43880.00ohm.
```

```shell
tpl0501 -h

Usage:
  tpl0501 (-i | --information)
  tpl0501 (-h | --help)
  tpl0501 (-p | --port)
  tpl0501 (-t write | --test=write) [--times=<num>]
  tpl0501 (-e write | --example=write) [--percentage=<percentage>]

Options:
  -e <write>, --example=<write>      Run the driver example.
  -h, --help                         Show the help.
  -i, --information                  Show the chip information.
  -p, --port                         Display the pin connections of the current board.
      --percentage                   Set input percentage.([default: 50.0])
  -t <write>, --test=<write>         Run the driver test.
      --times=<num>                  Set the running times.([default: 3])
```

