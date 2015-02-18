set(CURRENT_DIR ${PROJECT_SOURCE_DIR}/src)

set(SOURCE_FILES ${SOURCE_FILES}
    ${CURRENT_DIR}/glib/glib.h
    ${CURRENT_DIR}/glib/GlibWindow/GlibWindow.cpp
    ${CURRENT_DIR}/glib/GlibWindow/GlibWindow.h
    PARENT_SCOPE)

set(INCLUDE_DIRS ${INCLUDE_DIRS}
    ${CURRENT_DIR}
    PARENT_SCOPE)