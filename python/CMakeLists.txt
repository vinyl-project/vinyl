
# copy python pyd files
set(PYD_LIST ${VINYL_PATH}/python/pyvinyl/vinyl.pyd)
add_custom_command(OUTPUT ${PYD_LIST}
  COMMAND python ${VINYL_PATH}/python/build.py ${VINYL_PATH}
 )

 add_custom_target(PYD_GENA ALL DEPENDS ${PYD_LIST})
