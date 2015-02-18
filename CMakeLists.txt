cmake_minimum_required(VERSION 2.8.4)
project(glib)

include(ExternalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Glib
set(SOURCE_FILES)
set(INCLUDE_DIRS)

add_subdirectory(src)

#GLFW
set(GLFW_PATH ${PROJECT_BINARY_DIR}/libs/glfw)
externalproject_add(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.1
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${GLFW_PATH}")

set(INCLUDE_DIRS ${INCLUDE_DIRS}
    ${GLFW_PATH}/include)

#Build
include_directories(${INCLUDE_DIRS})
add_library(glib STATIC ${SOURCE_FILES})