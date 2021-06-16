//
//  main.cpp
//  pa9
//
//  Created by Mike Peng on 4/6/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include <iostream>
#include <ctime>

#include <cstdlib>
#include<vector>
using namespace std;

template <typename T>
T Pick(T p1, T p2, T p3);
template <typename F>
F GetChoice(string name,string name1,F a,F b);
template<typename K>
class UniqueList
{
private:
    vector<K> items;
public:
    void Insert(K item);
    int Size() const;
    K GetFirst() const;
    K GetLast() const;
    K GetMax() const;
    K GetMin() const;
};
int main()
{
    
    cout<<GetChoice("seven","eleven",7,11);
    cout<<GetChoice("cat", "dog", "meow", "woof");
    cout<<Pick("no","like","yes");
    UniqueList<string> itemss;
    itemss.Insert("cool");
    itemss.Insert("list");
    itemss.Insert("comb");
    cout<<itemss.Size()<<endl;
    cout<<itemss.GetFirst()<<endl;
    cout<<itemss.GetLast()<<endl;
    cout<<itemss.GetMax()<<endl;
    cout<<itemss.GetMin()<<endl;
    
    
    
    return 0;
}
template <typename T>
T Pick(T p1, T p2, T p3)
{
    srand(time(0));
    int randNum=rand()%3;
    T arr[]={p1,p2,p3};
    
    cout<< randNum<<endl;
  return arr[randNum];
}
template <typename F>
F GetChoice(string name,string name1,F a,F b)
{
    while(true)
    {
        string name2;
        cout<<" Please pick "<<name<<" or "<<name1<<" ";
        getline(cin,name2);
        if(name2==name)
        {
            return a;
            break;
        }
        else if(name2==name1)
        {
            return b;
            break;
        }
    }
    return 0;
}

template<typename K>
void UniqueList<K>::Insert(K item)
{
    bool result=true;
    for(int i=0;i<items.size();i++)
    {
        if(items[i]==item)
        {
            result=false;
        }
    }
    if(result==true)
    {
        this->items.push_back(item);
    }
    else
        cout<<"error, you already have "<<item<<endl;
}
template <typename K>
int UniqueList<K>::Size() const
{
    return items.size();
}
template <typename K>
K UniqueList<K>::GetFirst() const
{
    return items[0];
}
template <typename K>
K UniqueList<K>::GetLast() const
{
    return items[items.size()-1];
}
template <typename K>
K UniqueList<K>::GetMax() const
{
    K maxScore=items[0];
    int maxIndex=0;
    for(unsigned int i=1;i<items.size();i++)
    {
        if(items[i]>maxScore)
        {
            maxScore=items[i];
            maxIndex=i;
        }
    }
    return items[maxIndex];
}
template <typename K>
K UniqueList<K>::GetMin() const
{
    K minScore=items[0];
    int minIndex=0;
    for(unsigned int i=1;i<items.size();i++)
    {
        if(items[i]<minScore)
        {
           minScore=items[i];
           minIndex=i;
        }
    }
    return items[minIndex];
}
