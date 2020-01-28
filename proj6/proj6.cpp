// Author: Michael McComas
// Project #6
// File: worldtree.cpp
// CSCI 3110-001
// Due: 4/1/19
// Remarks: Driver file for WordTree class that reads 2 files
// and creates a binary search tree and tries to find specific words

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "wordtree.h"

using namespace std;

int main(){
    // Variables
    int count;
    string file;
    string var;
    WordTree word;
    vector<string> vec;
    vector<string>& v = vec;

    // Open Files
    ifstream inFile;
    ifstream query;
    inFile.open("input.txt");
    query.open("queries.txt");

    // Read input.txt
    getline(inFile, file);
    transform(file.begin(), file.end(), file.begin(), ::tolower);
    word.split(file, ' ', v);

    // Assemble the Binary Search Tree
    for(auto &i : vec)
        word.addWord(i);

    cout << "Word Tree built and loaded" << endl;
    cout << "\n";

    // Seaarch for words from query file in word tree
    query >> var;
    while(!query.eof()){
        if(var == "C"){
            query >> count;
            word.getCounts(count);
        }
        query >> var;
        if(var == "F"){
            query >> var;
            cout << "Searching for occurances of the word '" << var << "'" << endl;
            word.findWord(var);
        }
    }

    inFile.close();
    query.close();
    return 0;
}