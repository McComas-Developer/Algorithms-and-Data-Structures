//Author: Michael McComas
//CSCI 3110-001
//Project #3
//Due 2/18/19
#include <iostream>
#include <string>

using namespace std;

#ifndef SHIP_H
#define SHIP_H

class Ship{
    public:
        Ship(string, double);
        Ship(){}
        void fuel();
        virtual void sail();
        virtual void load (int) = 0;

    protected:
        string shipName;
        double shipFuel;
};

#endif
