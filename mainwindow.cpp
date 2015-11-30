#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "character.h"
#include "map.h"
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
class layoutGroup : public QWidget
{
public:
    QWidget * lab[20];
    void keyPressed(QKeyEvent * event)
    {
        QRect rct;
        switch(event->key())
        {
        case Qt::Key_W:

            rct = dynamic_cast<character*>(lab[2])->geometry();
            rct.adjust(1,0,1,0);
            dynamic_cast<character*>(lab[2])->setGeometry(rct);
            break;
        case Qt::Key_S:
            rct = dynamic_cast<character*>(lab[2])->geometry();
            rct.adjust(-1,0,-1,0);
            dynamic_cast<character*>(lab[2])->setGeometry(rct);
            break;
        default:
            event->ignore();
            break;
        }
    }

    void keyPressed_Map(QKeyEvent * event)
    {
        switch(event->key())
        {
        case Qt::Key_Left:
        case Qt::Key_A:
            dynamic_cast<Map*>(lab[3])->moveDelta(0,-1);
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            dynamic_cast<Map*>(lab[3])->moveDelta(0,1);
            break;
        case Qt::Key_Up:
        case Qt::Key_W:
            dynamic_cast<Map*>(lab[3])->moveDelta(-1,0);
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            dynamic_cast<Map*>(lab[3])->moveDelta(1,0);
            break;
        default:
            event->ignore();
            break;
        }
    }

    layoutGroup()
    {
        this->setFocusPolicy(Qt::StrongFocus);
        lab[0] = new QLabel(this);
        lab[0]->setGeometry(0,0,10,10);
        dynamic_cast<QLabel*>(lab[0])->setText("asdf");
        lab[1] = new QLabel(this);
        lab[1]->setGeometry(10,10,10,10);
        dynamic_cast<QLabel*>(lab[1])->setText("2asdf");
        /*여기가 중요 */
        lab[2] = new character(this);
        lab[3] = new Map(this);

    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    central = new layoutGroup();
    this->setCentralWidget(central);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug("keyPressEvent(%x)", event->key());
    dynamic_cast<layoutGroup *>(central)->keyPressed_Map(event);
}
