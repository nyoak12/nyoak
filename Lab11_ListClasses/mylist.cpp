// Nathan Yoak 11/19/24

#include <iostream>
#include "list.hpp"
#include "list.cpp"

using std::cout; using std::endl;

int main(){
    int size=0;  // setting list array size
    // double *a = new double[size]; // allocating dynamic array
    bool keepTrack = true;
    char operation;
    double number;

    List c1;

    while(operation != 'q'){
        cout << "enter operation [a/r/q] and number: " << endl;
        cin >> operation;
        if(operation == 'q')
            break;
        else cin >> number;
        
        if(operation == 'a'){
            if(c1.check(number)== -1) c1.addNumber(number);
            else cout << number << " is already in list." << endl;
        }

        else if(operation == 'r'){
            c1.removeNumber(number);
        }
        
        else keepTrack = false;
        cout << "your numbers: ";
        c1.output(); cout << endl;
    }     
}