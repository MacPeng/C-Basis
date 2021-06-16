//
//  PairValue.hpp
//  pa6
//
//  Created by Mike Peng on 3/5/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#ifndef PairValue_hpp
#define PairValue_hpp

#include <stdio.h>
#include <string>
using namespace std;

class PairValue
{
private:
    double x;
    double y;
public:
    PairValue(double x, double y);
    void Show() const;
    PairValue operator+( PairValue rightSide);
    PairValue operator-( PairValue rightSide);
    double operator*( PairValue rightSide);
    PairValue operator*(const double rightSide);
    double operator%(PairValue rightSide);
    PairValue operator++(); //++obj
    operator double();//convert to double
    friend ostream& operator<<(ostream& os,const PairValue &rightSide);
    
};







#endif /* PairValue_hpp */
