//
//  TaskList.cpp
//  Task
//
//  Created by Mike Peng on 2/19/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include "TaskList.hpp"
#include <iostream>

using namespace std;

TaskList::TaskList(string tempListName)
{
    listName=tempListName;
    numTasks=0;
}
void TaskList::AddTask(string taskTitle, string taskLocation, int taskPriority)
{
    Task * p = new Task(taskTitle, taskLocation, taskPriority);
    
    for(int i=0;i<100;i++)
    {
        if(allTasks[i]!=NULL)
        {
        
          if (allTasks[i]->GetTitle() == taskTitle)
            {
             cout<<"Error, TASK is alredy presented .."<<endl;
              break;
            }
        }
   if(allTasks[i]==NULL)
   {
       allTasks[i]=p;
       numTasks++;
       break;
   }
        
   }
}
    

void TaskList::CompleteTask(string taskTitle)
{
    for(int i = 0; i<100; i++)
    {
        if(allTasks[i]!=NULL)
        {
            string returnTasks=allTasks[i]->GetTitle();
            if(returnTasks==taskTitle)
            {
                delete (allTasks[i]);
                allTasks[i]=NULL;
                numTasks --;
                break;
            }
        }
    }
    for (int n=0; n<100; n++)
    {
        if(allTasks[n]==NULL && allTasks[n+1]!=NULL)
        {
            allTasks[n]=allTasks[n+1];
            allTasks[n+1]=NULL;
        }
    }
}
void TaskList::CompleteTask(int index)
{
  if(index>=0 && index <=numTasks-1)
  {
      if(allTasks[index]!=NULL)
      {
          delete (allTasks[index]);
          allTasks[index]=NULL;
          numTasks--;
      }
      for(int n = 0; n<100; n++)
      {
          if(allTasks[n]==NULL && allTasks[n+1]!=NULL)
          {
              allTasks[n]=allTasks[n+1];
              allTasks[n+1]=NULL;
          }
      }
  }else
  {
      cout<<"Index is invalid "<<endl;
  }
    
}
void TaskList::ShowAll() const
{
    int i=0;
    cout << listName << endl;
    while(i<=numTasks-1)
    {
        if(numTasks==1)
        {
            string realDescription = allTasks[i]->Description();
            cout<<realDescription<<endl;
            break;
        }
        string realDescriptions = allTasks[i]->Description();
        cout<< i << ") " <<realDescriptions<<endl;
        i++;
        
    }
}
void TaskList::ShowByPriority(int minPriority, int maxPriority) const
{
  if(minPriority<maxPriority )
  {
      
      int Counter =0;
      string description;
      cout << listName << " by Priority from " << minPriority << " to " << maxPriority << endl;
      for(int i = 0;i<=(numTasks-1);i++)
      {
          int priority=allTasks[i]->GetPriority();
          if(priority>=minPriority && priority<=maxPriority)
          {
              description=allTasks[i]->Description();
              cout<< Counter << ") " << description<<endl;
              Counter++;
          }
          
      }
  }
}
void TaskList::ShowByLocation(string location) const
{
    int Counter = 0;
    string description;
    cout << listName << " by location of " << location << endl;
    for(int i = 0; i<=(numTasks-1); i++)
    {
        if(allTasks[i]->GetLocation()==location)
           {
               description=allTasks[i]->Description();
               cout<< Counter << ") " << description<<endl;
               Counter++;
           }
    }
}
TaskList::~TaskList()
{
    for(int i = 0; i<=(numTasks-1);i++)
    {
        delete (allTasks[i]);
        allTasks[i] = NULL;
    }
}
