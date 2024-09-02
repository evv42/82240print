# 82240print - tools for using a HP 82240(B) infrared printer with a computer.

## Contents  

82240print.c: PC-side program. takes an image (handled by stb_image.h) as argument and outputs a stdout stream.  
82240blinker: Arduino-side program. converts a serial data input to an IR output usable by the printer  

## Usage

Put an IR led between D2 and GND on a Atmega328P-based Arduino.  
Upload the program, the printer is now exposed through the serial interface at 115200 baud.  
You can either send ASCII/raw commands to it, or use the supplied 82240print program to print an image.  

## Build

```
$ cc 82240print.c -lm -o 82240print

(there's probably a thousand other ways)

for the arduino part, refer to the usual methods
```



## Disclaimer

This software is provided 'AS-IS', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.  

