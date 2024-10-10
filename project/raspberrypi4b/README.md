### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

SPI Pin: SCLK/MOSI/CS  GPIO11/GPIO10/GPIO8.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(tpl0501 REQUIRED)
```

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
./tpl0501 -i

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
./tpl0501 -p

tpl0501: SCK connected to GPIO11(BCM).
tpl0501: MOSI connected to GPIO10(BCM).
tpl0501: CS connected to GPIO8(BCM).
```

```shell
./tpl0501 -t write --times=3

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
tpl0501: percentage is 69.12%.
tpl0501: wl is 69119.27ohm.
tpl0501: hw is 30880.73ohm.
tpl0501: percentage check is 68.75%.
tpl0501: wl check is 68750.00ohm.
tpl0501: hw check is 31250.00ohm.
tpl0501: percentage is 33.69%.
tpl0501: wl is 33692.93ohm.
tpl0501: hw is 66307.06ohm.
tpl0501: percentage check is 33.59%.
tpl0501: wl check is 33593.75ohm.
tpl0501: hw check is 66406.25ohm.
tpl0501: percentage is 98.69%.
tpl0501: wl is 98689.27ohm.
tpl0501: hw is 1310.73ohm.
tpl0501: percentage check is 98.44%.
tpl0501: wl check is 98437.50ohm.
tpl0501: hw check is 1562.50ohm.
tpl0501: finish write test.
```

```shell
./tpl0501 -e write --percentage=56.12

tpl0501: percentage is 56.12%.
tpl0501: wl is 56120.00ohm.
tpl0501: hw is 43880.00ohm.
```

```shell
./tpl0501 -h

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

