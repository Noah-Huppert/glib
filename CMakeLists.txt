cmake_minimum_required(VERSION 2.8.4)
project(glib CXX)

#Global
# -- Includes
include(ExternalProject)

# -- Vars
set(EXTERNAL_LIB_DIR ${PROJECT_BINARY_DIR}/ExternalLibs)

#GLIB
# -- Vars
set(glib_SOURCE_FILES)
set(glib_INCLUDE_DIRS)

# -- Source
add_subdirectory(src)

#GLFW
# -- Vars
set(glfw_INSTALL_DIR ${EXTERNAL_LIB_DIR}/glfw)
set(glfw_INCLUDE_DIRS ${glfw_INSTALL_DIR}/include)

set(glfw_INCLUDE_DIRS ${glfw_INCLUDE_DIRS}
    ${glfw_INSTALL_DIR}/include/GLFW)

# -- Build
externalProject_add(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.1
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${glfw_INSTALL_DIR}")

#Compile
# -- Link
# -- -- GLIB
include_directories(${glib_INCLUDE_DIRS})

# -- -- GLFW
include_directories(${glfw_INCLUDE_DIRS})

# -- Compile
add_library(glib STATIC ${glib_SOURCE_FILES})