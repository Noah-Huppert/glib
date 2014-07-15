//ERROR: iNCLUDING glload HEADERS IN THE SAME FILE AS glfw HEADERS CAUSES exit AND CONSTANTS LIKE gl_true AND g_falure TO BE UNDEFINED
#include "glload\gl_all.hpp"
#include "glload\gl_load.hpp"

#include "GLFW\glfw3.h"

#include <stdio.h>

static void error_callback(int error, const char* desc){
	fputs(desc, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void){
	GLFWwindow * window;
	
	glfwSetErrorCallback(error_callback);

	if (!glfwInit()){
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(640, 480, "A Window", NULL, NULL);

	if (!window){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);

	glload::LoadTest loadTest = glload::LoadFunctions();
	if (!loadTest){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	while (!glfwWindowShouldClose(window)){
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}