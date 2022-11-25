#Lab 2, Setion 1, Task1
#Jeremy Love
#9/23/2022

from sense_hat import SenseHat
import time

sense = SenseHat()
sense.clear()

w = (255,255,255)
r = (255,0,0)
b = (0,0,255)
n = (0,0,0)

wipe_1 = [
    n,r,w,b,n,r,w,b,
    b,n,r,w,b,n,r,w,
    w,b,n,r,w,b,n,r,
    r,w,b,n,r,w,b,n,
    n,r,w,b,n,r,w,b,
    b,n,r,w,b,n,r,w,
    w,b,n,r,w,b,n,r,
    r,w,b,n,r,w,b,n
    ]

wipe_2 = [
    r,w,b,n,r,w,b,n,
    n,r,w,b,n,r,w,b,
    b,n,r,w,b,n,r,w,
    w,b,n,r,w,b,n,r,
    r,w,b,n,r,w,b,n,
    n,r,w,b,n,r,w,b,
    b,n,r,w,b,n,r,w,
    w,b,n,r,w,b,n,r
    ]
    
wipe_3 = [
    w,b,n,r,w,b,n,r,
    r,w,b,n,r,w,b,n,
    n,r,w,b,n,r,w,b,
    b,n,r,w,b,n,r,w,
    w,b,n,r,w,b,n,r,
    r,w,b,n,r,w,b,n,
    n,r,w,b,n,r,w,b,
    b,n,r,w,b,n,r,w
    ]
    
wipe_4 = [
    b,n,r,w,b,n,r,w,
    w,b,n,r,w,b,n,r,
    r,w,b,n,r,w,b,n,
    n,r,w,b,n,r,w,b,
    b,n,r,w,b,n,r,w,
    w,b,n,r,w,b,n,r,
    r,w,b,n,r,w,b,n,
    n,r,w,b,n,r,w,b
    ]
    
def blinky():
    while True:
        sense.set_pixels(wipe_1)
        time.sleep(0.25)
        sense.set_pixels(wipe_2)
        time.sleep(0.25)
        sense.set_pixels(wipe_3)
        time.sleep(0.25)
        sense.set_pixels(wipe_4)
        time.sleep(0.25)
        
blinky()
