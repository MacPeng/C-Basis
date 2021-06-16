//
//  Task.hpp
//  Task
//
//  Created by Mike Peng on 2/18/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp
#include <string>
#include <stdio.h>
using namespace std;
class Task{
private:
    string title;
    string location;
    int priority;
public:
    //constructor
    Task(string tempTitle,string tempLocation,int tempPriority);
    
    void ChangePriority(int newPriority);
    string Description() const;
    string GetTitle() const;
    string GetLocation() const;
    int GetPriority() const;
};







#endif /* Task_hpp */
