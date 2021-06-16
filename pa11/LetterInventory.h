#ifndef LETTERINVENTORY_H
#define LETTERINVENTORY_H

#include <map>
#include <string>
using namespace std;

class LetterInventory
{
 private:
  map<char, int> counts;
  int totalCount;
  
 public:
  LetterInventory(string data = "");
  bool IsEmpty() const;
  void Show() const;
  void Insert(LetterInventory& other);
  bool CanRemove( LetterInventory& other);
  void Remove( LetterInventory& other);
  int GetCount();
};

#endif
