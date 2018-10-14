from enum import Enum
import time
import pyvinyl
import pyvinyl.vinyl

class KeyCode(Enum):
    NoneKey = 0
    Space = 32
    Apostrophe = 39
    Comma = 44
    Minus = 45
    Period = 46
    Slash = 47
    Key0 = 48
    Key1 = 49
    Key2 = 50
    Key3 = 51
    Key4 = 52
    Key5 = 53
    Key6 = 54
    Key7 = 55
    Key8 = 56
    Key9 = 57
    Semicolon = 59
    Equal = 61
    A = 65
    B = 66
    C = 67
    D = 68
    E = 69
    F = 70
    G = 71
    H = 72
    I = 73
    J = 74
    K = 75
    L = 76
    M = 77
    N = 78
    O = 79
    P = 80
    Q = 81
    R = 82
    S = 83
    T = 84
    U = 85
    V = 86
    W = 87
    X = 88
    Y = 89
    Z = 90
    LeftBracket = 91
    Backslash = 92
    RightBracket = 93
    GraveAccent = 96
    World1 = 161
    World2 = 162
    VolumeDown = 174
    VolumeUp = 176
    Escape = 256
    Enter = 257
    Tab = 258
    Backspace = 259
    Insert = 260
    Delete = 261
    ArrowRight = 262
    Right = ArrowRight
    ArrowLeft = 263
    Left = ArrowLeft
    ArrowDown = 264
    Down = ArrowDown
    ArrowUp = 265
    Up = ArrowUp
    PageUp = 266
    PageDown = 267
    Home = 268
    End = 269
    CapsLock = 280
    ScrollLock = 281
    NumLock = 282
    PrintScreen = 283
    Pause = 284
    F1 = 290
    F2 = 291
    F3 = 292
    F4 = 293
    F5 = 294
    F6 = 295
    F7 = 296
    F8 = 297
    F9 = 298
    F10 = 299
    F11 = 300
    F12 = 301
    F13 = 302
    F14 = 303
    F15 = 304
    F16 = 305
    F17 = 306
    F18 = 307
    F19 = 308
    F20 = 309
    F21 = 310
    F22 = 311
    F23 = 312
    F24 = 313
    F25 = 314
    KP_0 = 320
    KP_1 = 321
    KP_2 = 322
    KP_3 = 323
    KP_4 = 324
    KP_5 = 325
    KP_6 = 326
    KP_7 = 327
    KP_8 = 328
    KP_9 = 329
    KP_Decimal = 330
    KP_Divide = 331
    KP_Multiply = 332
    KP_Subtract = 333
    KP_Add = 334
    KP_Enter = 335
    KP_Equal = 336
    LeftShift = 340
    Shift = LeftShift
    LeftControl = 341
    Control = LeftControl
    Ctrl = LeftControl
    LeftCtrl = LeftControl
    LeftAlt = 342
    Alt = LeftAlt
    LeftSuper = 343
    Super = LeftSuper
    RightShift = 344
    RightControl = 345
    RightAlt = 346
    RightSuper = 347
    LeftMenu = 348
    Menu = LeftMenu
    RightMenu = 349

    none_key = 0
    space = 32
    apostrophe = 39
    comma = 44
    minus = 45
    period = 46
    slash = 47
    key0 = 48
    key1 = 49
    key2 = 50
    key3 = 51
    key4 = 52
    key5 = 53
    key6 = 54
    key7 = 55
    key8 = 56
    key9 = 57
    semicolon = 59
    equal = 61
    a = 65
    b = 66
    c = 67
    d = 68
    e = 69
    f = 70
    g = 71
    h = 72
    i = 73
    j = 74
    k = 75
    l = 76
    m = 77
    n = 78
    o = 79
    p = 80
    q = 81
    r = 82
    s = 83
    t = 84
    u = 85
    v = 86
    w = 87
    x = 88
    y = 89
    z = 90
    left_bracket = 91
    backslash = 92
    right_bracket = 93
    grave_accent = 96
    world1 = 161
    world2 = 162
    volume_down = 174
    volume_up = 176
    escape = 256
    enter = 257
    tab = 258
    backspace = 259
    insert = 260
    delete = 261
    arrow_right = 262
    right = arrow_right
    arrow_left = 263
    left = arrow_left
    arrow_down = 264
    down = arrow_down
    arrow_up = 265
    up = arrow_up
    page_up = 266
    page_down = 267
    home = 268
    end = 269
    caps_lock = 280
    scroll_lock = 281
    num_lock = 282
    print_screen = 283
    pause = 284
    f1 = 290
    f2 = 291
    f3 = 292
    f4 = 293
    f5 = 294
    f6 = 295
    f7 = 296
    f8 = 297
    f9 = 298
    f10 = 299
    f11 = 300
    f12 = 301
    f13 = 302
    f14 = 303
    f15 = 304
    f16 = 305
    f17 = 306
    f18 = 307
    f19 = 308
    f20 = 309
    f21 = 310
    f22 = 311
    f23 = 312
    f24 = 313
    f25 = 314
    kp_0 = 320
    kp_1 = 321
    kp_2 = 322
    kp_3 = 323
    kp_4 = 324
    kp_5 = 325
    kp_6 = 326
    kp_7 = 327
    kp_8 = 328
    kp_9 = 329
    kp_decimal = 330
    kp_divide = 331
    kp_multiply = 332
    kp_subtract = 333
    kp_add = 334
    kp_enter = 335
    kp_equal = 336
    left_shift = 340
    shift = left_shift
    left_control = 341
    control = left_control
    ctrl = left_control
    left_ctrl = left_control
    left_alt = 342
    alt = left_alt
    left_super = 343
    super = left_super
    right_shift = 344
    right_control = 345
    right_alt = 346
    right_super = 347
    left_menu = 348
    menu = left_menu
    right_menu = 349


def wait_key(code):
    while(is_key_up(code)):
        pass

def is_key_up(code):
    result = False
    if (type(code) == KeyCode):
        result = pyvinyl.vinyl.is_key_up(code.value)
    elif (type(code) == str):
        result = pyvinyl.vinyl.is_key_up(KeyCode[code].value)
    return result

def is_key_down(code):
    result = False
    if (type(code) == KeyCode):
        result = pyvinyl.vinyl.is_key_down(code.value)
    elif (type(code) == str):
        result = pyvinyl.vinyl.is_key_down(KeyCode[code].value)
    return result

def say_string(text):
    pyvinyl.auto_delay()
    pyvinyl.vinyl.say_string(text)
    

def key_down(code):
    pyvinyl.auto_delay()

    if (type(code) == KeyCode):
        pyvinyl.vinyl.key_down(code.value)
    elif (type(code) == str):
        pyvinyl.vinyl.key_down(KeyCode[code].value)
    

def key_up(code):
    pyvinyl.auto_delay()

    if (type(code) == KeyCode):
        pyvinyl.vinyl.key_up(code.value)
    elif (type(code) == str):
        pyvinyl.vinyl.key_up(KeyCode[code].value)
    

def key_press(code):
    pyvinyl.auto_delay()

    if (type(code) == KeyCode):
        pyvinyl.vinyl.key_click(code.value)
    elif (type(code) == str):
        pyvinyl.vinyl.key_click(KeyCode[code].value)

def hotkey(*args):
    pyvinyl.auto_delay()
    for key in args:
        pyvinyl.key_down(key)

    args = args[::-1]
    for key in args:
        pyvinyl.key_up(key)
    