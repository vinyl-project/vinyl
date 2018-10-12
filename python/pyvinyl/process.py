import subprocess

def cmd(command):
    subprocess.Popen(command, shell=True,
            stdout=subprocess.PIPE, stderr=subprocess.PIPE)