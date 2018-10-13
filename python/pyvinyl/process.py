import pyvinyl
import pyvinyl.vinyl
import subprocess

def sleep(t):
    pyvinyl.vinyl.sleep(t)

def cmd(command):
    subprocess.Popen(command, shell=True,
            stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if (pyvinyl.DELAY > 0):
        pyvinyl.sleep(pyvinyl.DELAY)