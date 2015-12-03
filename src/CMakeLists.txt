set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

#Include
set(glib_SOURCE_FILES ${glib_SOURCE_FILES}
    ${SRC_DIR}/GlibErrors.h

    ${SRC_DIR}/GlibWindow.h
    ${SRC_DIR}/GlibWindow.cpp

    ${SRC_DIR}/GlibWindowEventHandler.h
    PARENT_SCOPE)

set(glib_INCLUDE_DIRS ${glib_INCLUDE_DIRS}
    ${SRC_DIR}
    PARENT_SCOPE)