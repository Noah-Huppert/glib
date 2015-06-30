#include "GlibWindow.h"

#include "GlibErrors.h"

void GLFWErrorCallback(int error, const char* desc){

}

void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){

}

int GlibWindow::InitWindow(int width, int height, const char *title){
	glfwSetErrorCallback(GLFWErrorCallback);

	if (!glfwInit()){
		return GLIB_ERROR_GLFW_INIT_FAIL;
	}

	mGLFWWindow = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!mGLFWWindow){
		glfwTerminate();
		return GLIB_ERROR_GLFW_WINDOW_CREATE_FAIL;
	}

	glfwMakeContextCurrent(mGLFWWindow);
	glfwSetKeyCallback(mGLFWWindow, KeyCallback);

	/* GLEW NEEDS TO BE INCLUDED TO USE THIS

	GLenum glewInitErr = glewInit();
	if (glewInitErr != GLEW_OK){
		fprintf(stdout, "Glew Error: %s\n", glewGetErrorString(glewInitErr));
		return GLIB_ERROR_GLEW_INIT_FAIL;
	}
	*/

	return GLIB_ERROR_OK;
}