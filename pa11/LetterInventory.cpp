#include "LetterInventory.h"
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

LetterInventory::LetterInventory(string data)
{
	totalCount = 0;

   transform(data.begin(),data.end(),data.begin(),::tolower);

   for(int i = 0; i < data.length();i++){
	   if(isalpha(data[i])) {
		   counts[data[i]] = count(data.begin(),data.end(),data[i]);
		   totalCount++;
	   }

   }


}

void LetterInventory::Show() const
{
  // Note: This is ALREADY COMPLETE.
  // You can call it to help you test the rest of your code,
  //  as you get different methods in the LetterInventory class working.

  for (map<char, int>::const_iterator iter = counts.begin(); iter != counts.end(); iter++)
    {
      for (int k = 1; k <= iter->second; k++)
	cout << iter->first;
      if (iter->second)
	cout << " ";
    }
  cout << "\n";
}

bool LetterInventory::IsEmpty() const
{
  return (totalCount == 0);
}

void LetterInventory::Insert(LetterInventory& other)
{
    totalCount += other.totalCount;
     for(map<char,int>::iterator iter = other.counts.begin(); iter != other.counts.end();iter++) {
    	 map<char,int>::iterator iterForCurrentCount = counts.find(iter->first);
    	 if(iterForCurrentCount != counts.end()) {
    	       iterForCurrentCount->second += iter->second;
    	 }else{
    	       counts[iter->first] = iter->second;
         }
     }

}

bool LetterInventory::CanRemove( LetterInventory& other)
{
	bool success = true;
	for(map<char,int>::iterator iter = other.counts.begin(); iter != other.counts.end();iter++) {
			 map<char,int>::iterator iterForCurrentCount = counts.find(iter->first);
			  if(iterForCurrentCount != counts.end() && (iterForCurrentCount->second - iter->second) >= 0) {
				success = true;
			  }else{
				  success =  false;
			  }

			  if(success == false) {
				  return false;
			  }

		 }
	return success;

}

void LetterInventory::Remove( LetterInventory& other)
{
	for(map<char,int>::iterator iter = other.counts.begin(); iter != other.counts.end();iter++) {
		 map<char,int>::iterator iterForCurrentCount = counts.find(iter->first);
		  if(iterForCurrentCount != counts.end() && (iterForCurrentCount->second - iter->second) >= 0) {
			  totalCount = totalCount - iter->second;
			  counts[iterForCurrentCount->first] = iterForCurrentCount->second - iter->second;
		  }else{
			  throw string("Attempt to call Remove that would yield a negative count, not possible!");
		  }
	 }



}

int LetterInventory::GetCount(){
	return totalCount;
}

