#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

enum Direction { NORTH, EAST, SOUTH, WEST };

class Room {
private:
	string name;
	string description;
	Room* exits[4];
	vector<Item> contents;

	// static member variable declaration
	static int numRooms;
	static string directionNames[4];

public:
	Room(string name, string description);
	void Describe() const;
	void AddExit(Direction dir, Room* destination);
	Room* FindExit(string text);
	void AddItem(Item theItem);

	static string DirName(int n);
};

#endif /* ROOM_H_ */
