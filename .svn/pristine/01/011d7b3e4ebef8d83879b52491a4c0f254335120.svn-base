//created by Nathan Yoak 10/21/24
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::ifstream; using std::ofstream;
using namespace std;

//ifstream fin;
//ofstream fout;
ifstream myFile("unjustified.txt");
ofstream outFile("justified.txt");

const int LSIZE=90;
string myString;


void AddPunctSpace(string&);
void AddRandSpace(string&);


int main(){
   srand(time(nullptr));

   while(getline(myFile, myString)){
       AddPunctSpace(myString);
       while(myString.size() < LSIZE && myString.size() > 40){
           AddRandSpace(myString);
       }
       outFile << myString << endl;
   }
}

void AddPunctSpace(string& myString){
   int charPos;
   charPos=myString.find_first_of("?!,.");
   while(charPos != myString.npos){
       if(charPos < myString.size()-1) myString.insert(charPos+1, "  ");   
       charPos=myString.find_first_of(".,?1;", charPos+1);
       }
}

void AddRandSpace(string& myString){
   int RandSpace=rand() % myString.size();
   while(myString[RandSpace] != ' '){
       RandSpace=rand() % myString.size();
   }
   myString.insert(RandSpace, " ");
}

