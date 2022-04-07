#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "Parser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::parseInput(const string &input)
{
    Command *command = ZorkUL::getParser()->getCommand(input);

    string inputString = "> " + input + "\n\n";

    string output = ZorkUL::outputCommand(*command);
}


void MainWindow::on_plainTextEdit_blockCountChanged(int newBlockCount)
{

}


void MainWindow::on_westButton_clicked()
{
    parseInput("go west");
}

