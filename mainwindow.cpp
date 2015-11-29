#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "character.h"
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
class layoutGroup : public QWidget
{
public:
    QWidget * lab[20];
    virtual void keyPressEvent(QKeyEvent * event)
    {
        QRect rct;
        switch(event->key())
        {
        case Qt::Key_W:

            rct = dynamic_cast<character*>(lab[2])->geometry();
            rct.setX(rct.x()+1);
            dynamic_cast<character*>(lab[2])->setGeometry(rct);
            break;
        case Qt::Key_S:
            rct = dynamic_cast<character*>(lab[2])->geometry();
            rct.setX(rct.x()-1);
            dynamic_cast<character*>(lab[2])->setGeometry(rct);
            break;
        default:
            event->ignore();
            break;
        }
    }

    layoutGroup()
    {

        lab[0] = new QLabel(this);
        lab[0]->setGeometry(0,0,10,10);
        dynamic_cast<QLabel*>(lab[0])->setText("asdf");
        lab[1] = new QLabel(this);
        lab[1]->setGeometry(10,10,10,10);
        dynamic_cast<QLabel*>(lab[1])->setText("2asdf");
        /*여기가 중요 */
        lab[2] = new character(this);
    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(new layoutGroup());
}

MainWindow::~MainWindow()
{
    delete ui;
}
