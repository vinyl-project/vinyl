import pyvinyl


import cv2 as cv
img = cv.imread("python/test.png")
cv.imshow("Image",img)
print(type(img[0][0][0]))


# pyvinyl.move_to(20, 20)

# pyvinyl.left_double_click()

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
