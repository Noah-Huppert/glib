#ifndef GLIB_APPLICATION_H
#define GLIB_APPLICATION_H

#include "GlibWindow.h"

class GlibApplication{
private:
    GlibWindow mGlibWindow;

public:
    GlibApplication();
    ~GlibApplication();

    int start();
    void render();

    GlibWindow glibWindow(){return mGlibWindow;}
    void glibWindow(GlibWindow glibWindow){GlibApplication::mGlibWindow = glibWindow;}
};

#endif