AC_ADD_SCRIPT_LOADER("mod_gvg_core" "${CMAKE_CURRENT_LIST_DIR}/src/loader.cpp")

AC_ADD_SCRIPT("GvgCore" "${CMAKE_CURRENT_LIST_DIR}/src/GvgCore.cpp")
AC_ADD_SCRIPT("GvgCommands" "${CMAKE_CURRENT_LIST_DIR}/src/GvgCommands.cpp")
AC_ADD_SCRIPT("GvgHostility" "${CMAKE_CURRENT_LIST_DIR}/src/GvgHostility.cpp")
AC_ADD_SCRIPT("ModuleGvg" "${CMAKE_CURRENT_LIST_DIR}/src/ModuleGvg.cpp")

AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/gvg_core.conf.dist")

