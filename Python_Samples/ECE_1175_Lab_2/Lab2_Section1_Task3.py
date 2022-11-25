#Lab 2, Setion 1, Task 3
#Jeremy Love
#9/23/2022

from sense_hat import SenseHat
import time

sense = SenseHat()

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

def wipe_columns(num):
    
    if num != -1:
        i=0
        row = 0
        while row <=7:
            for col in range(8):
                sense.set_pixel(row,col,colors[i])
            time.sleep(0.2)
            i += 1
            row += 1
            sense.clear()
    else:
        i=0
        row = 7
        while row >= 0:
            for col in range(8):
                sense.set_pixel(row,col,colors[i])
            time.sleep(0.2)
            i += 1
            row -= 1
            sense.clear()

def wipe_rows(num):
    
    if num == -1:
        i=0
        row = 7
        while row >=0:
            for col in range(8):
                sense.set_pixel(col,row,colors[i])
            time.sleep(0.2)
            i += 1
            row -= 1
            sense.clear()
    else:
        i=0
        row = 0
        while row <= 7:
            for col in range(8):
                sense.set_pixel(col,row,colors[i])
            time.sleep(0.2)
            i += 1
            row += 1
            sense.clear()


while True:
    
    movement = sense.get_accelerometer_raw()
    x = movement['x']
    y = movement['y']
    z = movement['z']

    x = round(x, 0)
    y = round(y, 0)
    z = round(z, 0)

        
    if x==0 and y==0:
        
        if z==1:
            sense.show_message("UP")
            sense.clear()
        else:
            print("DOWN")
            
    elif abs(x) >= abs(y):
        wipe_columns(x)
        sense.clear()
        
    elif abs(x) < abs(y):
        wipe_rows(y)
        sense.clear()



