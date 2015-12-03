#ifndef GLIB_WINDOW_H
#define GLIB_WINDOW_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <memory>
#include "GlibWindowEventHandler.h"

class GLFWwindow{
public:
    ~GLFWwindow(){}
};

namespace glib {
class GlibWindow {
public:
    std::unique_ptr<GLFWwindow> mGLFWWindow;
    std::unique_ptr<GlibWindowEventHandler> mGlibWindowEventHandler;

    int InitWindow(int width, int height, const char *title);
private:
    GLFWerrorfun GLFWErrorCallback;
    GLFWkeyfun KeyCallback;
};
}

#endif