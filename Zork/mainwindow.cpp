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
Ui::MainWindow* uiptr;
Command* cmd;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , command(Command("", ""))
{
    uiptr = ui;
    cmd = &command;
    ui->setupUi(this);
    ui->textEdit->append("Welcome to Zork! Press buttons to get started.");
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
    ui->textEdit->append(QString::fromStdString(zork->getTeleport()));
}


void MainWindow::on_takeButton_clicked()
{
    ui->inventory->append(QString::fromStdString(zork->addItemToInv(zork->currentRoom->numberOfItems() - 1)));
}


void MainWindow::on_quitButton_clicked()
{
    qApp->exit();
}

void MainWindow::on_infoButton_clicked()
{
    ui->textEdit->append(QString::fromStdString(zork->getInfo()));
}

void MainWindow::on_searchButton_clicked()
{
    ui->textEdit->append(QString::fromStdString(zork->getSearch()));
}




void MainWindow::on_mapButton_clicked()
{
    ui->textEdit->append(QString::fromStdString(zork->getMap()));
}

inline void MainWindow::goText(string direction)
{
    zork->go(direction);
    ui->textEdit->append(QString::fromStdString(zork->currentRoom->longDescription()));
}

/*inline void MainWindow::commandText(string input)
{
    cmd = parser->getCommand(input);
    finished = zork->processCommand(command);
    if (finished == true)
    {
        ui->textEdit->append("Game over, you won!");
    }
}*/

