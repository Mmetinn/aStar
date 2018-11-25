/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QRadioButton *engel_radio;
    QPushButton *hesapla_buttn;
    QLabel *output;
    QPushButton *clearwall_btn;
    QPushButton *restrart_btn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(695, 393);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 81, 25));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));

        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        engel_radio = new QRadioButton(layoutWidget);
        engel_radio->setObjectName(QStringLiteral("engel_radio"));

        gridLayout->addWidget(engel_radio, 0, 1, 1, 1);

        hesapla_buttn = new QPushButton(centralWidget);
        hesapla_buttn->setObjectName(QStringLiteral("hesapla_buttn"));
        hesapla_buttn->setGeometry(QRect(90, 0, 89, 25));
        output = new QLabel(centralWidget);
        output->setObjectName(QStringLiteral("output"));
        output->setGeometry(QRect(190, 0, 251, 181));
        clearwall_btn = new QPushButton(centralWidget);
        clearwall_btn->setObjectName(QStringLiteral("clearwall_btn"));
        clearwall_btn->setGeometry(QRect(470, 0, 89, 25));
        restrart_btn = new QPushButton(centralWidget);
        restrart_btn->setObjectName(QStringLiteral("restrart_btn"));
        restrart_btn->setGeometry(QRect(570, 0, 89, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 695, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        engel_radio->setText(QApplication::translate("MainWindow", "ENGEL", Q_NULLPTR));
        hesapla_buttn->setText(QApplication::translate("MainWindow", "A*", Q_NULLPTR));
        output->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        clearwall_btn->setText(QApplication::translate("MainWindow", "clear wall", Q_NULLPTR));
        restrart_btn->setText(QApplication::translate("MainWindow", "restrart", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
