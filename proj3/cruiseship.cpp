//Author: Michael McComas
//CSCI 3110-001
//Project #3
//Due 2/18/19

#include "cruiseship.h"
#include <cstring>

CruiseShip::CruiseShip(string ship, double fuel, double lux, double upp, double low) : Ship(ship, fuel){
    luxPer = lux;
    uppPer = upp;
    lowPer = low;
}

void CruiseShip::sail(){
    cout << shipName << " " << luxPass << " " << uppPass << " " 
    << lowPass << endl;
}

void CruiseShip::load(int pass){
    double temp = 0;
    temp = (luxPer * pass);
    luxPass = temp;
    temp = (uppPer * pass);
    uppPass = temp;
    temp = (lowPer * pass);
    lowPass = temp;
}