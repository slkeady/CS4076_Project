#include <iostream>
#include <vector>

using namespace std;
#include "ZorkUL.h"
#include "mainwindow.h"
#include "Parser.h"
#include "item.h"
#include <QApplication>
#include <QTextStream>
#include <QDebug>

Parser* parser;
vector<Room> rooms;
Command* command;
bool isParsed = false;
MainWindow* window;
vector<Item> inventory;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    window = &w;
    parser = new Parser();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
    qDebug() << "ZorkUL constructor";
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;

	a = new Room("a");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
	b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
	c = new Room("c");
	d = new Room("d");
	e = new Room("e");
	f = new Room("f");
	g = new Room("g");
	h = new Room("h");
	i = new Room("i");

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
	e->setExits(NULL, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);

    rooms.push_back(*a);
    rooms.push_back(*b);
    rooms.push_back(*c);
    rooms.push_back(*d);
    rooms.push_back(*e);
    rooms.push_back(*f);
    rooms.push_back(*g);
    rooms.push_back(*h);
    rooms.push_back(*i);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    qDebug() << "ZorkUL play";
	printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        //Command* command = parser->getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    window->updateTextBox("\nend\n");
    //cout << endl;
    //cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    window->updateTextBox("start\ninfo for help\n\n" + currentRoom->longDescription() + "\n");
    //cout << "start"<< endl;
    //cout << "info for help"<< endl;
    //cout << endl;
    //cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
        return 0;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
        {
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}

    else if (commandWord.compare("teleport") == 0)
    {
        string s;
        currentRoom = &rooms.at((int) rand() % rooms.size());
        window->updateTextBox(currentRoom->longDescription());
        //cout << currentRoom->longDescription() <<endl;

    }
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {

    //cout << "valid inputs are; " << endl;
    //parser->showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
        return "direction null";
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

string outputCommand(Command command)
{
    if (command.isUnknown())
    {
        return "invalid input";
    }
    else
    {
        return command.getCommandWord() + " " + command.getSecondWord() + "\n";
    }
}

void ZorkUL::parseInput(const string &input)
{
    qDebug() << "parseinput called";
    command = parser->getCommand(input);
    qDebug() << "getcommand";
    isParsed = true;
}

string ZorkUL::getInfo()
{
    return currentRoom->longDescription();
}

string ZorkUL::getSearch()
{
    return currentRoom->displayItem();
}

string ZorkUL::getMap()
{
    vector<string> map;
    string smap;

    map.push_back("[h] --- [f] --- [g]\n");
    map.push_back("         |         \n");
    map.push_back("         |         \n");
    map.push_back("[c] --- [a] --- [b]\n");
    map.push_back("         |         \n");
    map.push_back("         |         \n");
    map.push_back("[i] --- [d] --- [e]\n");

    smap = map[0] + map[1] + map[2] + map[3] + map[4] + map[5] + map[6];

    return smap;
}

string ZorkUL::addItemToInv(int location)
{
    if (currentRoom->numberOfItems() == 0)
    {
        return "";
    }
    else
    {
        string sitem = currentRoom->getItem(location).getShortDescription();
        Item item = currentRoom->getItem(location);
        inventory.push_back(item);
        currentRoom->removeItemFromRoom();
        return sitem;
    }

}

string ZorkUL::getTeleport()
{
    currentRoom = &rooms.at((int) rand() % rooms.size());
    return currentRoom->longDescription();
}
