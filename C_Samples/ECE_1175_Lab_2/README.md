Jeremy Love

This folder contains the files for Lab 2: "I/O Programming" for the class 
  ECE 1175, Embedded Systems Design.

All files within this folder were edited code samples given to complete the
  lab via usage of a Raspberry Pi 4B and a Raspberry Pi Sense HAT.

The relevant lab description is below.

The ".c" file contains a program that fulfills the requirements from the 
  lab description.

-----------------------------------------------------------------------------

2231 ECE 1175 SEC1075
University of Pittsburgh
Swanson School of Engineering
Fall Term 2022

ECE 1175 - Lab 2 - I/O Programming

Lab 2 consists of two sections.

Section 1 (50%): This section uses Python as the programming language.

Section 2 (50%): This section uses C as the programming language.

In this section, you are required to write a system-call-based interrupt 
  over Linux. In completing this section, you need to use timer inside 
  Linux-based operating system to trigger interrupt. When timer expired, 
  as advent of an interrupt, you need to send a signal to kernel to run 
  specific function for handling this expired timer or interrupt.

Useful library could be sys/time.h and signal.h
Useful functions could be memset(), setitimer() and sigaction()
Useful structure variables could be sigaction, and itimerval

-----------------------------------------------------------------------------

Grade: 100/100 (50/50 in application sections)