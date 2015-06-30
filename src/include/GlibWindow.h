#ifndef GLIB_WINDOW_H
#define GLIB_WINDOW_H

#include "GLFW/glfw3.h"

#include "GlibWindowEventHandler.h"

class GlibWindow {
public:
	GLFWwindow *mGLFWWindow;
	GlibWindowEventHandler *mGlibWindowEventHandler;

    GlibWindow(GlibWindowEventHandler *mGlibWindowEventHandler): mGlibWindowEventHandler(mGlibWindowEventHandler){}

	int InitWindow(int width, int height, const char *title);
};

#endif