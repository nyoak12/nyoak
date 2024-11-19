#include <iostream>
#include "maze.hpp"

using std::cout; using std::cin; using std::endl;

Room::Room(): x_(-1), y_('*'){
}
void Room::print() const{
    cout << x_ << y_;
}

void RoomPair::print() const{
    one_.print(); cout << "|"; two_.print();
}


void Room::pick(){
    x_ = rand()%5 + 1;
    y_ = 'a' + (rand()%5);
}

void RoomPair::pick(){
    char direction_list[]= {'u', 'd', 'l', 'r'};
    one_.pick();
    two_ = one_.pickAdjacent();
}


bool Room::goodDirection(const char dr) const{
    if(dr == 'u'){
       if(y_ - 1 >= 'a')
           return true;
   }
    if(dr == 'd'){
       if(y_ + 1 <= 'a'+ mazeSize_-1)
           return true;
   }
    if(dr == 'l'){
       if(x_ - 1 >= 1)
           return true;
   }
    if(dr == 'r'){
       if(x_ + 1 <= mazeSize_)
           return true;
   }
   return false;
}

const Room Room::pickAdjacent(){
    Room createWall;
    char direction_list[]= {'u', 'd', 'l', 'r'};
    char dr;
    bool result;
    do{
        dr = direction_list[rand()%4];
        result = goodDirection(dr);
    }while(!result);
    createWall = createAdjacent(dr);
    return createWall;

}

const Room Room::createAdjacent(const char dr) const{
    Room newAdj;
    if(dr == 'u'){
        newAdj.y_ = y_ - 1;
        newAdj.x_ = x_;
    }
    if(dr == 'd'){
        newAdj.y_ = y_ + 1;
        newAdj.x_ = x_;        
    }
    if(dr == 'l'){
        newAdj.y_ = y_;
        newAdj.x_ = x_ - 1;
    }
    if(dr == 'r'){
        newAdj.y_ = y_;
        newAdj.x_ = x_ + 1;        
    }  
    return newAdj;
}

const Room Room::nextMove() const{
    char dr;
    bool result;
    do{
        cout << "whats your next move? 'u' 'd' 'l' 'r' " << endl;
        cin >> dr;
        result = goodDirection(dr);
    }while(!result);
    return createAdjacent(dr);   
}

bool matchRoom(const Room& a, const Room& b){
    if(a.x_ == b.x_ && a.y_ == b.y_)
        return true;
    else return false;
}

bool matchPair(const RoomPair& rp1, const RoomPair& rp2){
    if(matchRoom(rp1.one_, rp2.one_)){
        if(matchRoom(rp1.two_, rp2.two_))
            return true;
    }
    if(matchRoom(rp1.one_, rp2.two_)){
        if(matchRoom(rp1.two_, rp2.one_))
            return true;
    }

    return false;
}

void Maze::print() const{
    for(int i = 0; i < numWalls_; i++){
        walls_[i].print();
        cout << " ";
    }      
}

bool Maze::checkMaze(const RoomPair& currentRP) const{
    for(int i = 0; i < numWalls_; i++){
        if(matchPair(walls_[i], currentRP))
            return true;
    }
    return false;
}
void Maze::build(){
    bool result;
    RoomPair buildWalls;
    for(int i = 0; i < numWalls_; i++){
        do{
            buildWalls.pick();
            result = checkMaze(buildWalls);
        }while(result);
        walls_[i] = buildWalls;
    }
}

bool Maze::move(const Room& nextR){
    RoomPair myMoves(getCurrentRoom(), nextR);
    if(!checkMaze(myMoves)){
        currentRoom_ = nextR;
        return true;

    }
    return false;
    
}


