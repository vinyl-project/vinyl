import numpy
import pyvinyl.vinyl

def screenshot(x, y, w, h):
    image = pyvinyl.vinyl.screenshot(x, y, w, h)
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)
    return image[:,:,::-1]

def find_color(image, color):
    all_logic = numpy.all(image==color, axis = 2)
    return numpy.where(all_logic == True)
