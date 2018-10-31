import pyvinyl
import pyvinyl.vinyl
import os

def sleep(ms):
    pyvinyl.vinyl.sleep(ms)

def cmd(command):
    pyvinyl.vinyl.cmd(command)

pyvinyl.vinyl.init(os.path.dirname(__file__))