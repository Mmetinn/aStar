#include "box.h"

box::box(QWidget *parent):
     QLabel(parent)
{
    setAcceptDrops(true);
    setFrameShape(QFrame::Box);
    show();
    kontrol = 0;

}
void box::mousePressEvent(QMouseEvent *event)
{

        setStyleSheet("QLabel { background-color : black; color : black; }");
        setText("1");

}



