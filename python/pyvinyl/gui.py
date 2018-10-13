import pyvinyl
import pyvinyl.vinyl


def message_box(content):
    pyvinyl.vinyl.message_box(content)
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)

