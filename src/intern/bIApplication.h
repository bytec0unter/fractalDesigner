#ifndef BAPPLICATION_H
#define BAPPLICATION_H

/** Qt includes */
#include <QDebug>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFramebufferObjectFormat>
#include <QtSvg>
#include <QApplication>
#include <QTableWidget>
#include <QSplitter>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QHeaderView>
#include <QTimer>





class bIApplication: public QApplication
{
public:

    /*! Called to render the hole application window.  */
    virtual void render() = 0;

protected:
    /** Called when an event from Qt was triggered. */
    virtual bool event(QEvent *event) = 0;

    /** Called when the window is resized. */
    virtual void resizeEvent(int width, int height) = 0;

private:

    QWidget mainW;
};

#endif