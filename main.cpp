//
//  main.cpp
//  pa8
//
//  Created by Mike Peng on 3/30/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class MenuItem
{
private:
    string name;
    double price;
public:
    // Constructor - initialize the object from a given name and price
    MenuItem(string itemName, double itemPrice);
    
    // Constructor - initialize the object given a single text line
    //  using the syntax "itemname:price"
    MenuItem(string specification);
    void Invalidate(string param,size_t position);
    
    // Print the name and price of this menu item
    void Display() const;
    class InvalidItem
    {
    private:
        string message;
    public:
        InvalidItem(string message) { this->message = message; }
        string GetMessage() const { return message; }
        
    };
};
void ReadDataFromFile(vector<MenuItem>& Item, string fileName);
void DisplayData(const vector<MenuItem>& Item);


int main()
{
    vector<MenuItem> Item;
    string fileName;
    try
    {
        
        cout << "Enter a filename: ";
        getline(cin, fileName);
        ReadDataFromFile(Item, fileName);
        DisplayData(Item);
    }
    catch (string& message)
    {
        cout << "** Error: " << message << endl;
    }
    catch (MenuItem::InvalidItem& exception)
    {
        cout << "** Data Error: " << exception.GetMessage()<<endl;
        
    }
    
  
}



MenuItem::MenuItem(string itemName, double itemPrice)
{
   
    
    if (itemName == "" )
    {
        throw InvalidItem("error,there is no name");
    }
    else if (itemPrice <=0)
    {
        throw InvalidItem("error,this is not a real price");
    }
    else
    {
        this->name=itemName;
        this->price=itemPrice;
    }
}


MenuItem:: MenuItem(string specification)
{
    string colon=":";
    size_t found=specification.find(colon);
    if(found!=string::npos)
    {
        this->Invalidate(specification,found);
    }else{
        throw InvalidItem("error,colon is missing");
    }
   
    
        
}
void MenuItem::Invalidate(string param,size_t position)
{
    string itemName=param.substr(0,position);
    string value=param.substr(position+1);
    if(itemName=="")
    {
        throw InvalidItem("error, you should enter an item name..");
    }else{
        this->name=itemName;
    }
    try{
        double numValue=stod(value);
        if(numValue<=0)
        {
            
                throw InvalidItem("error,this is not a real price");
            
        }
        this->price=numValue;
    }catch(exception& e){
        throw InvalidItem("error, the given value is not a double value");
    }
}
   



void MenuItem::Display() const
{
    cout << "the item " << this->name << " costs " << this->price <<endl;
}

void ReadDataFromFile(vector<MenuItem>& Item, string fileName)
{
    string line;
    ifstream file;
    int lineNumber = 1;
    file.open(fileName.c_str());
    if(file.fail()) throw string("Could not open filename "+fileName);
    while(getline(file,line))
    {
        try{
            MenuItem b(line);
            Item.push_back(b);
            lineNumber++;
        }catch(MenuItem::InvalidItem& e){
            throw string("error, there is an error in line "+to_string(lineNumber)+"\n"+e.GetMessage());
        }
    }
    file.close();
   
}
void DisplayData(const vector<MenuItem>& Item){
    for(unsigned int i=0;i<Item.size();i++)
    {
        Item[i].Display();
    }
}
