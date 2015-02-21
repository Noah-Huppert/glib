set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

#Include
set(glib_SOURCE_FILES ${glib_SOURCE_FILES}
    ${SRC_DIR}/include/glib.h
    ${SRC_DIR}/include/GlibErrors.h
    ${SRC_DIR}/include/GlibWindow.h
    ${SRC_DIR}/include/GlibWindowEventHandler.h

    ${SRC_DIR}/source/GlibWindow.cpp
    PARENT_SCOPE)

set(glib_INCLUDE_DIRS ${glib_INCLUDE_DIRS}
    ${SRC_DIR}/include
    PARENT_SCOPE)