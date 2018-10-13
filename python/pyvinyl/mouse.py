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

def position():
    pass

def is_button_up(code):
    result = False
    if (type(code) == ButtonCode):
        result = pyvinyl.vinyl.is_mouse_button_up(code.value)
    elif (type(code) == str):
        result = pyvinyl.vinyl.is_mouse_button_up(ButtonCode[code].value)
    return result

def is_button_down(code):
    result = False
    if (type(code) == ButtonCode):
        result = pyvinyl.vinyl.is_mouse_button_down(code.value)
    elif (type(code) == str):
        result = pyvinyl.vinyl.is_mouse_button_down(ButtonCode[code].value)
    return result

def move(x=None, y=None, duration=0):
    pyvinyl.auto_delay()
    # TODO
    pyvinyl.vinyl.move(x, y)

def move_to(x=None, y=None, duration=0):
    pyvinyl.auto_delay()
    # TODO
    pyvinyl.vinyl.move_to(x, y)

def click(x=None, y=None, clicks=1, interval=0, button='Left'):
    pyvinyl.auto_delay()
    
    pyvinyl.vinyl.move_to(x, y)
    clicks_num = 0
    while(clicks_num<clicks):
        if(ButtonCode[button] == ButtonCode.Left):
            pyvinyl.vinyl.left_click()
        elif(ButtonCode[button] == ButtonCode.Right):
            pyvinyl.vinyl.right_click()
        elif(ButtonCode[button] == ButtonCode.Middle):
            pyvinyl.vinyl.middle_click()
        
        if(interval>0):
            pyvinyl.sleep(interval)
        clicks_num = clicks_num + 1


def left_double_click():
    pyvinyl.auto_delay()

    pyvinyl.vinyl.left_click()
    pyvinyl.vinyl.sleep(500)
    pyvinyl.vinyl.left_click()

def middle_double_click():
    pyvinyl.auto_delay()

    pyvinyl.vinyl.middle_click()
    pyvinyl.vinyl.sleep(500)
    pyvinyl.vinyl.middle_click()

def right_double_click():
    pyvinyl.auto_delay()

    pyvinyl.vinyl.right_click()
    pyvinyl.vinyl.sleep(500)
    pyvinyl.vinyl.right_click()


def mouse_up(x=None,y=None,button='Left'):
    pyvinyl.auto_delay()


def mouse_down(x=None,y=None,button='Left'):
    pyvinyl.auto_delay()

def scroll(delta, x=None,y=None):
    pyvinyl.auto_delay()
