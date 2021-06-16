//
//  TaskList.cpp
//  pa5
//
//  Created by Mike Peng on 2/27/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "TaskList.hpp"
#include "Task.hpp"
#include<iostream>
#include<string>
using namespace std;
// Constructor
// - This doesn't actually need to do anything.
TaskList :: TaskList()
{
    
}

void TaskList ::AddTask(string taskTitle, string taskLocation)
{
    Task* ptr = new Task(taskTitle,taskLocation);
    allTasks.push_back(ptr);
}

void TaskList ::CompleteTask(int taskIndex)
{
    if(taskIndex<0 || taskIndex>allTasks.size())
    {
        cout<<"error..."<<endl;
    }
    if(taskIndex>=0 && taskIndex<=allTasks.size())
    {
        if(allTasks[taskIndex]!=NULL)
        {
            if(allTasks[taskIndex]->prereqTask!=NULL)
            {
                cout<<"error,must complete the prereq "<<allTasks[taskIndex]->prereqTask->title<<endl;
            }
            else
            {
                delete allTasks[taskIndex];
                allTasks.erase(allTasks.begin()+taskIndex);
            }
        }
    }
    if(allTasks[taskIndex]==NULL)
        cout<<"error,there is no task in it"<<endl;
}
void TaskList ::AddTags(int taskIndex, string tagsToAdd[], int size)
{
    if(taskIndex<0 || taskIndex >allTasks.size())
    {
        cout<<"error..."<<endl;
    }
    if(allTasks[taskIndex]==NULL)
    {
        cout<<"error.."<<endl;
    }
    if((allTasks[taskIndex]->tags)==NULL)
    {
        (allTasks[taskIndex])->AddTags(tagsToAdd,size);
    }
}

void TaskList ::AddPrereq(int taskIndex, int prereqIndex)
{
    
    if(taskIndex<0 || taskIndex>allTasks.size())
    {
        cout<<"error..."<<endl;
    }
    else if(taskIndex == prereqIndex)
    {
        cout<<"error.."<<endl;
    }
    else
    {
        (*allTasks[taskIndex]).AddPrereq(allTasks[prereqIndex]);
    }
    
}

void TaskList ::RemovePrereq(int taskIndex)
{
    if(allTasks[taskIndex]==NULL)
    {
        cout<<"error.."<<endl;
    }
    else
    {
        allTasks[taskIndex]->prereqTask = NULL;
    }
}

void TaskList ::ShowAll() const
{
    for(int i=0;i<allTasks.size();i++)
    {
        cout<<i<<". "<<(allTasks[i])->Description()<<endl;
    }
}

void TaskList ::ShowByTag(string theTag) const
{
    
    for(int i =0; i < allTasks.size();i++)
    {
      if(allTasks[i]->tags!= NULL)
      {
        if(*allTasks[i]->tags==theTag)
      {
          cout<<(allTasks[i])->Description()<<endl;
      }
      }
    }
    
}
TaskList::~TaskList()
{
    
}
