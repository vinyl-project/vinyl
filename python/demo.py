import pyvinyl
import numpy
import cv2
import scipy.misc
import time

time_start=time.time()

# pyvinyl.move_to(20, 20)

# pyvinyl.left_double_click()

# pyvinyl.message_box("123")

def find_color_test():
    screen = pyvinyl.screenshot(0,0,600,600)
    print(screen.shape)

    numpy.savetxt('opt1.txt', screen, delimiter='\t', fmt='%s')

    # cv2.imshow("123", screen)
    # cv2.imwrite('lenagray.bmp',screen)
    # scipy.misc.imsave('lenagray.jpg',screen)

    pos = pyvinyl.find_color(screen, [60,60,60])
    i = 0
    len = pos[0].size
    print(len)
    while(i<len):
        pyvinyl.move_to(pos[0][i], pos[1][i])
        i=i+1

find_color_test()

'''
frame = 0

while(True):
    screen = pyvinyl.screenshot(0,0,1024,768)
    frame= frame+1
    time_end=time.time()
    print(frame/(time_end - time_start))
    
'''


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
