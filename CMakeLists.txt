CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT(glib)

#Setup Version Information
SET(glib_VERSION_MAJOR 0)
SET(glib_VERSION_MINOR 0)
SET(glib_VERSION_PATCH 1)

CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/src/BuildConfig/BuildConfig.in.h" "${PROJECT_BINARY_DIR}/src/BuildConfig/BuildConfig.h")

#Include Source Files
SET(glib_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}/src")

SET(glib_SOURCE_FILES)

ADD_SUBDIRECTORY(src)

INCLUDE_DIRECTORIES("${glib_INCLUDE_DIRS}")

#Add external dependencies
INCLUDE(ExternalProject)

SET(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/libs/glfw" glfw)

EXTERNALPROJECT_ADD(glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 3.1
	#BINARY_DIR "${PROJECT_BINARY_DIR}/libs/glfw"
	INSTALL_DIR "${PROJECT_BINARY_DIR}/libs/glfw"
	)

SET_TARGET_PROPERTIES(glfw PROPERTIES CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/libs/glfw")

IF(WIN32)

ELSEIF(UNIX)

ENDIF()

#Compile into Lib
ADD_LIBRARY(glib STATIC ${glib_SOURCE_FILES})
