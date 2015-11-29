#include "character.h"

character::character(QWidget *parent):QLabel(parent)
{
    this->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    this->setText("캐릭터");
    this->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    this->setGeometry(10,10,40,40);
}
