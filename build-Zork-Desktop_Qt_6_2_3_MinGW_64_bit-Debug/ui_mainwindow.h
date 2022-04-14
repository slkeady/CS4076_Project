/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *westButton;
    QPushButton *eastButton;
    QPushButton *northButton;
    QPushButton *southButton;
    QTextEdit *textEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QScrollBar *verticalScrollBar;
    QTableWidget *tableWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *teleportButton;
    QPushButton *quitButton;
    QPushButton *takeButton;
    QPushButton *quitButton_2;
    QPushButton *infoButton;
    QPushButton *takeButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(805, 485);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(290, 10, 491, 431));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        westButton = new QPushButton(gridLayoutWidget);
        westButton->setObjectName(QString::fromUtf8("westButton"));

        gridLayout->addWidget(westButton, 1, 0, 1, 1);

        eastButton = new QPushButton(gridLayoutWidget);
        eastButton->setObjectName(QString::fromUtf8("eastButton"));

        gridLayout->addWidget(eastButton, 1, 2, 1, 1);

        northButton = new QPushButton(gridLayoutWidget);
        northButton->setObjectName(QString::fromUtf8("northButton"));

        gridLayout->addWidget(northButton, 0, 1, 1, 1);

        southButton = new QPushButton(gridLayoutWidget);
        southButton->setObjectName(QString::fromUtf8("southButton"));

        gridLayout->addWidget(southButton, 2, 1, 1, 1);

        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 1, 1, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 271, 271));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 269, 269));
        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents_2);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(246, 0, 20, 341));
        verticalScrollBar->setOrientation(Qt::Vertical);
        tableWidget = new QTableWidget(scrollAreaWidgetContents_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 20, 251, 321));
        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 251, 16));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        tableWidget->raise();
        label->raise();
        verticalScrollBar->raise();
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 420, 271, 21));
        teleportButton = new QPushButton(centralwidget);
        teleportButton->setObjectName(QString::fromUtf8("teleportButton"));
        teleportButton->setGeometry(QRect(10, 360, 81, 51));
        quitButton = new QPushButton(centralwidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(200, 360, 81, 51));
        takeButton = new QPushButton(centralwidget);
        takeButton->setObjectName(QString::fromUtf8("takeButton"));
        takeButton->setGeometry(QRect(100, 360, 91, 51));
        quitButton_2 = new QPushButton(centralwidget);
        quitButton_2->setObjectName(QString::fromUtf8("quitButton_2"));
        quitButton_2->setGeometry(QRect(200, 300, 81, 51));
        infoButton = new QPushButton(centralwidget);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setGeometry(QRect(10, 300, 81, 51));
        takeButton_2 = new QPushButton(centralwidget);
        takeButton_2->setObjectName(QString::fromUtf8("takeButton_2"));
        takeButton_2->setGeometry(QRect(100, 300, 91, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 805, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        westButton->setText(QCoreApplication::translate("MainWindow", "west", nullptr));
        eastButton->setText(QCoreApplication::translate("MainWindow", "east", nullptr));
        northButton->setText(QCoreApplication::translate("MainWindow", "north", nullptr));
        southButton->setText(QCoreApplication::translate("MainWindow", "south", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Inventory", nullptr));
        teleportButton->setText(QCoreApplication::translate("MainWindow", "Teleport", nullptr));
        quitButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        takeButton->setText(QCoreApplication::translate("MainWindow", "Take", nullptr));
        quitButton_2->setText(QCoreApplication::translate("MainWindow", "Map", nullptr));
        infoButton->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        takeButton_2->setText(QCoreApplication::translate("MainWindow", "Map", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
