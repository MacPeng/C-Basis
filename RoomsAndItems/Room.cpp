#include "Room.h"
#include <iostream>
using namespace std;

// static variable definition
int Room::numRooms = 0;
string Room::directionNames[4] = { "north", "east", "south", "west" };

Room::Room(string name, string description) {
	this->name = name;
	this->description = description;
	for (int i = 0; i < 4; i++)
	{
		exits[i] = NULL;
	}
	Room::numRooms++;
	cout << "Room now built: " << Room::numRooms << endl;
}

void Room::Describe() const {
	cout << "===== " << name << " ======" << endl;
	cout << description << endl;
	if (contents.size() > 0)
	{
		cout << "You also see here:" << endl;
		for (int i = 0; i < contents.size(); i++)
		{
			cout << contents[i].name << endl;
		}
	}
	cout << "   Exits:" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (exits[i] != NULL)
		{
			cout << "   " << DirName(i) << " to the " << exits[i]->name << endl;
		}
	}
	cout << endl;
}

void Room::AddExit(Direction dir, Room* destination) {
	exits[dir] = destination;
}

Room* Room::FindExit(string text) {
	for (int i = 0; i < 4; i++)
	{
		if (text == Room::directionNames[i])
		{
			if (exits[i] != NULL)
				return exits[i];
			else
				return NULL;
		}
	}
	return NULL;
}

string Room::DirName(int n) {
	return Room::directionNames[n];
}

void Room::AddItem(Item theItem) {
	contents.push_back(theItem);
}
