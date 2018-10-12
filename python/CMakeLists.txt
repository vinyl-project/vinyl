
# copy python pyd files
 add_custom_target(PYD_GENA ALL 
 COMMAND python ${VINYL_PATH}/python/build.py ${VINYL_PATH}
 DEPENDS vinyl)
