# Debugging with ESP32 using JLink debugger

This document assumes that the esp toolchain is installed in a directory names 'esp' which will be referenced as ESP_PATH

## Install JLink software

To see if this is already installed:
```bash
JLinkExe
```

If is not installed, Download the latest package from:
https://www.segger.com/downloads/jlink/

## Install Openocd for esp32

```bash
cd ESP_PATH
wget https://github.com/espressif/openocd-esp32/releases/download/v0.10.0-esp32-20190313/openocd-esp32-linux64-0.10.0-esp32-20190313.tar.gz
tar -xzf ~/Downloads/xtensa-esp32-elf-linux64-1.22.0-80-g6c4433a-5.2.0.tar.gz
tar -xzf openocd-esp32-linux64-0.10.0-esp32-20190313.tar.gz
```
## Start OpenOcd

Make sure device is connected.

This step will start up the gdb server and connect to the target device.

```bash
cd ESP_PATH/openocd-esp32
bin/openocd -s share/openocd/scripts -f interface/jlink.cfg -f board/esp32-wrover.cfg
```
>If you are using a module other that the wrover , there are more options. Look through ESP_PATH/openocd-esp32/openocd/scripts/board


## Create gdbinit file for project

Create a file in your projects root directory named '.gdbinit'. Copy and paste these contents:

```bash
target remote :3333
set remote hardware-watchpoint-limit 2
mon reset halt
flushregs
thb app_main
c
```

## Debug!

Once those steps are done build the project and flash the board with the normal process. Then connect to the gdb server :

```bash
xtensa-esp32-elf-gdb -x gdbinit path/to/project.elf
```

This will give you a command line gdb console. If you prefer to use a gui debugger, just make sure that it is set up to call xtensa-esp32-elf-gdb, and it should work the same.
