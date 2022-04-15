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
    Parser *parser;
    vector<Room> rooms;
    Command* command;
    void createRooms();
    void createItems();
    void displayItems();
    static string outputCommand(Command command);


public:
    ZorkUL();
    string go(string direction);
    Room *currentRoom;
    vector<Item> inventory;
    string getInfo();
    string getSearch();
    string getMap();
    string addItemToInv(int location);
    string getTeleport();
};

#endif /*ZORKUL_H_*/
