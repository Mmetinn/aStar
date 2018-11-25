#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    showMaximized();
    ui->setupUi(this);
    int X=50;
    int Y=50;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 60; ++j) {
            box *label=new box(this);

            label->setGeometry(X,Y,20,20);
            label->anaform=this;
            label->show();
            X+=20;
            label_list.push_back(label);
        }
        Y+=20;
        X=50;
    }
    label_list.first()->setStyleSheet("QLabel { background-color : red; color : red; }");
    label_list.last()->setStyleSheet("QLabel { background-color : blue; color : blue; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::hangi_radio()
{
    if(ui->engel_radio->isChecked())
        return 3;
}

void MainWindow::on_hesapla_buttn_clicked()
{
    box *lbl;
    int sayac=0;
    //engellerin olduğu yerlere 1 eklendi ve map[][]ın içine atıldı
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 60; ++j) {
            lbl=label_list.at(sayac);
           int text=lbl->text().toInt();
           if(text==1){
               map[i][j]=1;
           }else{
               map[i][j]=0;
           }
            sayac++;
        }
    }

    //ind[][]'
    memset(ind, -1, sizeof (ind));

    int i, j, k, l, b, found;
        int p_len = 0;
        int * path = NULL;
        int c_len = 0;
        int * closed = NULL;
        int o_len = 1;
        int * open = (int*)calloc(o_len, sizeof(int));
        double min, tempg;
        int s;
        int e;
        int current;
        int s_len = 0;
        struct stop * stops = NULL;
        int r_len = 0;
        struct route * routes = NULL;

        //burada stops structunun içersiini dolduruyoruz ve
        //her bir indexin numarasını ind[][]nin içersine atıyoruz.
        for (i = 1; i < map_size_rows - 1; i++) {
            for (j = 1; j < map_size_cols - 1; j++) {
                if (!map[i][j]) {
                    ++s_len;
                    stops = (struct stop *)realloc(stops, s_len * sizeof(struct stop));
                    int t = s_len - 1;
                    stops[t].col = j;
                    stops[t].row = i;
                    stops[t].from = -1;
                    stops[t].g = 100000;
                    stops[t].n_len = 0;
                    stops[t].n = NULL;
                    ind[i][j] = t;
                }
            }
        }



        // indexin startı
        s = 0;
        // indexin bitişi
        e = s_len - 1;
        //sezgisel uzaklıkları hesaplıyoruz
        for (i = 0; i < s_len; i++) {
            stops[i].h = sqrt(pow(stops[e].row - stops[i].row, 2) + pow(stops[e].col - stops[i].col, 2));
        }

        for (i = 1; i < map_size_rows - 1; i++) {
            for (j = 1; j < map_size_cols - 1; j++) {
                if (ind[i][j] >= 0) {
                    for (k = i - 1; k <= i + 1; k++) {
                        for (l = j - 1; l <= j + 1; l++) {
                            /*if ((k == i) and (l == j)) {
                                continue;
                            }*/
                            if (ind[k][l] >= 0) {
                                ++r_len;
                                routes = (struct route *)realloc(routes, r_len * sizeof(struct route));
                                int t = r_len - 1;
                                routes[t].x = ind[i][j];
                                routes[t].y = ind[k][l];
                                routes[t].d = sqrt(pow(stops[routes[t].y].row - stops[routes[t].x].row, 2) + pow(stops[routes[t].y].col - stops[routes[t].x].col, 2));
                                ++stops[routes[t].x].n_len;
                                stops[routes[t].x].n = (int*)realloc(stops[routes[t].x].n, stops[routes[t].x].n_len * sizeof(int));
                                stops[routes[t].x].n[stops[routes[t].x].n_len - 1] = t;                                
                            }
                        }
                    }
                }
            }
        }

        //başlangıç noktasını opendan başlatıyoruz
        open[0] = s;
        //stopun içerisine de F=G+H denklemini
        stops[s].g = 0;
        stops[s].f = stops[s].g + stops[s].h;
        found = 0;

        while (o_len && !found) {
            min = 100000;
            for (i = 0; i < o_len; i++) {
                /*
                 *Şu an durduğum nodun f'i küçükse minden
                 * currenti open isine mini de stopbun fine eşitle
                 * 63.071388124885914=0+63.071388124885914
                 * f=g+h
                */
                if (stops[open[i]].f < min) {
                    current = open[i];
                    min = stops[open[i]].f;
                }
            }
            //konumum son indexe işitse gir
            if (current == e) {
                found = 1;

                ++p_len;
                path = (int*)realloc(path, p_len * sizeof(int));
                path[p_len - 1] = current;
                while (stops[current].from >= 0) {
                    current = stops[current].from;
                    ++p_len;
                    path = (int*)realloc(path, p_len * sizeof(int));
                    path[p_len - 1] = current;
                }
            }

            for (i = 0; i < o_len; i++) {
                //eğer şu ankş konumum başlangıç konumu ise
                if (open[i] == current) {
                    if (i != (o_len - 1)) {
                        for (j = i; j < (o_len - 1); j++) {
                            open[j] = open[j + 1];
                        }
                    }
                    --o_len;
                    open = (int*)realloc(open, o_len * sizeof(int));
                    break;
                }
            }

            ++c_len;
            closed = (int*)realloc(closed, c_len * sizeof(int));
            closed[c_len - 1] = current;

            for (i = 0; i < stops[current].n_len; i++) {
                b = 0;

                for (j = 0; j < c_len; j++) {
                    if (routes[stops[current].n[i]].y == closed[j]) {
                        b = 1;                     
                    }
                }

                if (b) {
                    continue;
                }

                tempg = stops[current].g + routes[stops[current].n[i]].d;

                b = 1;

                if (o_len > 0) {
                    for (j = 0; j < o_len; j++) {
                        if (routes[stops[current].n[i]].y == open[j]) {
                            b = 0;
                        }
                    }
                }

                if (b or (tempg < stops[routes[stops[current].n[i]].y].g)) {
                    stops[routes[stops[current].n[i]].y].from = current;
                    stops[routes[stops[current].n[i]].y].g = tempg;
                    stops[routes[stops[current].n[i]].y].f = stops[routes[stops[current].n[i]].y].g + stops[routes[stops[current].n[i]].y].h;

                    if (b) {
                        ++o_len;
                        open = (int*)realloc(open, o_len * sizeof(int));
                        open[o_len - 1] = routes[stops[current].n[i]].y;
                    }
                }
            }
        }

        for (i = 0; i < map_size_rows; i++) {
            for (j = 0; j < map_size_cols; j++) {
                if (map[i][j]) {
                    putchar(0xdb);
                } else {
                    b = 0;
                    for (k = 0; k < p_len; k++) {
                        if (ind[i][j] == path[k]) {
                            ++b;
                        }
                    }
                    if (b) {
                        int boyanacak=i*60;
                        boyanacak+=j;
                        label_list.at(boyanacak)
                                ->setStyleSheet("QLabel "
                                "{ background-color : pink; "
                                "color : white; }");
                        maliyet+=10;
                        //putchar('x');

                    } else {
                        putchar('.');
                    }
                }
            }
            putchar('\n');
        }
        /*if (not found) {
           ui->output->setText("Yol Kapalı");
        }else{
            ui->output->setText("Başarılı");
        }*/


}
