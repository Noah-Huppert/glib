#include "GlibWindow.h"
#include "GlibErrors.h"

int glib::GlibWindow::InitWindow(int width, int height, const char *title){
	//glfwSetErrorCallback(GLFWErrorCallback);

	if (!glfwInit()){
        return glib::error::FAIL;
	}

	mGLFWWindow = std::unique_ptr<GLFWwindow>(glfwCreateWindow(width, height, title, NULL, NULL));

	if (!mGLFWWindow){
		glfwTerminate();
        return glib::error::FAIL;
	}

	glfwMakeContextCurrent(mGLFWWindow.get());
	//glfwSetKeyCallback(mGLFWWindow.get(), KeyCallback);

	GLenum glewInitErr = glewInit();
	if (glewInitErr != GLEW_OK){
		fprintf(stdout, "Glew Error: %s\n", glewGetErrorString(glewInitErr));
		return glib::error::FAIL;
	}


    return glib::error::OK;
}