CMAKE_MINIMUM_REQUIRED (VERSION 2.8.4)
PROJECT(glib)

INCLUDE(ExternalProject)

#Setup Version Information
SET(glib_VERSION_MAJOR 0)
SET(glib_VERSION_MINOR 0)
SET(glib_VERSION_PATCH 1)

CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/src/BuildConfig/BuildConfig.in.h" "${PROJECT_BINARY_DIR}/src/BuildConfig/BuildConfig.h")

#Include Source Files
SET(glib_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}/include"              #For glib/glib.h
    "${PROJECT_BINARY_DIR}/src"                  #For BuildConfig
    "${PROJECT_SOURCE_DIR}/src"                  #For all other glib includes
    "${PROJECT_BINARY_DIR}/libs/glfw/include")   #For GLFW

SET(glib_SOURCE_FILES)

ADD_SUBDIRECTORY(src)

INCLUDE_DIRECTORIES("${glib_INCLUDE_DIRS}")

#Add external dependencies
#GLFW - Window creation and OpenGl context binding
EXTERNALPROJECT_ADD(glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 3.1
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/libs/glfw"
	)

#GLEW - OpenGl loader library
IF(WIN32)
  #http://downloads.sourceforge.net/project/glew/glew/1.12.0/glew-1.12.0-win32.zip
  EXTERNALPROJECT_ADD(glew
    URL http://downloads.sourceforge.net/project/glew/glew/1.12.0/glew-1.12.0-win32.zip
    )
ELSEIF(UNIX)
  #I have 0 idea if this works
  EXTERNALPROJECT_ADD(glew
    URL http://downloads.sourceforge.net/project/glew/glew/1.12.0/glew-1.12.0.tgz
    CMAKE_ARGS "-DCMAKE_INSTAL_PREFIX=${PROJECT_BINARY_DIR}/libs/glew"
    )
ENDIF()

#Compile into Lib
ADD_LIBRARY(glib STATIC ${glib_SOURCE_FILES})
