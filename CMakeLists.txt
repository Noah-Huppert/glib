cmake_minimum_required(VERSION 2.8.4)
project(glib)

include(ExternalProject)

#Global
set(SOURCE_FILES)
set(INCLUDE_DIRS)

set(EXTERNAL_LIB_PATH ${PROJECT_BINARY_DIR}/libs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Glib
add_subdirectory(src)

#GLFW
set(GLFW_PATH ${EXTERNAL_LIB_PATH}/glfw)

externalproject_add(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.1
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${GLFW_PATH}")

set(INCLUDE_DIRS ${INCLUDE_DIRS}
    ${GLFW_PATH}/include)

#Build
set(GLIB_LIB_DIR ${PROJECT_BINARY_DIR}/libs/glib)

set(ARCHIVE_OUTPUT_DIRECTORY ${GLIB_LIB_DIR})

include_directories(${INCLUDE_DIRS})
add_library(glib STATIC ${SOURCE_FILES})

set_target_properties(glib PROPERTIES
         ARCHIVE_OUTPUT_DIRECTORY ${GLIB_LIB_DIR})

#Install
# -- GLFW
install(DIRECTORY ${GLFW_PATH}
        DESTINATION ./)

# -- glib
install(DIRECTORY ${GLIB_LIB_DIR}
        DESTINATION ./)

install(DIRECTORY src/
        DESTINATION glib/include
        FILES_MATCHING PATTERN "**/*.h")