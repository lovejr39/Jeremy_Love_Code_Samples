//Lab 2, Section 2, Task 1
//Jeremy Love
//9/23/2022

#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void timer_handler(int signum)
{    
    static int count = 0 ;
    struct timeval ts ;
    
    count += 1 ;
    gettimeofday(&ts, NULL) ;
    printf("%d.%06d: timer expired, interrupt triggered x %d times\n", ts.tv_sec, ts.tv_usec, count) ;
}

int main(){

    struct sigaction sa;
    struct itimerval timer;
    
    //Set timer_handler to be signal handler for SIGVTALRM
        memset(&sa, 0, sizeof(sa)) ;
        sa.sa_handler = &timer_handler ;
        sigaction(SIGVTALRM, &sa, NULL);
    
    //Set the timer to expire over repeated time interval
        timer.it_value.tv_sec = 0 ;
        timer.it_value.tv_usec = 500000 ;
        timer.it_interval.tv_sec = 0 ;
        timer.it_interval.tv_usec = 500000 ;
    
    //Start a virtual timer. It counts down whenever this process is executing
        setitimer(ITIMER_VIRTUAL, &timer, NULL);
    
    //Do busy work
        while(1);

}
