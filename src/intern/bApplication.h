
#ifndef BAPPLICATION_H
#define BAPPLICATION_H


/** Qt includes */
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




class bApplication : public QApplication
{
    Q_OBJECT

public:

    bApplication(int &argc, char **argv);
    ~bApplication();

    void render() const;


protected:
    bool event(QEvent *event);

    void resizeEvent(QResizeEvent *event);

private:





};


#endif