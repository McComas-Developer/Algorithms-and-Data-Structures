//Author: Michael McComas
//CSCI 3110-001
//Project #3
//Due 2/18/19
#include <string>
#include "ship.h"

using namespace std;

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

class CargoShip : public Ship{
    public:
        CargoShip(string, double, double, double);
        ~CargoShip();
        void fuel(int);
        void load(int);
    private:
        int MAX;
        double pCargo;
        double *forBay;
        double *aftBay;
};

#endif