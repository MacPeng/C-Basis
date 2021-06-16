#ifndef ITEM_H_
#define ITEM_H_
#include <string>
using namespace std;

class Item {
private:
	string name;
	int value;
public:
	Item(string name, int value);

friend void ShowItem(Item i);
friend class Room;
};

#endif /* ITEM_H_ */
