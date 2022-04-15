#ifndef WORDLEFILE_H
#define WORDLEFILE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class WordleFile
{
public:
    WordleFile();
    ~WordleFile();

protected:
    vector<string> wordlist;
    virtual void populateWordList(vector<string> wordlist) = 0;
private:
    ifstream readFile;
    string words;
};


#endif // WORDLEFILE_H
