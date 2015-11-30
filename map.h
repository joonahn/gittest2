#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QWidget>

class Tile;

class Map : public QWidget
{
private:
    int posX, posY;
    Tile * mapData[][];
public:
    Map(QWidget *_parent);
    moveDelta(int up_down, int right_left);
};

#endif // MAP_H

