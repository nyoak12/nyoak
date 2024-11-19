//functions implementation here
#include <iostream> 
using std::cout; using std::cin; using std::endl;

#include "list.hpp"

void output(double *colPtr, int size){
    for(int i = 0; i < size; i++){
        cout << *(colPtr + i) << ", ";  
    }
    cout << endl;
}

int check(double *colPtr, double number, int size){
    for(int i = 0; i < size; i++){
        if(*(colPtr + i) == number)
            return i;  //true and index place
    }
    return -1; //false
}

void addNumber(double *& colPtr, double number, int &size){
    if(check(colPtr, number, size) == -1){
        size +=1;
        double *new_arrPtr = new double[size];
        for(int i = 0; i < (size - 1); i++){
            new_arrPtr[i] = colPtr[i];
        }
        delete[] colPtr;
        colPtr = new_arrPtr;
        colPtr[size-1]=number;
    }
}

void removeNumber(double *& colPtr, double number, int &size){
        size -= 1;
        double *new_arrPtr = new double[size];
        int count = 0;
        for(int i = 0; i < (size+1); i++){
            if(colPtr[i] != number){
                new_arrPtr[count] = colPtr[i];
                count +=1;
            }
        }
        delete[] colPtr;
        colPtr = new_arrPtr;  
    
}