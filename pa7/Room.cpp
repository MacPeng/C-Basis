//
//  Room.cpp
//  pa7
//
//  Created by Mike Peng on 3/15/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "Room.hpp"
#include "Item.hpp"
#include "Food.hpp"
#include "Utility.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Constructor
Room::Room(string name, string description)
{
    this->name=name;
    this->description=description;
}

// Accessor method: Describe
// (1) Print the location's name in ALL CAPS (i.e converted to uppercase)
// (2) Print The location's description, using the
//      Utility::PrintWrappedString() method
// (3) Call ListContents()
void Room::Describe() const
{
    Utility::PrintWrappedString(description);
    this->ListContents();
}

// Method: AddThing
// Add the given pointer to the end of the contents vector
// You may assume the pointer already points to a valid  object.
void Room::AddThing(Thing* thingPtr)
{
    this->contents.push_back(thingPtr);
}

// Method: ExamineThing
// This has one parameter, representing the NAME of a thing
//   that may be in this location.
// It should respond one of two ways:
// (a) If there is no thing with the given name, print "There is no ___ here.",
//       with the ___ replaced by the parameter value.
// (b) If there is a matching item, call that item's Describe() method.
void Room::ExamineThing(string thingName) const
{
    bool get = false;
    for(int i =0; i < this->contents.size();i++)
    {
        if(contents[i]->GetName() == thingName)
        {
            get = true;
            contents[i]->Describe();
            break;
        }
    }
    if(get == false) {
        cout << "There is no "<< thingName << " here. "<<endl;
    }
}

// Method: TakeThing
// This has one parameter, representing the NAME of a thing
//   that may be in this location.
// It should respond one of three ways:
// (a) If there is no thing with the given name, print "There is no ___ here.",
//       with the ___ replaced by the parameter value.
// (b) If there is a matching thing, but it is not an Item,
//       print "The __ cannot be picked up."
// (c) If there is a matching thing and it is an Item,
//       call that object's Take method.
void Room::TakeThing(string thingName) const
{
    bool get = false;
    for(int i = 0; i < this->contents.size();i++) {
        if(contents[i]->GetName() == thingName) {
            get = true;
            Item* possibleItemPtr = dynamic_cast<Item*>(contents[i]);
            Food* possibleFoodPtr = dynamic_cast<Food*>(contents[i]);
            if(possibleItemPtr != NULL){
                possibleItemPtr->Take();
                break;
            }else if (possibleFoodPtr != NULL){
                possibleFoodPtr->Take();
                break;
            }else{
                cout << "This " << thingName << " cannot be picked up"<<endl;
            }
        }
    }
    if(get == false){
        cout << "There is no "<<thingName<<" here."<<endl;
    }
}

// Method: DropThing
// This has one parameter, representing the NAME of a thing
//   that may be in this location.
// It should respond one of three ways:
// (a) If there is no thing with the given name, print "There is no ___ here.",
//       with the ___ replaced by the parameter value.
// (b) If there is a matching thing, but it is not an Item,
//       print "The __ cannot be dropped."
// (c) If there is a matching thing and it is an Item,
//       call that object's Drop method.
void Room::DropThing(string thingName) const
{
    bool get = false;
    for(int i = 0; i < this->contents.size();i++) {
        if(contents[i]->GetName() == thingName) {
            get = true;
            Item* possibleItemPtr = dynamic_cast<Item*>(contents[i]);
            Food* possibleFoodPtr = dynamic_cast<Food*>(contents[i]);
            if(possibleItemPtr != NULL){
                possibleItemPtr->Drop();
                break;
            }else if (possibleFoodPtr != NULL){
                possibleFoodPtr->Drop();
                break;
            }else{
                cout << "This " << thingName << " cannot be dropped up"<<endl;
            }
        }
    }
    if(get == false){
        cout << "There is no "<<thingName<<" here."<<endl;
    }
    
}

// Method: EatThing
// This has one parameter, representing the NAME of a thing
//   that may be in this location.
// It should respond in one of three ways:
// (a) If there is no thing with the given name, print "There is no ___ here."
// (b) If there is a matching thing but it is not a Food,
//       print "The ___ is not edible."
// (c) If there is a matching thing and it is a Food,
//       call that food's Eat() method,
//       then remove the corresponding entry from the contents vector.
void Room::EatThing(string thingName)
{
    bool get = false;
    for(int i = 0; i < this->contents.size();i++) {
        if(contents[i]->GetName() == thingName) {
            get = true;
            Food* possibleFoodPtr = dynamic_cast<Food*>(contents[i]);
            if (possibleFoodPtr != NULL){
                possibleFoodPtr->Eat();
                this->contents[i] = NULL;
                break;
            }else{
                cout << "This " << thingName << " is not edible"<<endl;
            }
        }
    }
    if(get == false){
        cout << "There is no "<<thingName<<" here."<<endl;
    }
    
    for(int i = 0; i < contents.size();i++) {
        if(contents[i] == NULL && contents[i++] != NULL && (i+1)<contents.size()){
            Thing* copy = contents[i];
            contents[i] = contents[i+1];
            contents[i+1] = copy;
        }
        
    }
}
// Helper method: FindThing
// This has one parameter, representing the NAME of a thing
//   that may be in this location.
// If something in the contents array has the given name, return the index of that element.
// Otherwise, return -1.
int Room::FindThing(string thingName) const
{
    int get = -1;
    
    for(int i = 0; i < contents.size();i++) {
        if(contents[i]->GetName() == thingName) {
            get = 0;
            break;
        }
    }
    return get;
}

// Helper method: ListContents
// Loop through all elements (if any) of the contents vector.
// For each element:
//  - Check if the corresponding object is an Item or not. (Hint: Use dynamic_cast<>)
//  - If it is an Item, also check if it is pickedUp
// Using additional temporary vectors as needed, prints the following output:
// (a) A message in the form "In this room you see __ thing(s):"
//       - Replace __ with the total number of Thing objects in the room
//       - Do not print this at all if the number of objects is 0
// (b) The names of all Thing objects in the room, one per line.
// (c) A message in the form "You are holding:"
//       - Do not print this at all if the number of pickedUp items is 0
// (d) The names of all Item objects in the room that are pickedUp, one per line.
void Room::ListContents() const
{
    int count=0;
    int k = 0;
    vector<Item*> PickUp;
    if(contents.size() > 0) {
        for(unsigned int i = 0; i < contents.size();i++) { //findingNumOfItems
            Item* possibleItemPtr = dynamic_cast<Item*>(contents[i]);
            if(possibleItemPtr != NULL){
                if(possibleItemPtr->IsPickedUp() == false) {
                    count++;
                }else{
                    PickUp.push_back(possibleItemPtr);
                    k++;
                }
            }
            
        }
}
 if(count>0)
 {
     cout<<"In the room, you see "<<contents.size()<<"things."<<endl;
     for(unsigned int n=0;n<contents.size();n++)
     {
         cout<<contents[n]->GetName()<<endl;
     }
 }
    if(k>0)
    {
        cout<<"You are holding: "<<endl;
        for(unsigned int m=0;m<PickUp.size();m++)
        {
            cout<<PickUp[m]->GetName()<<endl;
        }
    }
}
