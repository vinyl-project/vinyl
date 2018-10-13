import pyvinyl
import pyvinyl.vinyl

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