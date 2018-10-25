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

    left = 0
    right = 1
    middle = 2
    mouse0 = Left
    mouse1 = Right
    mouse2 = Middle
    mouse3 = 3
    mouse4 = 4
    mouse5 = 5
    mouse6 = 6
    mouse7 = 7
    mouse8 = 8
    mouse_wheel = 9
    mouseX = 10
    mouseY = 11
    mouseZ = 12
    mouse_last = 13