#include <iostream>
#include "Room.h"
using namespace std;

void ShowItem(Item i)
{
	cout << i.name << " is worth " << i.value << endl;
}

int main() {
	Room a("Kitchen", "This is a crowded kitchen.");
	Room b("Living room", "This is a cozy living room.");
	Room c("Dining room", "A large dining room with a nice wooden table.");

	a.AddExit(EAST, &b);
	b.AddExit(WEST, &a);
	a.AddExit(SOUTH, &c);
	c.AddExit(NORTH, &a);

	Item t("toaster", 10);
	Item k("knife", 5);

	a.AddItem(t);
	a.AddItem(k);

	ShowItem(t);


	string command;
	Room* location;
	location = &a;

	while (true)
	{
		cout << endl;
		location->Describe();
		cout << "> ";
		getline(cin, command);
		if (command == "quit")
			break;
		Room* result = location->FindExit(command);
		if (result == NULL)
		{
			cout << command << " is not an available exit." << endl;
		}
		else
		{
			location = result;
		}
	}

}
