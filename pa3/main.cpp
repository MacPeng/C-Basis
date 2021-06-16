//
//  main.cpp
//  project
//
//  Created by Mike Peng on 2/3/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include <iostream>
#include "Button.hpp"
#include "Date.hpp"
using namespace std;
int main()
{
    Button b;
    b.Press();
    b.Press();
    b.Press();
    cout << b.TimesPressed() << endl; // prints "3"

    Date d(2015, 4, 12);
    d.DisplayNumerically(); // prints "04/12/2015"
    d.DisplayTextually(); // prints "April 12, 2015"
    
    Date e(2015, 8, 99); // prints "Error: Date created with invalid date information."
    e.DisplayNumerically(); // prints "01/01/1900"
    e.DisplayTextually(); // prints "January 1, 1900"
    
    Date f(1980, 6, 8);
    f.DisplayNumerically(); // prints "06/08/1980"
    f.DisplayTextually(); // prints "June 8, 1980"
    
    f.SetDate(1980, 6, 31); // prints "Error: SetDate() called with invalid date information"
    f.DisplayNumerically(); // prints "06/08/1980"
    f.DisplayTextually(); // prints "June 8, 1980"
    
    Date g(2019, 1, 28);
    g.DisplayNumerically(); // prints "01/28/2019"
    g.DisplayTextually(); // prints "January 28, 2019"
    g.AdvanceOneDay();
    g.DisplayNumerically(); // prints "01/29/2019"
    g.DisplayTextually(); // prints "January 29, 2019"
    g.AdvanceDays(10);
    g.DisplayNumerically(); // prints "02/08/2019"
    g.DisplayTextually(); // prints "February 8, 2019"
    
    return 0;
    
    
    
    
}
