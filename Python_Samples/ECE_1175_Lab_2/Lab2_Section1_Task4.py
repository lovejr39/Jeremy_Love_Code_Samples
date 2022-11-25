#Lab 2, Setion 1, Task 4
#Jeremy Love
#9/23/2022

from sense_hat import SenseHat
import time

sense = SenseHat()
sense.clear()

n = (0,0,0)

r = (255,0,0)
o = (255,125,0)
y = (255,255,0)
g = (0,255,0)
b = (0,0,255)
pu = (150,0,150)
pi = (255,100,175)
w = (255,255,255)

colors = [r, o, y, g, b, pu, pi, w]

while True:
    
    i = 0
    size = 7
    x = 0
    y = 0
    
    while x <= size and y <= size :
        
        if x == 0 and y == 0 :
            sense.set_pixel(x, y, colors[i])
            
        elif x != 0 and y != 0 :
            j = 0
            k = 0
            
            while j <= x :
                while k <= y : 
                    if j + k == x :
                        sense.set_pixel(j, k, colors[i])
                        sense.set_pixel(k, j, colors[i])
                    k += 1
                j += 1
                k = 0
                    
        time.sleep(0.1)
        
        x += 1
        y += 1
        i += 1
        
        sense.clear()
        
    i = 0
    
    while x <= 2 * size and y <= 2 * size :
        
        if x != 0 and y != 0 :
            j = 0
            k = 0
            
            while j <= size :
                while k <= size :
                    if j + k == x :
                        sense.set_pixel(j, k, colors[i])
                        sense.set_pixel(k, j, colors[i])
                    k += 1
                j += 1
                k = 0
                
            time.sleep(0.1)
            
            x += 1
            y += 1
            i += 1
            
            sense.clear()
