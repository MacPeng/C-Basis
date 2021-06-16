//
//  Food.cpp
//  pa7
//
//  Created by Mike Peng on 3/15/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "Food.hpp"
#include <iostream>
using namespace std;
Food::Food(string name, string description, string taste, bool isGood):Item(name,description)
{
    this->taste=taste;
    this->isGood=isGood;
}

// Accessor method: Eat
// Print "You eat the ___, which tastes ___.",
//  with the blanks filled in with the name and taste of this food.
// Then print "Yum!" or "Yuck!" depending on whether isGood is true or false.
void Food::Eat() const
{
    cout << "You eat the" << name << " which tastes " << this->taste << " ."<<endl;
    if(isGood == true) {
        cout << "YUM"<<endl;
    }else{
        cout << "YUCK!"<<endl;
    }
}

// Accessor method: Describe
// First, call the Item::Describe() method.
// Then, print "It looks delicious." or "It looks gross." depending on
//  whether isGood is true or false.
void Food::Describe() const
{
    Item::Describe();
    if(isGood == true) {
        cout << "It looks good"<<endl;
    }else{
        cout << "It looks gross"<<endl;
    }
}
