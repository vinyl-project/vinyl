from enum import Enum
import pyvinyl
import pyvinyl.vinyl

class ButtonCode(Enum):
    Left = 0
    Right = 1
    Middle = 2
    Mouse0 = Left
    Mouse1 = Right
    Mouse2 = Middle
    Mouse3 = 3
    Mouse4 = 4
    Mouse5 = 5
    Mouse6 = 6
    Mouse7 = 7
    Mouse8 = 8
    MouseWheel = 9
    MouseX = 10
    MouseY = 11
    MouseZ = 12
    MouseLast = 13

def is_button_up(code):
    result = False
    if (type(code) == ButtonCode):
        result = pyvinyl.vinyl.is_mouse_button_up(code.value)
    elif (type(code) == str):
        result = pyvinyl.vinyl.is_mouse_button_up(ButtonCode[code].value)
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)
    return result

def is_button_down(code):
    result = False
    if (type(code) == ButtonCode):
        result = pyvinyl.vinyl.is_mouse_button_down(code.value)
    elif (type(code) == str):
        result = pyvinyl.vinyl.is_mouse_button_down(ButtonCode[code].value)
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)
    return result

def left_double_click():
    pyvinyl.vinyl.left_click()
    pyvinyl.vinyl.sleep(500)
    pyvinyl.vinyl.left_click()
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)

def middle_double_click():
    pyvinyl.vinyl.middle_click()
    pyvinyl.vinyl.sleep(500)
    pyvinyl.vinyl.middle_click()
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)

def right_double_click():
    pyvinyl.vinyl.right_click()
    pyvinyl.vinyl.sleep(500)
    pyvinyl.vinyl.right_click()
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)