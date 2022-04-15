#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>
#include <QDebug>

using namespace std;

class ZorkUL {
    friend class MainWindow;
private:
    vector<Room> rooms;
    Parser *parser;
    Command* command;
    bool isParsed;
    //Room *currentRoom;
	void createRooms();
	void printWelcome();
    //bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    static string outputCommand(Command command);


public:
	ZorkUL();
    void play();
    string go(string direction);
    void parseInput(const string &input);
    Room *currentRoom;
    bool processCommand(Command command);
    string getInfo();
    string getSearch();
    string getMap();
    string addItemToInv(int location);
    vector<Item> inventory;
    string getTeleport();
};

#endif /*ZORKUL_H_*/
