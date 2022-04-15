#include "WordleFile.h"

using namespace std;

WordleFile::WordleFile()
{
    vector<string> wordlist;
}

WordleFile::~WordleFile()
{

}

void WordleFile::populateWordList(vector<string> wordlist)
{
    ifstream readFile("wordlelist.txt");
    while (getline(readFile, words))
    {
        wordlist.push_back(words);
    }
    readFile.close();
}
