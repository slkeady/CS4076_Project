#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "mainwindow.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ZorkUL {
private:
    vector<Room> rooms;
    Parser* parser;
	Room *currentRoom;
	void createRooms();
	void printWelcome();
    bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    static string outputCommand(Command command);
    friend void MainWindow::parseInput(const string &input);

public:
	ZorkUL();
	void play();
    string go(string direction);
    static Parser* getParser();
};

#endif /*ZORKUL_H_*/
