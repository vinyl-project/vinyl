ADD_CUSTOM_TARGET(vinyl-install ALL COMMAND python ${VINYL_PATH}/python/build.py ${VINYL_PATH} DEPENDS vinyl vinyl-d3d11 vinyl-opengl)
SET_TARGET_PROPERTIES(vinyl-install PROPERTIES FOLDER "install")