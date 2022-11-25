Jeremy Love

This folder contains the files for Lab 3: "Cache and I/O Programming over 
  Raspberry Pi" for the class ECE 1175, Embedded Systems Design.

All files within this folder are edited code samples given to complete the
  lab via usage of a Raspberry Pi 4B and a Raspberry Pi Sense HAT.

The relevant lab description is below.

The ".c" file contains a program that fulfills the requirements from the 
  lab description.

-----------------------------------------------------------------------------

2231 ECE 1175 SEC1075
University of Pittsburgh
Swanson School of Engineering
Fall Term 2022

ECE 1175 - Lab 3 - Cache and I/O Programming over Raspberry Pi

Lab 3 consists of two sections. Both use C/C++ as the programming language. 
  In section 1, you will use the performance analyzing tool perf to measure 
  the cache miss rate of your program. In section 2, you will practice how to 
  directly manipulate GPIO registers from Raspberry Pi OS. Please refer to the 
  lab slides and video for more details.

Section 1 (50%): This section uses C++ as the programming language.

Section 2 (50%): This section uses C as the programming language.

Direct GPIO Access on Raspberry Pi OS

Please write C code to directly manipulate GPIO registers from Raspberry Pi OS 
  (Raspbian).  

For security reasons, the operating system itself does not provide direct access 
  to the physical memory and users are basically doing all their work on the 
  virtual memory. You need to use mmap() and the device file dev/mem to create a 
  mapping from virtual memory (user space) to physical memory (GPIO registers), 
  such that you will be able to manipulate GPIO registers through your program.

To debug and demonstrate your code, you can use GPIO 42 to control the onboard 
  green LED to show a blinking pattern (to setup the LED, refer to lab lecture 
  slides). Alternatively, if you have an external LED, or you have a multimeter 
  or oscilloscope, you could use that to indicate your GPIO output.

You can first use existing libraries such as RPi.GPIO for debugging, then need 
  to find a way to manipulate GPIO directly through the registers.

-----------------------------------------------------------------------------

Grade: 100/100 (50/50 in application sections)