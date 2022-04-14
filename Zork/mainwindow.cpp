#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "Room.h"
#include "Parser.h"
#include "CommandWords.h"
#include "Command.h"
#include <iostream>
#include <QPixmap>
#include <QMessageBox>
#include <stdlib.h>
#include <QString>

bool finished = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , command(Command("", ""))
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Type your commands here");
    zork = new ZorkUL();
    parser = new Parser();
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
    ui->textEdit->append(QString::fromStdString(text));
}



/*void MainWindow::on_plainTextEdit_blockCountChanged(int newBlockCount)
{

}
*/

void MainWindow::on_northButton_clicked()
{
    goText("north");
}

void MainWindow::on_southButton_clicked()
{
    goText("south");
}

void MainWindow::on_eastButton_clicked()
{
    goText("east");
}

void MainWindow::on_westButton_clicked()
{
   goText("west");
}


void MainWindow::on_lineEdit_returnPressed()
{
    //string text = ui->lineEdit->text().toStdString();
    //zork->parseInput(text);
    //ui->lineEdit->clear();
}

/*ZorkUL* getZork()
{
    return zork;
}
*/
void MainWindow::on_textEdit_textChanged()
{

}


void MainWindow::on_teleportButton_clicked()
{
    commandText("teleport", "");
}


void MainWindow::on_takeButton_clicked()
{

}


void MainWindow::on_quitButton_clicked()
{
    commandText("quit", "");
}

void MainWindow::on_infoButton_clicked()
{
    commandText("info", "");
}


void MainWindow::on_mapButton_clicked()
{
    commandText("map", "");
}

inline void MainWindow::goText(string direction)
{
    zork->go(direction);
    ui->textEdit->append(QString::fromStdString(zork->currentRoom->longDescription()));
    ui->textEdit->append("\n");
}

inline void MainWindow::commandText(string firstWord, string secondWord)
{
    command = Command(firstWord, secondWord);
    zork->processCommand(command);
}
