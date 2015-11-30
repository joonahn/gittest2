#include "map.h"
#include <QRect>
#include <QPixmap>

Map::Map(QWidget *_parent) : QLabel(_parent)
{
    QPixmap pixmap(":/image/mask.png");
    this->setPixmap(pixmap);
    this->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    //this->setText("맵맵맵맵맵\n맵맵맵맵맵\n맵맵맵맵맵\n맵맵맵맵맵\n맵맵맵맵맵");
    this->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    this->setGeometry(0,0,500,300);
}

Map::moveDelta(int up_down, int right_left)
{
    QRect rct;
    rct = this->geometry();
    rct.adjust(right_left,up_down,right_left,up_down);
    this->setGeometry(rct);
}
