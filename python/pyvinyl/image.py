import numpy
import pyvinyl.vinyl

def find_color(image, color):
    all_logic = numpy.all(image==color, axis = 2)
    return numpy.where(all_logic == True)
