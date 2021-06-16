#include <iostream>
#include "AnagramSolver.h"
#include "LetterInventory.h"
using namespace std;

int main()
{
  string fname;
  cout << "Enter a dictionary filename: ";
  getline(cin, fname);

  try
    {
      AnagramSolver solver(fname);
      cout << endl;
      string text;
      int maxWords;
      while (true)
	{
	  cout << "Word or phrase (blank to stop): ";
	  getline(cin, text);
	  cout << "Max words (0 = no max): ";
	  cin >> maxWords;
	  cin.ignore(1000, '\n');
	  cout << "Anagrams generated\n";
	  cout << "------------------\n";
	  solver.GenerateAnagrams(text, maxWords);
	  cout << "------------------\n";
	}
    }
  catch (string msg)
    {
      cout << "*** Error: " << msg << endl;
    }
//
//	LetterInventory lv("bogus go");
//	LetterInventory lc("guo");
//
//	lv.Remove(lc);
//	lv.Show();



}
