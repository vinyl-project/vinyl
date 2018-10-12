ADD_CUSTOM_TARGET(vinyl-install ALL COMMAND python ${VINYL_PATH}/python/build.py ${VINYL_PATH} DEPENDS vinyl)
SET_TARGET_PROPERTIES(vinyl-install PROPERTIES FOLDER "core")