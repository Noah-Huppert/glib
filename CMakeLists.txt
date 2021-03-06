cmake_minimum_required(VERSION 2.8.4)
project(glib CXX)

#Cmake Config
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}
    -std=c++11)

#Global
# -- Includes
include(ExternalProject)

# -- Vars
set(EXTERNAL_LIB_DIR ${PROJECT_BINARY_DIR}/libs)

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

# -- Build
externalProject_add(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.1
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${glfw_INSTALL_DIR}")

#GLEW
# -- Vars
set(glew_INSTALL_DIR ${EXTERNAL_LIB_DIR}/glew)

# -- Build
externalProject_add(glew
    GIT_REPOSITORY https://github.com/nigels-com/glew.git

    CONFIGURE_COMMAND make extensions

    BUILD_IN_SOURCE true
    BUILD_COMMAND make

    INSTALL_DIR ${glew_INSTALL_DIR}
    INSTALL_COMMAND sudo make install && rsync ./lib ${glew_INSTALL_DIR} && sudo make clean)


#Compile
# -- Link
# -- -- GLFW
include_directories(${glfw_INCLUDE_DIRS})

# -- -- GLIB
include_directories(${glib_INCLUDE_DIRS})

# -- Compile
add_library(glib STATIC ${glib_SOURCE_FILES} example/main.h example/main.c)
target_link_libraries(glib
    ${glfw_INSTALL_DIR}/lib/libglfw3.a
    ${glew_INSTALL_DIR}/lib/libGLEW.a)

#Install
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include
            FILES_MATCHING PATTERN glib.h)

install(TARGETS glib DESTINATION libs)