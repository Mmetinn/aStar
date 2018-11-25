#ifndef BOX_H
#define BOX_H

#include <QLabel>
#include "mainwindow.h"

class MainWindow;

class box:public QLabel
{
    Q_OBJECT
public:
    box(QWidget *parent=0);
    void mousePressEvent(QMouseEvent *);   
    MainWindow *anaform;
    int hangi_radio;
    int kontrol;

};

#endif // BOX_H
