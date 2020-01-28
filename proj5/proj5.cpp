// Author: Michael McComas
// Project #5
// File: proj5.cpp
// CSCI 3110-001
// Due: 3/18/19
// Remarks: Create a program that solves a maze using recursion

#include <iostream>
#include <fstream>
#include "maze.h"

using namespace std;

int main(){
    // Variables
    bool isFound;
    // Open file
    ifstream file;
    file.open("maze.txt");
    Maze maze(file);

    // Output maze and begin
    maze.Print();
    cout << "Start position: 1,1" << endl;
    maze.FindExit(1,1, isFound);

    // Output Maze result
    if(isFound)
        cout << "Found exit!" << endl;
    else
        cout << "No exit!" << endl;
    
    return 0;
}