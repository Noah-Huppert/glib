#ifndef GLIB_WINDOW_H
#define GLIB_WINDOW_H

#include <memory>

#include "GLFW\glfw3.h"

class GlibWindow{
private:
	std::shared_ptr<GLFWwindow> mGLFWWindow;

public:
    GlibWindow(int width, int height, char title);
    ~GlibWindow();
};

#endif