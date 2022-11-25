#Lab 2, Setion 1, Task 2
#Jeremy Love
#9/23/2022

from sense_hat import SenseHat
import time

sense = SenseHat()
sense.clear()

b = (0,0,255)
n = (0,0,0)

burst_pattern = [
    b,n,b,n,n,b,n,b,
    n,b,n,b,b,n,b,n,
    b,n,b,n,n,b,n,b,
    n,b,n,b,b,n,b,n,
    n,b,n,b,b,n,b,n,
    b,n,b,n,n,b,n,b,
    n,b,n,b,b,n,b,n,
    b,n,b,n,n,b,n,b,
    ]

while True:
    
    for event in sense.stick.get_events() :
        
        if event.direction == 'left' and event.action == 'pressed' :
            sense.clear()
            sense.show_message("LEFT", back_colour=[255,0,0])
            
        elif event.direction == 'up' and event.action == 'pressed' :
            sense.clear()
            sense.show_message("UP", back_colour=[255,0,0])
            
        elif event.direction == 'right' and event.action == 'pressed' :
            sense.clear()
            sense.show_message("RIGHT", back_colour=[255,0,0])
            
        elif event.direction == 'down' and event.action == 'pressed' :
            sense.clear()
            sense.show_message("DOWN", back_colour=[255,0,0])
            
        elif event.direction == 'middle' and event.action == 'pressed' :
            sense.clear()
            sense.set_pixels(burst_pattern)
            time.sleep(1)

        sense.clear()
        