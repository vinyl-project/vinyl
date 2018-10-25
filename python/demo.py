import pyvinyl
import numpy
import cv2
import scipy.misc
import time

def fps_test(win):
    time_start=time.time()
    frame = 0

    while(True):
        screen = win.screenshot(0,0,1024,768)
        frame= frame+1
        time_end=time.time()
        print(frame/(time_end - time_start))

def find_color_test(win):
    screen = win.screenshot(0,0,600,600)
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
        win.move_to(pos[0][i], pos[1][i])
        i=i+1

def screenshot_test(win):
    s = win.size()
    screen = win.screenshot(0,0,s[0], s[1])
    scipy.misc.imsave('lenagray.jpg',screen)
    print(s)

# pyvinyl.message_box('你好')


win = pyvinyl.new_window("notepad")
# screenshot_test(win)
# win.hotkey('LeftControl', 'C')

'''
win.left_click()
win.right_click()
win.middle_click()

win.left_double_click()

win.left_down()
win.right_down()
win.middle_down()

win.left_up()
win.right_up()
win.middle_up()

x = 1
y = 1
delta = 1

win.move_to(x, y)

win.move(x, y)

win.mouse_wheel(delta)

c='a'
win.key_press(c)
win.key_up(c)
win.key_down(c)
'''
