//Author: Michael McComas
//CSCI 3110-001
//Project #3
//Due 2/18/19
#include <iostream>
#include <fstream>
#include <cstring>
#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"

using namespace std;

//Function prototype
void sailShip(Ship &myShip);

int main(){
    //Cruise Variables
    int pass;
    string ship;
    double fuel;
    double lux;
    double upp;
    double low;
    //Cargo Variables
    int cap;
    int cargoTon;
    int fuelFlash;
    string SHIP;
    double FUEL;
    double fwdPer;
    //Open text file
    ifstream inFile;
    inFile.open("ships.txt");
    //Input Cruise variables
    inFile >> ship >> fuel >> lux >> upp >> low >> pass;
    //Create Cruise object with input variables
    CruiseShip myCruise(ship, fuel, lux, upp, low);
    //Call Cruise object functions
    myCruise.fuel();
    myCruise.load(pass);
    sailShip(myCruise);
    //Input Cargo variables
    inFile >> SHIP >> FUEL >> cap >> fwdPer >> cargoTon >> fuelFlash;
    //Create Cargo object with input variables
    CargoShip myCargo(SHIP, FUEL, cap, fwdPer);
    //Call Cargo object functions
    myCargo.fuel(fuelFlash);
    myCargo.load(cargoTon);
    sailShip(myCargo);

    inFile.close();
    return 0;
}
void sailShip(Ship &myShip){
    myShip.sail();
}