CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT(glib)

SET(glib_VERSION_MAJOR 0)
SET(glib_VERSION_MINOR 0)
SET(glib_VERSION_PATCH 1)

CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/src/BuildConfig/BuildConfig.in.h" "${PROJECT_BINARY_DIR}/src/BuildConfig/BuildConfig.h")

SET(glib_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}/src")

SET(glib_SOURCE_FILES)

ADD_SUBDIRECTORY(src)

INCLUDE_DIRECTORIES("${glib_INCLUDE_DIRS}")

ADD_LIBRARY(glib STATIC ${glib_SOURCE_FILES})