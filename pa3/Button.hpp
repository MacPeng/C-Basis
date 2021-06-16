//
//  button.hpp
//  project
//
//  Created by Mike Peng on 2/3/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#ifndef button_hpp
#define button_hpp

#include <stdio.h>
class Button
{
private:
    int pressCount; // starts at 0 by default
    
public:
    // Constructors
    Button(); // default constructor
    Button(int startCount);
    
    // Mutators
    void Press(); // increments the pressCount
    void Reset(); // resets the pressCount
    
    // Accessors
    int TimesPressed() const; // returns the value of pressCount
    bool CheckCountAbove(int n) const; // checks whether the pressCount is above n
};

#endif /* button_hpp */
