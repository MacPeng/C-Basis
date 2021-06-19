
//  main.cpp
//  pa99
//
//  Created by Mike Peng on 5/23/19.
//  Copyright © 2019 Yiming Peng. All rights reserved.


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class Term {
private:
    string str;
    unsigned long long weight;
public:
    Term(string s, unsigned long long w) :str(s), weight(w) {}
    bool GreaterWeight(Term rightSide);
    bool operator<(Term rightSide);
    friend ostream& operator<<(ostream& os, Term rightSide);
    friend vector<Term> List(vector<Term> & records, string prefix);
};
vector<Term> ReadFile(string fileName);
bool Compare(Term leftSide, Term rightSide);
void Sort(vector<Term>& term);
bool CompareWeight(Term leftSide, Term rightSide);
vector<Term> CreateVectorFromFile();
vector<Term> CombineVectors(vector<Term> term1, vector<Term> term2);
void SortByWeight(vector<Term> term);

int main() {
    vector<Term> wiktionary = ReadFile("wiktionary.txt");
    vector<Term> cities = ReadFile("cities.txt");

    string prefix;
    int num;
    cout << " Please text to autocomplete: ";
    getline(cin, prefix);
    cout << "Max number of result: ";
    cin >> num;
    vector<Term> term1;
    term1 = List(wiktionary, prefix);
    vector<Term> term2;
    term2 = List(cities, prefix);
    vector<Term> result= CombineVectors(term1,term2);
    SortByWeight(result);
    for (int i = 0; i < num; i++) {
        cout << result[i] << endl;
    }

    return 0;
}

vector<Term> ReadFile(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName);

    vector<Term> term;
    if (inputFile.fail()) {
        cout << "The file failed to open/" << endl;
    }

    else {
        long long size;
        inputFile >> size;
        for (long long i = 0; i < size; i++) {
            unsigned long long w;
            string s;
            inputFile >> w;
            inputFile.ignore(1);
            getline(inputFile, s);
            Term tempTerm(s, w);
            term.push_back(tempTerm);
        }

    }
    inputFile.close();
    return term;
}

vector<Term> CombineVectors(vector<Term> term1, vector<Term> term2) {
    vector<Term> result = term1;
    for (long long i = 0; i < term2.size(); i++) {
        result.push_back(term2[i]);
    }
    return result;
}

bool Term::GreaterWeight(Term rightSide) {
    if (rightSide.weight < this->weight) {
        return true;
    }
    else if (rightSide.weight > this->weight) {
        return false;
    }
    else{
        return false;
    }
}

bool CompareWeight(Term leftSide, Term rightSide) {
    return (leftSide.GreaterWeight(rightSide));
}

ostream& operator<<(ostream& os, Term rightSide) {
    os << rightSide.weight << " " << rightSide.str;
    return os;
}

vector<Term> List(vector<Term> & records, string prefix) {
    vector<Term> term;
for (long long i = 0; i < records.size(); i++) {
        if (prefix.size() > records[i].str.size()) {
            break;
        }
        else {
            int result = 0;
            for (int n = 0; n < prefix.size(); n++) {
                if (tolower(prefix[n]) == tolower(records[i].str[n])) {
                    result++;
                }
                else {
                    break;
                }
            }
            if (result == prefix.size()) {
                term.push_back(records[i]);
            }
        }
    }

    return term;
}

void SortByWeight(vector<Term> term) {
    sort(term.begin(), term.end(), CompareWeight);
}

bool Term::operator<(Term rightSide) {
    if (rightSide.str.size() > this->str.size()) {
        return true;
    } else if (this->str.size() < rightSide.str.size()) {
        return false;
    } else {
        for (unsigned int i = 0; i < rightSide.str.size(); i++) {
            
            if (tolower(this->str[i]) < tolower(rightSide.str[i])) {
                return true;
            }
            else if (tolower(this->str[i]) > tolower(rightSide.str[i])) {
                return false;
            }
            
        }
        return true;
    }
    
}



bool Compare(Term leftSide, Term rightSide) {
    return (leftSide < rightSide);
}
void Sort(vector<Term>& term) {
    sort(term.begin(), term.end(), Compare);
}


