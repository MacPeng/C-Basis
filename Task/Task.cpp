//
//  Task.cpp
//  Task
//
//  Created by Mike Peng on 2/18/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "Task.hpp"
#include <iostream>
using namespace std;

Task::Task(string tempTitle,string tempLocation,int tempPriority)
{
    title=tempTitle;
    location=tempLocation;
    priority=tempPriority;
    if(tempPriority<1)
    {
        priority=1;
    }
    if(tempPriority>5)
    {
        priority=5;
    }
}

void Task::ChangePriority(int newPriority)
{
    priority=newPriority;
    if(newPriority<1)
    {
        priority=1;
    }
    if(newPriority>5)
    {
        priority=5;
    }
}
string Task::Description() const
{
    string description;
    description+="[";
    description+=location;
    description+="] ";
    description+=title;
    switch(priority)
    {
        case 1:
            description+=" *";
            break;
        case 2:
            description+=" **";
            break;
        case 3:
            description+=" ***";
            break;
        case 4:
            description+=" ****";
            break;
        case 5:
            description+=" *****";
            break;
            
    }
    return description;
}
string Task::GetTitle() const
{
    return title;
}
string Task::GetLocation() const
{
    return location;
}
int Task::GetPriority() const
{
    return priority;
}

