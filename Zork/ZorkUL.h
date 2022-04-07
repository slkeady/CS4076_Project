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
	Room *currentRoom;
	void createRooms();
	void printWelcome();
    bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();

protected:
    static Parser* parser;
    static string outputCommand(Command* command);


public:
    static ZorkUL temp;
	ZorkUL();
	void play();
    string go(string direction);
    //friend void MainWindow::parseInput(const string &input);
    //static Parser getParser();
};

#endif /*ZORKUL_H_*/
