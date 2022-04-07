#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QTextStream>
#include "Command.h"

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
    //void parseInput(const string &input);

private slots:

    void on_westButton_clicked();

    void on_plainTextEdit_blockCountChanged(int newBlockCount);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
