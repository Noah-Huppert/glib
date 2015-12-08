# CMake
# -- Config
cmake_minimum_required(VERSION 3.3)
project(glib CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# -- Include
include(ExternalProject)

# GLFW
# -- Config
set(glfw_dl_PREFIX ${CMAKE_BINARY_DIR}/glfw_dl-prefix)
set(glfw_dl_SRC_DIR ${glfw_dl_PREFIX}/src/glfw_dl)
set(glfw_dl_INCLUDE_DIR ${glfw_dl_SRC_DIR}/include)

set(glib_INCLUDE_DIRS ${glib_INCLUDE_DIRS}
                      ${glfw_dl_INCLUDE_DIR})

set(glib_SOURCE_FILES ${glib_SOURCE_FILES}
                      ${glfw_dl_INCLUDE_DIR}/GLFW/glfw3.h)

# -- Build
ExternalProject_Add(glfw_dl
        PREFIX            ${glfw_dl_PREFIX}
        GIT_REPOSITORY    https://github.com/glfw/glfw.git
        GIT_TAG           3.1.2
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        )

add_subdirectory(${glfw_dl_SRC_DIR})


# glib
# -- Config
set(glib_SOURCE_FILES ${glib_SOURCE_FILES}
                      main.cpp)

# -- Build
include_directories(${glib_INCLUDE_DIRS})

add_executable(glib ${glib_SOURCE_FILES})

target_link_libraries(glib glfw ${GLFW_LIBRARIES})