#ifndef GLIB_WINDOW_EVENT_HANDLER_H
#define GLIB_WINDOW_EVENT_HANDLER_H

#include "GLFW/glfw3.h"

namespace glib {
class GlibWindowEventHandler {
public:
    virtual void GLFWErrorCallback(int error, const char *desc) = 0;

    virtual void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;
};
}

#endif