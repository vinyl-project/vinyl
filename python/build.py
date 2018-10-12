import platform
import os
import shutil
import sys

def main(argv):
    system = platform.system()
    bit, _ = platform.architecture()

    vinyl_root = argv[1]

    lib_dir = vinyl_root + "/lib/binaries/"
    lib_name = "vinyl"

    if (system == "Windows"):
        if(bit == "32bit"):
            lib_dir = vinyl_root + "/lib/binaries/win32_Release"
            lib_name = "vinyl.dll"
        elif(bit == "64bit"):
            lib_dir = vinyl_root + "/lib/binaries/win64_Release"
            lib_name = "vinyl.dll"
            print(lib_dir)
    elif (system == "Linux"):
        if(bit == "32bit"):
            lib_dir = vinyl_root + "/lib/binaries/linux32_Release"
            lib_name = "vinyl.so"
        elif(bit == "64bit"):
            lib_dir = vinyl_root + "/lib/binaries/linux64_Release"
            lib_name = "vinyl.so"
    else:
        print("Unknown system.")

    if os.path.exists(vinyl_root + "/python/pyvinyl/vinyl.pyd"):
        os.remove(vinyl_root + "/python/pyvinyl/vinyl.pyd")
        
    if os.path.isfile(lib_dir + "/" + lib_name):
        shutil.copyfile(lib_dir + "/" + lib_name, vinyl_root + "/python/pyvinyl/vinyl.pyd")

if __name__ == '__main__':
    main(sys.argv)