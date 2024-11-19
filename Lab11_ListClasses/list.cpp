//functions implementation here
#include <iostream> 
using std::cout; using std::cin; using std::endl;

#include "list.hpp"

List::List(): size_(0), list_(nullptr){
    list_ = new double[size_];
    cout << "constructor called!" << endl;
}

// // copy constructor
List::List(const List& mylist){
    size_ = mylist.size_;
    list_ = new double[size_];
    for(int i=0; i < size_; i++) list_[i]=mylist.list_[i];
} 

// // overloaded assignment
List& List::operator=(const List& rhs){
    if(this != &rhs){
        size_ = rhs.size_;
        delete [] list_;
        list_ = new double[size_];
        for(int i = 0; i < size_; i++)
            list_[i] = rhs.list_[i];
    }
    return *this;
}
//deconstructor
List::~List(){
   delete [] list_;
   cout << "destructor called!" << endl;
}


void List::output(){
    for(int i = 0; i < size_;i++)
        cout << *(list_+i) << " ";
}


int List::check(double number){
    for(int i = 0; i < size_+1; i++){
        if(*(list_ + i) == number)
            return i;  //true returns index place
    }
    return -1; //false returns -1
}


void List::addNumber(double number){
    int result = check(number);
    if(result==-1){
        size_ += 1;
        double *new_arrPtr = new double[size_];
        for(int i = 0; i < (size_ - 1); i++){
            new_arrPtr[i] = list_[i];
        }
        delete[] list_;
        list_ = new_arrPtr;
        list_[size_-1]=number;
    }
}


void List::removeNumber(double number){
    int result = check(number);
    if(result!=-1){
        size_ -= 1;
        double *new_arrPtr = new double[size_];
        int count = 0;
        for(int i = 0; i < (size_+1); i++){
            if(list_[i] != number){
                new_arrPtr[count] = list_[i];
                count +=1;
            }
        }
        delete[] list_;
        list_ = new_arrPtr;
    }
}



