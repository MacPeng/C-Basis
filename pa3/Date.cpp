//
//  Date.cpp
//  project
//
//  Created by Mike Peng on 2/4/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "Date.hpp"
#include <iostream>
using namespace std;
Date::Date()
{
    year=2018;
    month=1;
    day=1;
}
Date::Date(int tempYear,int tempMonth,int tempDay)
{
    int DaysPerMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (tempMonth<0||tempMonth>12||tempDay<1||tempDay>DaysPerMonth[tempMonth])
    {
        cout<<"Error,please type valid month and date."<<endl;
        year=1900;
        month=1;
        day=1;
    }
    else
    {
        year=tempYear;
        month=tempMonth;
        day=tempDay;
    }
    
}
void Date::SetDate(int tempYear,int tempMonth,int tempDay)
{
    int orgYear = year;
    int orgMonth = month;
    int orgDay = day;
   int DaysPerMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (tempMonth<0||tempMonth>12||tempDay<1||tempDay>DaysPerMonth[tempMonth])
    {
        cout<<"Error,please type valid month and date."<<endl;
        year = orgYear;
        month=orgMonth;
        day=orgDay;
    }
    else
    {
        year=tempYear;
        month=tempMonth;
        day=tempDay;
    }
}
void Date::DisplayNumerically()
{
 if(month<10&&day<10)
 {
     cout<<"0"<<month<<"/"<<"0"<<day<<"/"<<year<<endl;
 }
 if(month>10&&day>10)
 {
     cout<<month<<"/"<<day<<"/"<<year<<endl;
 }
 if(month<10&&day>=10)
 {
     cout<<"0"<<month<<"/"<<day<<"/"<<year<<endl;
 }
 if(month>=10&&day<10)
 {
     cout<<month<<"/"<<"0"<<day<<"/"<<year<<endl;
     
 }
    
}
void Date::DisplayTextually()
{
   if (month==1)
   {
       cout<<"January";
   }
    if (month==2)
    {
        cout<<"February";
    }
    if (month==3)
    {
        cout<<"March";
    }
    if (month==4)
    {
        cout<<"April";
    }
    if (month==5)
    {
        cout<<"May";
    }
    if (month==6)
    {
        cout<<"June";
    }
    if (month==7)
    {
        cout<<"July";
    }
    if (month==8)
    {
        cout<<"August";
    }
    if (month==9)
    {
        cout<<"September";
    }
    if (month==10)
    {
        cout<<"October";
    }
    if (month==11)
    {
        cout<<"November";
    }
    if (month==12)
    {
        cout<<"December";
    }
    cout<<" "<<day<<" , "<<year<<endl;
}
void Date::AdvanceOneDay()
{
    //increment days by one
    day++;
    int DaysPerMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(day>DaysPerMonth[month])
    {
        day=day-DaysPerMonth[month];
        month++;
    }
    if(month>12)
    {
        month=1;
    }
}
void Date::AdvanceDays(int tempDay)
{
    //add days together
    day+=tempDay;
    int DaysPerMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(day>DaysPerMonth[month])
    {
        day=day-DaysPerMonth[month];
        month++;
    }
    if(month>12)
    {
        month=1;
    }
    
}
