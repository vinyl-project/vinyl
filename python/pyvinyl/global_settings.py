
import pyvinyl

DELAY = 0

def auto_delay():
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)