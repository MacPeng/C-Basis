//
//  TaskList.hpp
//  Task
//
//  Created by Mike Peng on 2/19/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#ifndef TaskList_hpp
#define TaskList_hpp
#include <string>
#include <stdio.h>
#include "Task.hpp"
using namespace std;
class TaskList
{
private:
    string listName; // a name for the entire list
    int numTasks;  // the current number of tasks on the list
    Task* allTasks[100]={NULL}; // an array whose elements are pointers
    
public:
    //constructor
    TaskList(string tempListName);
    void AddTask(string taskTitle, string taskLocation, int taskPriority);
    void CompleteTask(string taskTitle);
    void CompleteTask(int index);
    void ShowAll() const;
    void ShowByPriority(int minPriority, int maxPriority) const;
    void ShowByLocation(string location) const;
    //destructor
    ~TaskList();

};



#endif /* TaskList_hpp */
