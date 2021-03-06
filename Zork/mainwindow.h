#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ZorkUL.h"
#include "Parser.h"
#include <QMainWindow>
#include <QTextStream>
#include <sstream>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using std::string;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ZorkUL* zork;
    void updateTextBox(string text);
    Parser* parser;
    Ui::MainWindow* uiptr;
    Command* cmd;

private slots:
    void on_westButton_clicked();

    void on_northButton_clicked();

    void on_eastButton_clicked();

    void on_southButton_clicked();

    void on_teleportButton_clicked();

    void on_takeButton_clicked();

    void on_quitButton_clicked();

    void on_infoButton_clicked();

    void on_mapButton_clicked();

    void on_searchButton_clicked();

    void on_wordleButton_clicked();

private:
    Ui::MainWindow *ui;
    Command command;
    bool finished;
    void goText(string direction);
    //void commandText(string input);
};
#endif // MAINWINDOW_H
