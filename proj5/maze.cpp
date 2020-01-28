// Author: Michael McComas
// Project #5
// File: maze.cpp
// CSCI 3110-001
// Due: 3/18/19

#include "maze.h"
#include <iostream>

Maze::Maze(std::ifstream& file){
    file >> maxRows >> maxCols;
    // Build Maze
    for(int i = 1; i < maxRows + 1; i++){
        for(int j = 1; j < maxCols + 1; j++)
            file >> maze[i][j];
    }
    // Build barrier
    for(int i = 0; i < maxRows + 2; i++){
        for(int j = 0; j < maxCols + 2; j++){
            if(i == 0 || i == maxRows + 1)
                maze[i][j] = 'X';
            else{
                maze[i][0] = 'X';
                maze[i][maxRows+1] = 'X';
            }
        }
    }
}
// Print maze
void Maze::Print(){
    std::cout << "Maze state: " << std::endl;
    for(int i = 1; i < maxRows + 1; i++){
        for(int j = 1; j < maxCols + 1; j++)
            std::cout << maze[i][j] << " ";
        std::cout << "\n";
    }
}

void Maze::FindExit(int num1, int num2, bool& found){
    // While exit not found, explore maze
    if(!found){
        if(maze[num1][num2] == 'E'){
            found = true;
            std::cout << "Exploring: " << num1 << "," << num2 << std::endl;
        }
        else if(maze[num1][num2] == 'X'){}
        else if(maze[num1][num2] == 'O'){
            maze[num1][num2] = '*';
            std::cout << "Exploring: " << num1 << "," << num2 << std::endl;
            Print();
            FindExit(num1-1, num2, found);
            FindExit(num1, num2+1, found);
            FindExit(num1+1, num2, found);
            FindExit(num1, num2-1, found);
        }
    }
}