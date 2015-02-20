#include "GlibWindow.h"

GlibWindow::GlibWindow(int width, int height, char title):
	mGLFWWindow((width, height, title, NULL, NULL)){
}

GlibWindow::~GlibWindow() {
}