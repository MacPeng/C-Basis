
//
//  Task.cpp
//  pa5
//
//  Created by Mike Peng on 2/27/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "Task.hpp"
#include <iostream>
#include <string>
using namespace std;
// Constructor: Initializes all instance variables.
// A newly-created task has no tags and no prereq task.
Task::Task(string title, string location)
{
    this->title = title;
    this->location = location;
    this->tags = NULL;
    this->prereqTask = NULL;
    this->numTags = 0;
}
Task::Task(const Task& otherTask)
{
    this->title = otherTask.title;
    this->location = otherTask.location;
    this->numTags = otherTask.numTags;
    
    if(otherTask.tags != NULL)
    {
        this->tags = new string[numTags];
        
        for(int i = 0; i < numTags; i++)
        {
            this->tags[i] = otherTask.tags[i];
            
        }
    }
    else
    {
        this->tags = NULL;
    }
    if(otherTask.prereqTask == NULL)
    {
        this->prereqTask = NULL;
    }
    else
    {
        this->prereqTask = otherTask.prereqTask;
    }
    
}
void Task::AddTags(string tagsToAdd[], int size)
{
    if(this->tags == NULL)
    {
        this->tags = new string[size];
        
        for(int i = 0; i < size; i++)
        {
            this->tags[i] = tagsToAdd[i];
            numTags++;
        }
    }
    else
    {
        cout << "error...this task already has tags " <<endl;
    }
    
}
void Task::AddPrereq(Task * otherTask)
{
    if(this->prereqTask != NULL)
    {
        cout << "error,this task already has a prereq task" <<endl;
    }
    else
    {
        this->prereqTask = otherTask;
    }
}
void Task:: RemovePrereq()
{
    if(this->prereqTask != NULL)
    {
        delete this->prereqTask;
        this->prereqTask = NULL;
    }
    else
    {
        cout << "error,there is no prreq task in it "<<endl;
    }
}
string Task::Description() const
{
    string description = " ";
    string PreReqTask;
    
    if(this->tags == NULL)
    {
        description = "No tags";
    }
    else
    {
        for(int i =0; i < numTags; i++)
        {
         description += this->tags[i] + " " ;
        }
    }
    
    if(this->prereqTask == NULL)
    {
        PreReqTask = "No prereq tasks";
    }
    else
    {
        PreReqTask = (*prereqTask).title;
    }
    
    return "The title is " + title + "The location is " + location + "The tags are    " + description + "     " + PreReqTask + "\n\n\n";
    
}



bool Task :: HasTag(string theTag) const
{
    
        for(int i =0; i < numTags; i++)
        {
            if(*tags == theTag)
            {
                cout<<"error"<<endl;
                return false;
            }
        }
    
    return true;
}



Task::~Task()
{
    this->tags = NULL;
    this->prereqTask = NULL;
}

