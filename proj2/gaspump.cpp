// Author: Michael McComas
// CSCI 3110-001
// File: gaspump.cpp
// Project #2
// Due: 2/6/19

#include "gaspump.h"

GasPump::GasPump(string gas, double capacity, double price){
    gasTyp = gas;
    fuelCap = capacity;
    ppg = price;
    fuel = fuelCap;
    given = 0;
    mnyColl = 0;
};
void GasPump::replenish(double &fuel, double fuelCap){
    fuel = fuelCap;
    nextCust = true;
}

void GasPump::dispenseFuel(double* fuelIt, double money){
    double request = (money/ppg);
    if(request <= fuel){
        fuelIt[0] = money;
        fuelIt[1] = request;
        fuel -= request;
        given += request;
        mnyColl += money;
    }
    else if(request > fuel && fuel != 0){
        fuelIt[0] = (fuel*ppg);
        fuelIt[1] = fuel;
        given += fuel;
        fuel = 0;
        mnyColl += fuelIt[0];
        nextCust = false;
    }
    else if(nextCust = false){
        replenish(fuel, fuelCap);
    }
}