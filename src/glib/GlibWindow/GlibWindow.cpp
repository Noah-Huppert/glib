#include "GlibWindow.h"

#include <stdio.h>
#include "GLFW\glfw3.h"

GlibWindow::GlibWindow() {
	glfwInit();
}

GlibWindow::~GlibWindow() {
}

void GlibWindow::SayHello() {
    printf("I am saying %s", "Hello!");
}