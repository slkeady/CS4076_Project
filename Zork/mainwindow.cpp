#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Parser.h"
#include "Command.h"
#include <sstream>
#include <QString>
#include "ZorkUL.h"

ZorkUL* zork = new ZorkUL();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Type your commands here");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::parseInput(const string &input)
{
    ZorkUL* zork = ZorkUL::getZork();
    Command *command = zork->getParser()->getCommand(input);
}*/

void MainWindow::updateTextBox(string text)
{
    QString qtext = QString::fromStdString(text);
    ui->plainTextEdit->setPlainText(qtext);
}



/*void MainWindow::on_plainTextEdit_blockCountChanged(int newBlockCount)
{

}
*/

void MainWindow::on_westButton_clicked()
{
    zork->parseInput("go west");

}


void MainWindow::on_lineEdit_returnPressed()
{
    string text = ui->lineEdit->text().toStdString();
    zork->parseInput(text);
    ui->lineEdit->clear();
}

ZorkUL* getZork()
{
    return zork;
}
