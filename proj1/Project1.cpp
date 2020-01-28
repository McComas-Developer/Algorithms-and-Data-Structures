// Author: Michael McComas
// CSCI 3110-001
// File: proj1.cpp
// Project #1
// Due: 1/28/19

#include <iostream>
#include <fstream>

using namespace std;

// Function Prototypes:
int *allocateArray(int *array, int *size, double EXPAND);
double calcAvg(int *array, int cnt);

int main(){
    //variables
    int size = 0;
    int hold = 0;
    int cnt = 0;
    int *array;
    double EXPAND = 0;

    ifstream nums;
    nums.open("nums.txt");
    nums >> size;
    //Determine if initial array size is valid, if not exit program.
    if(size % 50 != 0 || size < 100 || size > 350){
        cout << "ERROR" << endl;
        return 0;
    }
    //Send initial array size to file and stdout
    ofstream out;
    out.open("out.txt");
    out << size << endl;
    cout << size << endl;
    //Find array expansion rate
    nums >> EXPAND;
    nums >> hold;
    //Create intial array and find average
    array = allocateArray(NULL, &size, EXPAND);           
    //Put elements from file into array
    for(int i = 0; i < size; i++){
        cnt++;
        array[i] = hold;
        nums >> hold;
        if(nums.eof()){
            i++;
            cnt++;
            array[i] = hold;
            break;
        }
        //If array size is reached and theres more to the
        //file, call the following functions.
        if(i == size - 1 && !nums.eof()){
            cout << size << " " << calcAvg(array, cnt) << endl;
            out << size << " " << calcAvg(array, cnt) << endl;
            array = allocateArray(array, &size, EXPAND);
        }
    }
    cout << size << " " << cnt << " " << calcAvg(array, cnt) << endl;
    out << size << " " << cnt << " " << calcAvg(array, cnt) << endl;
    //Close text files
    nums.close();
    out.close();
    //Deallocate pointer for array length
    delete [] array;
    array = nullptr;
    return 0;
}

int *allocateArray(int *array, int *size, double EXPAND){
    //If no array, create one
    if(!array){
        array = new int[*size];
        return array;
    }
    //Old size of array
    int old = *size;
    //Determine new size
    *size = ((*size * EXPAND) + *size);
    //New array
    int *temp = new int[*size];
    //Put old array values in new array
    for(int i = 0; i < old; i++){
        temp[i] = array[i];
    }
    //Deallocate old array and set array pointer to null
    delete [] array;
    array  = nullptr;
    return temp;
}

double calcAvg(int *array, int cnt){
    //Values
    double sum = 0.000;
    //Determine total in array
    for(int i = 0; i < cnt; i++){
        sum += array[i];
    }
    return (sum/(cnt));
}