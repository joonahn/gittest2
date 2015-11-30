#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "character.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QTimer timer;
    character * me;
    QWidget * central;
};

#endif // MAINWINDOW_H
