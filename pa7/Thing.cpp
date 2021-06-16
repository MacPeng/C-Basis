//
//  Thing.cpp
//  pa7
//
//  Created by Mike Peng on 3/15/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "Thing.hpp"
#include "Utility.hpp"
#include<string>
#include <iostream>
using namespace std;
// Constructor
Thing::Thing(string name, string description)
{
    this->name=name;
    this->description=description;
}

// Method: GetName
// This is just an accessor. It must return this item's name.
string Thing::GetName() const
{
    return this->name;
}

// Method: Describe
// Print this item's description, using the
//      Utility::PrintWrappedString() method
 void Thing::Describe() const
{
    Utility::PrintWrappedString(description);
}
