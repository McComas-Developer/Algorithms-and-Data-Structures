//Author: Michael McComas
//CSCI 3110-001
//Project #3
//Due 2/18/19

#include <iostream>
#include "ship.h"

using namespace std;

#ifndef CRUISESHIP_H
#define CRUISESHIP_H

class CruiseShip : public Ship{
    public:
        CruiseShip(string, double, double, double, double);
        void sail();
        void load(int);

    private:
        int luxPass;
        int uppPass;
        int lowPass;
        double luxPer;
        double uppPer;
        double lowPer;
};

#endif