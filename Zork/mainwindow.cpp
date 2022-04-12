#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Parser.h"
#include "Command.h"
#include <sstream>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Type your commands here");
    ui->plainTextEdit->setPlainText("Welcome to Zork!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::parseInput(const string &input)
{

    ui->plainTextEdit->setPlainText("");
}



void MainWindow::on_plainTextEdit_blockCountChanged(int newBlockCount)
{

}


void MainWindow::on_westButton_clicked()
{

}


void MainWindow::on_lineEdit_returnPressed()
{
    string text = ui->lineEdit->text().toStdString();
    parseInput(text);
    ui->lineEdit->clear();
}

