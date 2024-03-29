/** include python */
#define PY_SSIZE_T_CLEAN
#include <Python.h>



#include <QApplication>
#include <QSurfaceFormat>
#include <QScreen>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "glwidget.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("Qt Hello GL 2 Example");
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption multipleSampleOption("multisample", "Multisampling");
    parser.addOption(multipleSampleOption);
    QCommandLineOption coreProfileOption("coreprofile", "Use core profile");
    parser.addOption(coreProfileOption);
    QCommandLineOption transparentOption("transparent", "Transparent window");
    parser.addOption(transparentOption);

    parser.process(app);

    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    if (parser.isSet(multipleSampleOption))
        fmt.setSamples(4);
    if (parser.isSet(coreProfileOption)) {
        fmt.setVersion(3, 2);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
    }
    QSurfaceFormat::setDefaultFormat(fmt);

    MainWindow mainWindow;

    GLWidget::setTransparent(parser.isSet(transparentOption));
    if (GLWidget::isTransparent()) {
        mainWindow.setAttribute(Qt::WA_TranslucentBackground);
        mainWindow.setAttribute(Qt::WA_NoSystemBackground, false);
    }
    mainWindow.resize(mainWindow.sizeHint());
    int desktopArea = QGuiApplication::primaryScreen()->size().width() *
                      QGuiApplication::primaryScreen()->size().height();
    int widgetArea = mainWindow.width() * mainWindow.height();
    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        mainWindow.show();
    else
        mainWindow.showMaximized();
    return app.exec();
}












/**
int main(int argc, char *argv[])
{
    bApplication *bApplication = new bApplication(argc, argv);

    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program);  
    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n");


    QApplication a(argc, argv);
    //////////////////////////////////////////////////////////////////////////
    /// Things you can do in Qt Designer
    QWidget mainW;


    QOpenGLWidget *gl = new QOpenGLWidget(&mainW, Qt::Widget);

    QSplitter *hSplitter = new QSplitter(Qt::Horizontal,&mainW);
    QSplitter *vSplitter1 = new QSplitter(Qt::Vertical,&mainW);
    QSplitter *vSplitter2 = new QSplitter(Qt::Vertical,&mainW);
    QTableWidget *tableRed = new QTableWidget(6,6,&mainW);
    tableRed->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableRed->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableRed->verticalHeader()->hide();
    tableRed->horizontalHeader()->hide();

    QTableWidget *tableGreen = new QTableWidget(1,6,&mainW);
    tableGreen->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableGreen->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableGreen->verticalHeader()->hide();
    tableGreen->horizontalHeader()->hide();

    QTableWidget *tableYellow = new QTableWidget(6,2,&mainW);
    tableYellow->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableYellow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableYellow->verticalHeader()->hide();
    tableYellow->horizontalHeader()->hide();


    QWidget *topLeft = new QWidget(&mainW);
    vSplitter1->addWidget(topLeft);
    vSplitter1->addWidget(tableYellow);
    vSplitter2->addWidget(tableGreen);
    vSplitter2->addWidget(tableRed);
    hSplitter->addWidget(vSplitter1);
    hSplitter->addWidget(vSplitter2);
    QHBoxLayout *mainLay = new QHBoxLayout(&mainW);
    mainLay->addWidget(hSplitter);

    QTimer::singleShot(0,vSplitter1,[vSplitter2,vSplitter1](){vSplitter1->setSizes(vSplitter2->sizes());});
    QObject::connect(vSplitter1,&QSplitter::splitterMoved,vSplitter2,[vSplitter2,vSplitter1](){vSplitter2->setSizes(vSplitter1->sizes());});
    QObject::connect(vSplitter2,&QSplitter::splitterMoved,vSplitter1,[vSplitter2,vSplitter1](){vSplitter1->setSizes(vSplitter2->sizes());});
    QObject::connect(tableRed->verticalScrollBar(),&QScrollBar::valueChanged,tableYellow->verticalScrollBar(),&QScrollBar::setValue);
    QObject::connect(tableYellow->verticalScrollBar(),&QScrollBar::valueChanged,tableRed->verticalScrollBar(),&QScrollBar::setValue);
    QObject::connect(tableRed->horizontalScrollBar(),&QScrollBar::valueChanged,tableGreen->horizontalScrollBar(),&QScrollBar::setValue);
    QObject::connect(tableGreen->horizontalScrollBar(),&QScrollBar::valueChanged,tableRed->horizontalScrollBar(),&QScrollBar::setValue);
    mainW.show();

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);


    return a.exec();
    */

