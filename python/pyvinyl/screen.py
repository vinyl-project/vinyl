import numpy
import pyvinyl.vinyl

def screenshot(x, y, w, h):
    image = pyvinyl.vinyl.screenshot(x, y, w, h)
    return image[:,:,::-1]

def find_color(image, color):
    return numpy.all(image==color, axis = 2)
