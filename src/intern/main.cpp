#include <QApplication>
#include <QTableWidget>
#include <QSplitter>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QHeaderView>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //////////////////////////////////////////////////////////////////////////
    /// Things you can do in Qt Designer
    QWidget mainW;
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
    //////////////////////////////////////////////////////////////////////////
    QTimer::singleShot(0,vSplitter1,[vSplitter2,vSplitter1](){vSplitter1->setSizes(vSplitter2->sizes());});
    QObject::connect(vSplitter1,&QSplitter::splitterMoved,vSplitter2,[vSplitter2,vSplitter1](){vSplitter2->setSizes(vSplitter1->sizes());});
    QObject::connect(vSplitter2,&QSplitter::splitterMoved,vSplitter1,[vSplitter2,vSplitter1](){vSplitter1->setSizes(vSplitter2->sizes());});
    QObject::connect(tableRed->verticalScrollBar(),&QScrollBar::valueChanged,tableYellow->verticalScrollBar(),&QScrollBar::setValue);
    QObject::connect(tableYellow->verticalScrollBar(),&QScrollBar::valueChanged,tableRed->verticalScrollBar(),&QScrollBar::setValue);
    QObject::connect(tableRed->horizontalScrollBar(),&QScrollBar::valueChanged,tableGreen->horizontalScrollBar(),&QScrollBar::setValue);
    QObject::connect(tableGreen->horizontalScrollBar(),&QScrollBar::valueChanged,tableRed->horizontalScrollBar(),&QScrollBar::setValue);
    mainW.show();
    return a.exec();
}



