#include "list.hpp"
#include "list.cpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main(){
    int size=0;  // setting list array size
    double *a = new double[size]; // allocating dynamic array
    bool keepTrack = true;
    char operation;
    double number;

    while(operation != 'q'){
        cout << "enter operation [a/r/q] and number: " << endl;
        cin >> operation;
        if(operation == 'q')
            break;
        else cin >> number;
        
        if(operation == 'a'){
            if(check(a, number, size)== -1) addNumber(a, number, size);
        }

        else if(operation == 'r'){
            removeNumber(a, number, size);
        }
        
        else keepTrack = false;
        cout << "your numbers: ";
        output(a, size);
    }   
}