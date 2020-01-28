// Author: Michael McComas
// CSCI 3110-001
// File: proj2.cpp
// Project #2
// Due: 2/6/19

#include <iostream>
#include <fstream>
#include <iomanip>
#include "gaspump.h"

using namespace std;

int main(){
    //Variables
    string gas = "";
    int seed = 0;
    int money = 0;
    int numCar = 0;
    double pCar1 = 0.00;
    double pCar2 = 0.00;
    double pCar3 = 0.00;
    double total = 0.00;
    double fuel = 0.00;
    double capacity = 0.00;
    double price = 0.00;
    double ran = 0.00;

    //Arrays
    GasPump* array[3];
    double fuelIt[2];
    double hold[3];
    //Open file
    ifstream inFile;
    inFile.open("gas.txt");
    //Random seed number & number of cars
    inFile >> seed >> numCar;

    //Values for pump1
    inFile >> gas >> capacity >> price >> pCar1;
    //create pump1 with array pointer
    GasPump pump1(gas, capacity, price);
    array[0] = &pump1;

    //Values for pump2
    inFile >> gas >> capacity >> price >> pCar2;
    //Create pump2 with array pointer
    GasPump pump2(gas, capacity, price);
    array[1] = &pump2;

    //Values for pump3
    inFile >> gas >> capacity >> price >> pCar3;
    //Create pump3 with array pointer
    GasPump pump3(gas, capacity, price);
    array[2] = &pump3;
    
    hold[0] = 1-pCar1;
    hold[1] = hold[0]-pCar2;
    hold[2] = hold[1]-pCar3;
    srand(seed);

    for(int i = 0; i < numCar; i++){
        ran = ((double) rand() + 1) / RAND_MAX;
        money = (((rand()%6)*5)+30);
       
        cout << "RAN: " << ran << endl;
        if(ran >= hold[0]){
            array[0]->dispenseFuel(fuelIt, money);
            cout << i+1 << " " << array[0]->getTyp() << " " << setprecision(2) << 
                fixed << array[0]->getPrice() << " " << setprecision(2) << fixed <<
                money << " " << setprecision(2) << fixed << fuelIt[0] << " " << 
                setprecision(2) << fixed << fuelIt[1] << " " << array[0]->getFuel() << endl;
        }
        else if(ran >= hold[1]){
            array[1]->dispenseFuel(fuelIt, money);
            cout << i+1 << " " << array[1]->getTyp() << " " << setprecision(2) << 
                fixed << array[1]->getPrice() << " " << setprecision(2) << fixed <<
                money << " " << setprecision(2) << fixed << fuelIt[0] << " " << 
                setprecision(2) << fixed << fuelIt[1] << " " << array[1]->getFuel() << endl;
        }
        else if(ran >= hold[2]){
            array[2]->dispenseFuel(fuelIt, money);
            cout << i+1 << " " << array[2]->getTyp() << " " << setprecision(2) << 
                fixed << array[2]->getPrice() << " " << setprecision(2) << fixed <<
                money << " " << setprecision(2) << fixed << fuelIt[0] << " " << 
                setprecision(2) << fixed << fuelIt[1] << " " << array[2]->getFuel() << endl;
        }
    }
    cout << pump1.getTyp() <<  " " << setprecision(2) << fixed << pump1.getGiven() << " "
         << setprecision(2) << fixed << pump1.getCollected() << endl;
    cout << pump2.getTyp() <<  " " << setprecision(2) << fixed << pump2.getGiven() << " "
         << setprecision(2) << fixed << pump2.getCollected() << endl;
    cout << pump3.getTyp() <<  " " << setprecision(2) << fixed << pump3.getGiven() << " "
         << setprecision(2) << fixed << pump3.getCollected() << endl;
    
    inFile.close();
    return 0;
}