#include "character.h"
#include <QPixmap>

character::character(QWidget *parent):QLabel(parent)
{
    QPixmap pixmap(":/image/prof.png");
    this->setPixmap(pixmap);
    //this->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    //this->setText("캐릭터");
    //this->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    this->setGeometry(0,0,301,555);
}
