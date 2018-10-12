import pyvinyl
import numpy
import cv2
import time

time_start=time.time()

# pyvinyl.move_to(20, 20)

# pyvinyl.left_double_click()

# pyvinyl.message_box("123")
frame = 0

while(True):
    screen = pyvinyl.screenshot(0,0,1024,768)
    frame= frame+1
    time_end=time.time()
    print(frame/(time_end - time_start))


cv2.imwrite('lenagray.png',screen)

'''
vinyl.left_click()
vinyl.right_click()
vinyl.middle_click()

vinyl.left_double_click()

vinyl.left_down()
vinyl.right_down()
vinyl.middle_down()

vinyl.left_up()
vinyl.right_up()
vinyl.middle_up()

x = 1
y = 1
delta = 1

vinyl.move_to(x, y)

vinyl.move(x, y)

vinyl.mouse_wheel(delta)

c='a'
vinyl.key_press(c)
vinyl.key_up(c)
vinyl.key_down(c)
'''
