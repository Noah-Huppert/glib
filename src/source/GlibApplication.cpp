#include <stdio.h>

#include "GLFW\glfw3.h"

#include "GlibApplication.h"
#include "GlibErrors.h"

GlibApplication::GlibApplication(): mGlibWindow() {
}

GlibApplication::~GlibApplication() {}

void glfw_error_callback(int error, const char *desc) {
    printf("GLFW Error: %s[%i]", desc, error);
}

int GlibApplication::start() {
    //Init GLFW context
	glfwSetErrorCallback(glfw_error_callback);

	if (!glfwInit()){
		return GLIB_GLFW_INIT_FAIL;
	}
}

void GlibApplication::render() {

}