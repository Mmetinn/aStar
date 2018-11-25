#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "box.h"
#include <QList>
#include <qmath.h>
#include <math.h>
#include <QPair>
typedef QPair<int, int> Pair;
typedef QPair<double, QPair<int, int>> pPair;
class box;

struct Point {
  int x;
  int y;
};
struct stop {
    double col, row;
    /* array of indexes of routes from this stop to neighbours in array of all routes */
    int * n;
    int n_len;
    double f, g, h;
    int from;
};
/* description of route between two nodes */
struct route {
    /* route has only one direction! */
    int x; /* index of stop in array of all stops of src of this route */
    int y; /* intex of stop in array of all stops od dst of this route */
    double d;
};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList <box*> label_list;
    int hangi_radio();
    Point bas,hed;
    QList <Point> engeller;
    void ara(int,int,Point,Point,QList<Point>);
    bool baslangic=false,hedef=false;
    char map[30][60];
    int ind[30][60];
    int map_size_rows=30;
    int map_size_cols=60;
    //void a_star(int [][]);
    //bool hedef_mi(int ,int);
    int ROW=9;
    int COL=10;
    int maliyet=0;


private slots:
    void on_hesapla_buttn_clicked(bool checked);

    void on_hesapla_buttn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
