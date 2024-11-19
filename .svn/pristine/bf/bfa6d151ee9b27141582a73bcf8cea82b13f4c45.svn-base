
#include "maze.hpp"
#include <iostream>
using std::cout; using std::cin; using std::endl;

// print room
void printRoom(const Room& myRoom){
   cout << myRoom.x << myRoom.y;
}

void printPair(const RoomPair& myRoomPair){
    cout << myRoomPair.one.x << myRoomPair.one.y << myRoomPair.two.x << myRoomPair.two.y << endl;
}

bool goodDirection(const Room& rm, const char dr){
   if(dr == 'u'){
       if(rm.y >= 'a')
           return true;
       else return false;
   }
   else if(dr == 'd'){
       if(rm.y <= 'a'+ mazeSize-1)
           return true;
       else return false;
   }
   else if(dr == 'l'){
       if(rm.x >= 1)
           return true;
       else return false;
   }
   else if(dr == 'r'){
       if(rm.x <= mazeSize)
           return true;
       else return false;
   }
   else return false;
}

Room createAdjacent(const Room &rm, const char dr){
   Room newRoom;
   if(dr == 'u'){
       newRoom.y = rm.y - 1;
       newRoom.x = rm.x;
   }
   if(dr == 'd'){
       newRoom.y = rm.y + 1;
       newRoom.x = rm.x;        
   }
   if(dr == 'l'){
       newRoom.y = rm.y;
       newRoom.x = rm.x - 1;
   }
   if(dr == 'r'){
       newRoom.y = rm.y;
       newRoom.x = rm.x + 1;        
   }  
   return newRoom;
}

const Room pickAdjacent(const Room &rm){
    char direction_list[]= {'u', 'd', 'l', 'r'};
    Room adjPick;
    int rand_num;
    do {
        rand_num = rand()%4;
        adjPick = createAdjacent(rm, direction_list[rand_num]); 
    }while(!goodDirection(adjPick, direction_list[rand_num]));

    return adjPick;

}

const Room nextMove(const Room& currentRoom){
    char dr;
    Room nextRoom;
    cout << "what direction is your next move?" << endl;
    do{    
        cin >> dr;
        nextRoom = createAdjacent(currentRoom,dr);
    }while(!goodDirection(nextRoom, dr));
    return nextRoom;
}


const RoomPair pickPair(){
    int rand_num = rand()%mazeSize+1;
    int rand_num2 = rand()%mazeSize;
    Room randRoom;
    RoomPair randPair;
    randRoom.x = rand_num;
    randRoom.y = 'a'+rand_num2;
    randPair.one = randRoom;
    randPair.two = pickAdjacent(randRoom);
    return randPair;
}

bool matchRoom(const Room& a, const Room& b){
    if(a.x == b.x && a.y == b.y)
        return true;
    else return false;
}

bool matchPair(const RoomPair& rp1, const RoomPair& rp2){
    if(((rp1.one.x + rp1.one.y) == (rp2.one.x + rp2.one.y)) && ((rp1.two.x + rp1.two.y) == (rp2.two.x + rp2.two.y))){
        return true;
    }
    else if(((rp1.one.x + rp1.one.y) == (rp2.two.x + rp2.two.y)) && ((rp1.two.x + rp1.two.y) == (rp2.one.x + rp2.one.y))){
        return true;
    }
    else{
        return false;
    }
}

void clearWalls(RoomPair a[]){
    for(int i = 0; i < numWalls; i++){
        a[i].one.x = -1;
        a[i].one.y = '*';
        a[i].two.x = -1;
        a[i].two.y = '*';
    }
}

void printMaze(const RoomPair a[]){
    cout << endl;
    for(int i = 0; i < numWalls; i++){
        cout << a[i].one.x << a[i].one.y << "|" << a[i].two.x << a[i].two.y << endl;
    }
}

void build(RoomPair a[]){
    bool result;
    RoomPair buildWalls;

    for(int i = 0; i < numWalls; i++){
        do{
            buildWalls = pickPair();
            result = checkMaze(a, buildWalls);
        }while(result);
        a[i].one.x = buildWalls.one.x;
        a[i].one.y = buildWalls.one.y;
        a[i].two.x = buildWalls.two.x;
        a[i].two.y = buildWalls.two.y;
    }
}

bool checkMaze(const RoomPair a[], const RoomPair &rp){
    for(int i = 0; i < numWalls; i++){
        if(matchPair(a[i], rp) == true){
            return true; 
        }
    }
    return false;
    
}
    

    
