#ifndef GLIB_WINDOW_H
#define GLIB_WINDOW_H

#include <functional>
#include <memory>
#include "GLFW\glfw3.h"

#include "GlibWindowEventHandler.h"

class GlibWindow {
public:
	std::shared_ptr<GLFWwindow> mGLFWWindow;
	std::shared_ptr<GlibWindowEventHandler> mGlibWindowEventHandler;

	int InitWindow(int width, int height, const char *title);
};

#endif