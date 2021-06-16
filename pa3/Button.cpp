//
//  button.cpp
//  project
//
//  Created by Mike Peng on 2/3/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "Button.hpp"
#include <iostream>
using namespace std;

Button::Button()
{
    cout<<"Default constructor running."<<endl;
    pressCount=0;
}
Button::Button(int startCount)
{
    pressCount=startCount;
}


void Button::Press()
{
    //count press
    pressCount++;
    
}// increments the pressCount
void Button:: Reset()
{
    pressCount=0;
}// resets the pressCount

// Accessors
int Button::TimesPressed() const
{
    return pressCount;
}
bool Button::CheckCountAbove(int n) const
{
  if(pressCount>n)
  {
      return true;
  }
    else
        return false;
}
