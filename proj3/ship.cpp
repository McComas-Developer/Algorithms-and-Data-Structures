//Author: Michael McComas
//CSCI 3110-001
//Project #3
//Due 2/18/19
#include "ship.h"

Ship::Ship(string name, double gas){
    shipName = name;
    shipFuel = gas;
}

void Ship::fuel(){
    cout << shipName << " " << shipFuel << endl;
}

void Ship::sail(){
    cout << shipName << " sailing" << endl;
}