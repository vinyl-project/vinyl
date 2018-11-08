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
	lib_hook = "vinyl-hook"
	lib_d3d11 = "vinyl-d3d11"
	lib_opengl = "vinyl-opengl"

	if (system == "Windows"):
		if(bit == "32bit"):
			lib_dir = vinyl_root + "/lib/binaries/win32_Release"
			lib_name = "vinyl.dll"
			lib_hook = "vinyl-hook.dll"
			lib_d3d11 = "vinyl-d3d11.dll"
			lib_opengl = "vinyl-opengl.dll"
		elif(bit == "64bit"):
			lib_dir = vinyl_root + "/lib/binaries/win64_Release"
			lib_name = "vinyl.dll"
			lib_hook = "vinyl-hook.dll"
			lib_d3d11 = "vinyl-d3d11.dll"
			lib_opengl = "vinyl-opengl.dll"
			print(lib_dir)
	elif (system == "Linux"):
		if(bit == "32bit"):
			lib_dir = vinyl_root + "/lib/binaries/linux32_Release"
			lib_name = "vinyl.so"
			lib_hook = "vinyl-hook.so"
			lib_d3d11 = "vinyl-d3d11.so"
			lib_opengl = "vinyl-opengl.so"
		elif(bit == "64bit"):
			lib_dir = vinyl_root + "/lib/binaries/linux64_Release"
			lib_name = "vinyl.so"
			lib_hook = "vinyl-hook.so"
			lib_d3d11 = "vinyl-d3d11.so"
			lib_opengl = "vinyl-opengl.so"
	else:
		print("Unknown system.")

	if os.path.exists(vinyl_root + "/python/pyvinyl/vinyl.pyd"):
		os.remove(vinyl_root + "/python/pyvinyl/vinyl.pyd")
		
	if os.path.exists(vinyl_root + "/python/pyvinyl/" + lib_hook):
		os.remove(vinyl_root + "/python/pyvinyl/" + lib_hook)

	if os.path.exists(vinyl_root + "/python/pyvinyl/" + lib_d3d11):
		os.remove(vinyl_root + "/python/pyvinyl/" + lib_d3d11)

	if os.path.exists(vinyl_root + "/python/pyvinyl/" + lib_opengl):
		os.remove(vinyl_root + "/python/pyvinyl/" + lib_opengl)

	if os.path.isfile(lib_dir + "/" + lib_name):
		shutil.copyfile(lib_dir + "/" + lib_name, vinyl_root + "/python/pyvinyl/vinyl.pyd")

	if os.path.isfile(lib_dir + "/" + lib_hook):
		shutil.copyfile(lib_dir + "/" + lib_hook, vinyl_root + "/python/pyvinyl/" + lib_hook)

	if os.path.isfile(lib_dir + "/" + lib_d3d11):
		shutil.copyfile(lib_dir + "/" + lib_d3d11, vinyl_root + "/python/pyvinyl/" + lib_d3d11)

	if os.path.isfile(lib_dir + "/" + lib_opengl):
		shutil.copyfile(lib_dir + "/" + lib_opengl, vinyl_root + "/python/pyvinyl/" + lib_opengl)

if __name__ == '__main__':
	main(sys.argv)