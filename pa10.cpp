//
//  main.cpp
//  pa10
//
//  Created by Mike Peng on 4/17/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.
//

#include <iostream>
using namespace std;
bool IsPowerOfTwo(int n);
/// Determines if n is an exact positive power of 2
/// (For instance: 2, 8, 128, and 1024)
string ReplaceEsWithAs(string s);
/// Return a string that is identical to s
/// except that any 'e' is replaced with an 'a'
/// (Assume all characters are lowercase.)
int DigitSum(int n);
/// Return the SUM of all digits in n

bool IsPowerOfTwo(int n)
{
    //base case
  if(n==2)
      return true;
  
    else if(n<2)
        return false;
    //recursive step
    else
    {
       return IsPowerOfTwo(n - 2);
    }
}
string ReplaceEsWithAs(string s)
{
    //base case
  if(s == "")
  {
      return s;
  }
    else if(s.front()=='e')
    {
        s.front()='a';
        return s.front()+ReplaceEsWithAs(s.substr(1));
    }
    //recursive case
    else
    {
        return s.front()+ReplaceEsWithAs(s.substr(1));
    }
}
int DigitSum(int n)
{
    //base case
 if(n<10)
 {
     return n;
 }
    //recursive case
 else
 {
     return (n%10)+DigitSum(n/10);
 }

}
