#include <GL/glew.h>
#include "mainwindow.h"
#include "glcanvas.hpp"

void GLCanvas::initializeGL() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Error while initializing GLEW:" << glewGetErrorString(err) << std::endl;
    }
}

void GLCanvas::resizeGL(int w, int h) {
    main_window_->resize_callback(w,h);
}

void GLCanvas::wheelEvent(QWheelEvent* ev) {
    main_window_->scroll_callback(ev->delta()/120.0f);
}