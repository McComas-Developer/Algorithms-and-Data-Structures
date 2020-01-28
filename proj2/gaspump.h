// Author: Michael McComas
// CSCI 3110-001
// File: gaspump.h
// Project #2
// Due: 2/6/19
#include <iostream>
#include <cstring>

using namespace std;

#ifndef GASPUMP_H
#define GASPUMP_H

class GasPump{
    public:
        GasPump(string, double, double);
        string getTyp() const{
            return gasTyp;
        }
        double getFuel() const{
            return fuel;
        }
        double getCap() const{
            return fuelCap;
        }
        double getPrice() const{
            return ppg;
        }
        double getGiven() const{
            return given;
        }
        double getCollected() const{
            return mnyColl;
        }
        void dispenseFuel(double*, double);
    private:
        string gasTyp; // The type of gas
        double fuel;   // The amount of fuel
        double fuelCap;// Fuel pump capacity
        double ppg;    // Price per gallon of fuel
        double given;  // Amount of fuel dispensed
        double mnyColl;// Money collected
        bool nextCust; // Fuel for next customer?
        void replenish(double&, double);// Replenishes fuel tank
};
#endif