Jeremy Love

This folder contains the files for Lab 4: "Real-Time Scheduling" for the 
  class ECE 1175, Embedded Systems Design.

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

ECE 1175 - Lab 4 - Real-Time Scheduling

Lab 4 consists of 3 sections.

Section 1 (30%) 
You are required to realize rate monotonic scheduling algorithm.

Please read rms.c file in detail. Try to use the following example as input 
  to see how sample code will work:
 
	Execution	Period
P1	10		25
P2	15		60

The sample code does not consider preemptive scenarios. Your task is to 
  modify the sample code so that it could schedule well while preemptive 
  scenarios occur. You can use the following example to test if your 
  modified code could handle preemptive situation.

	Execution	Period
P1	20		50
P2	35		100

Section 2 (30%)
You are required to realize earliest deadline first scheduling algorithm.

Please also read rms.c file in detail. Based on rms.c file, think about how 
  to modify the judgement so as to realize EDF algorithm. You can try the 
  following sample to see if your modified version works well:

	Execution	Period
P1	10		20
P2	25		50

Please double check with the following example to see if your algorithm 
  could handle preemptive scenario:

	Execution	Period
P1	25		50
P2	35		80

Section 3 (40%)
You are required to implement a program that can demonstrate priority 
  inheritance.

1. In this section, you should create at least three threads to realize 
     priority inheritance. The design could be as following:

void function()
{
  //do some work here.
}

void function1()
{
  //function 1 for thread 1.

  //do some work here
}

void function2()
{
  //function 2 for thread 2.

  //do some work here and call function()
}

void function3()
{
  //function 3 for thread 3.

  //do some work here
}

int main()
{
  //create mutex and initialize it.

  //create thread 1, thread 2 and thread 3

  //set different priority for each thread

  //set handler for thread 1, thread 2 and thread 3 respectively. For 
  //  instance, function 1 for thread 1, function 2 for thread 2 and
  //  function 3 for thread 3
}

2. For "do some work" in design chart, you may choose to print some messages 
     to terminal. For example: "Thread 1 in", "Thread 1 starts", "Thread 1 
     ends" and "Thread 1 out" are used to simply describe the work each 
     thread will do.
3. Please think carefully on what priority inheritance is, e.g., the advent 
   order of each thread. For example, if thread 1 has the lowest priority 
   and thread 3 has the highest priority. The definition of priority 
   inheritance is that thread 1 should be earlier than thread 3 and thread 2 
   is later than thread 3.

General recommendations:
  -  Run your program with privilege (run as "root" or using "sudo"). This 
       may circumvent permission issues (if any) when configuring thread 
       priorities.
  -  Consider whether limiting the number of CPU cores your program may use 
       is necessary. You may limit it by setting CPU affinity and disallow 
       placing multiple threads on different CPU cores.
  -  The following libraries, data types and functions may be useful when 
       writing your code:

Library and header files:
  "stdio.h", "stdlib.h", "unistd.h", "pthread.h" and "sched.h"

Data types:
  pthread_t: thread variable
  pthread_mutex_t: mutex variabl
  pthread_mutexattr_t: mutex attribute variable
  sched_param: structure variable for buffering thread priority

Functions:
  pthread_mutexattr_setprotocol(): set protocol for mutex attribute variable
  pthread_mutex_init(): initialize mutex variable
  pthread_mutex_lock(): lock mutex variable
  pthread_mutex_unlock():unlock mutex variable
  pthread_create(): create a thread
  pthread_setschedparam(): set priority, policy for a thread
  pthread_getschedparam(): get priority, policy of a thread
  pthread_join(): wait for all threads to finish before main() can exit
  pthread_setaffinity_np, pthread_getaffinity_np: get/get CPU affinity of a 
    thread
  sched_setaffinity, sched_getaffinity: set and get a thread's CPU affinity 
    mask

Work submission
  Ask the TA to check you off after you finish, and submit your code for all 
    sections to the TA.

-----------------------------------------------------------------------------

Grade: 100/100