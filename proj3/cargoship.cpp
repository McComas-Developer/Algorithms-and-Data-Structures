//Author: Michael McComas
//CSCI 3110-001
//Project #3
//Due 2/18/19
#include "cargoship.h"
#include <string>
#include <cmath>

using namespace std;

CargoShip::CargoShip(string shipName, double fuel, double cap, double fcb) : Ship(shipName, fuel){
    aftBay = new double;
    forBay = new double;
    *forBay = fcb;
    *aftBay = abs((*forBay) - 1); 
    MAX = cap;
}

CargoShip::~CargoShip(){
    delete aftBay;
    delete forBay;
    aftBay = nullptr;
    forBay = nullptr;
}
void CargoShip::fuel(int f){
    Ship::fuel();
    cout << shipName << " " << f << endl;
}

void CargoShip::load(int cargo){
    double temp;
    if ((cargo > MAX) ? cargo=MAX:cargo);
    temp = (cargo * (*aftBay));
    *aftBay = temp;
    temp = (cargo * (*forBay));
    *forBay = temp;
    cout << shipName << " " << *forBay << " " << *aftBay << endl;
}