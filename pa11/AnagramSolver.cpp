#include "AnagramSolver.h"
#include "LetterInventory.h"
#include <fstream>
#include <iostream>
using namespace std;

void AnagramSolver::RecursiveSolver(vector<string> & result, LetterInventory& remaining, int maxWords)
{
	if(remaining.IsEmpty()) {
		for(int i = 0; i < result.size();i++) {
			cout << result[i] << " ";
		}
		cout <<"\n";
		return;
	}

	if(maxWords != 0 && result.size() == maxWords) {
		return;
	}


    for(int i = 0; i < inventories.size(); i++ ) {

    	if(remaining.CanRemove(inventories[i])){
    		result.push_back(words[i]);
    		remaining.Remove(inventories[i]);

    		RecursiveSolver(result, remaining, maxWords);

    		remaining.Insert(inventories[i]);
    		result.pop_back();
    	}
    }

}



void AnagramSolver::GenerateAnagrams(string phrase, int maxNumWords)
{
  // Note: This method is ALREADY COMPLETE.

  LetterInventory phraseInventory(phrase);
  vector<string> words;
  RecursiveSolver(words, phraseInventory, maxNumWords);
}

AnagramSolver::AnagramSolver(string filename)
{
  // Note: This method is ALREADY COMPLETE.

  ifstream fin;
  fin.open(filename.c_str());
  if (fin.fail())
    throw string("Could not open file '") + filename + "'";

  string line;
  do
    {
      getline(fin, line);
      if (line != "")
	{
	  LetterInventory obj(line);
	  inventories.push_back(obj);
	  words.push_back(line);
	}
    }
  while (!fin.eof());
}

