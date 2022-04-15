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

    a = new Room("a: Hallway: an empty room with many doors");
    b = new Room("b: Bathroom: in here you find a Toilet, a Sink, a single bottle of Conditioner and a Razor.");
        b->addItem(new Item("T", 1, 1));
        b->addItem(new Item("S", 1, 1));
        b->addItem(new Item("C", 1, 1));
        b->addItem(new Item("R", 1, 1));
    c = new Room("c: Bedroom: you find a BeD, a Lamp, and a Wardrobe");
        c->addItem(new Item("B", 1, 1));
        c->addItem(new Item("D", 1, 1));
        c->addItem(new Item("L", 1, 1));
        c->addItem(new Item("W", 1, 1));
    d = new Room("d: Living Room: an average living room leading with doors leading off to each side.");
    e = new Room("e: Kitchen: in here you find a Microwave, a Frying Pan, and a Quater of a cake.");
        e->addItem(new Item("M", 1, 1));
        e->addItem(new Item("F", 1, 1));
        e->addItem(new Item("P", 1, 1));
        e->addItem(new Item("Q", 1, 1));
    f = new Room("f: Garage: in here you find a Glass fish tank, a Heater, a Nice Jacket, and a Yoga mat.");
        f->addItem(new Item("G", 1, 1));
        f->addItem(new Item("H", 1, 1));
        f->addItem(new Item("N", 1, 1));
        f->addItem(new Item("J", 1, 1));
        f->addItem(new Item("Y", 1, 1));
    g = new Room("g: Vet Office: in here you find an Xray machine, a Zoology degree, and a Kitten.");
        g->addItem(new Item("X", 1, 1));
        g->addItem(new Item("Z", 1, 1));
        g->addItem(new Item("K", 1, 1));
    h = new Room("h: The Vowel Room: an empty void containing vowels.");
        h->addItem(new Item("A", 1, 1));
        h->addItem(new Item("E", 1, 1));
        h->addItem(new Item("I", 1, 1));
        h->addItem(new Item("O", 1, 1));
        h->addItem(new Item("U", 1, 1));
    i = new Room("i: Outside: you see a large house in front of you with many rooms.");

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

//returns room description to infoButton
string ZorkUL::getInfo()
{
    return currentRoom->longDescription();
}

//returns items to searchButton
string ZorkUL::getSearch()
{
    return currentRoom->displayItem();
}

//returns map to mapButton
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

//removes item from room and adds it to inventory
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

//teleports to a random room
string ZorkUL::getTeleport()
{
    currentRoom = &rooms.at((int) rand() % rooms.size());
    return currentRoom->longDescription();
}
