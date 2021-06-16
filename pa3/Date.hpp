//
//  Date.hpp
//  project
//
//  Created by Mike Peng on 2/4/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
class Date
{
private:
    int year;
    int month;
    int day;
public:
    //constructor
    Date();
    Date(int tempYear,int tempMonth,int tempDay);
    //mutators
    void SetDate(int tempYear,int tempMonth,int tempDay);
    void DisplayNumerically();
    void DisplayTextually();

    void AdvanceOneDay() ;
    void AdvanceDays(int tempDay) ;
};

#endif /* Date_hpp */
