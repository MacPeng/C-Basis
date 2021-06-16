//
//  PairValue.cpp
//  pa6
//
//  Created by Mike Peng on 3/5/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "PairValue.hpp"
#include <iostream>
#include <cmath>
using namespace std;

PairValue::PairValue(double x, double y)
{
    this->x = x;
    this->y = y;
}
void PairValue::Show() const
{
    cout<<"("<< x <<" , "<< y <<")"<<endl;
}
PairValue PairValue::operator+( PairValue rightSide)
{
    PairValue result = *this;
    result.x += rightSide.x;
    result.y += rightSide.y;
    return result;
}
PairValue PairValue::operator-( PairValue rightSide)
{
    PairValue result = *this;
    result.x -= rightSide.x;
    result.y -= rightSide.y;
    return result;
}
double PairValue::operator*(PairValue rightSide)
{
    PairValue result= *this;
    double temp=0;
    temp+= (result.x*rightSide.x);
    temp+= (result.y*rightSide.y);
    return temp;
}
PairValue PairValue::operator*(const double rightSide)
{
    PairValue result = *this;
    result.x *= rightSide;
    result.y *= rightSide;
    return result;
}
double PairValue::operator%( PairValue rightSide)
{
    double distance=0;
    double sum=0;
    PairValue result = *this;
    result.x -=rightSide.x;
    result.x *=result.x;
    result.y -=rightSide.y;
    result.y *=result.y;
    sum=result.x+result.y;
    distance=sqrt(sum);
    return distance;
}
PairValue PairValue::operator++()
{
    PairValue original = *this;
    double n = this->y;
    this->y = this->x;
    this->x = n * -1;
    return original;
    
}
PairValue::operator double()
{
    return (x * y);
}
ostream& operator<<(ostream& os,const PairValue &rightSide)
{
    os<<"("<<rightSide.x<<" , ";
    os<<rightSide.y<<")"<<endl;
    return os;
}
