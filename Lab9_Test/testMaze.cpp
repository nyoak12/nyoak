// Mikhail Nesterenko
// tests class-based Maze function implementation
// 3/23/2023

#include <iostream>
#include "maze.hpp"
#include "maze.cpp"

using std::cout; using std::cin; using std::endl;

int main() {
    // 
    // checking room functions
    // 
    srand(time(nullptr)); // random seed
    // srand(1); // fixed seed

    
    //
    // first part: checking Room functions
    //

    Room myRoom; // create a room
   
    
    // // cout << "myRoom, default location: "; myRoom.print(); cout << endl;

    // myRoom.pick();
    // cout << "myRoom, random location: "; myRoom.print(); cout << endl;

    Room startRoom; startRoom.makeStartRoom();
    // cout << "start room: "; startRoom.print(); cout << endl;

    Room cheeseRoom; cheeseRoom.makeCheeseRoom();
    // cout << "cheese room: "; cheeseRoom.print(); cout << endl;

    myRoom = startRoom;
    Room newMoveRoom;
    // // make sure to implement goodDirection() and createAdjacent() first
    // Room newMoveRoom = myRoom.nextMove(); // asks user for new adjacent room
    // cout << "user selected adjacent room: "; newMoveRoom.print(); cout << endl; 
    // cout << "my room: "; myRoom.print(); cout << endl;



    // if(matchRoom(myRoom, newMoveRoom))
    //     cout << "myRoom is the same as newMoveRoom" << endl;
    // else
    //     cout << "myRoom is not the same as newMoveRoom" << endl;
    

    //
    // second part: RoomPair functions
    //
    
    RoomPair myPair;
    // cout << "myPair, default location: "; myPair.print(); cout << endl;

    // RoomPair otherPair(myRoom, newMoveRoom); // testing a constructor
    // cout << "pair of myRoom, newMoveRoom: "; otherPair.print(); cout << endl;

    myPair.pick();
   
    // cout << "random room pair: "; myPair.print(); cout << endl;

    // if(matchPair(myPair,otherPair))
    //     cout << "myPair is the same as otherPair" << endl;
    // else
    //     cout << "myPair is not the same as otherPair" << endl;
    
    //
    // third part: Maze functions
    //
    
    Maze myMaze;
    cout << "maze with no walls: "; myMaze.print(); cout << endl;

    myMaze.start();
    // cout << "current room: " ; myMaze.getCurrentRoom().print();

    // // make sure to implemnt Maze::checkMaze() before build()
    myMaze.build();
    cout << "maze with walls:"; myMaze.print(); cout << endl;


    while(!matchRoom(myRoom, cheeseRoom)){
        myRoom = myMaze.getCurrentRoom();
        cout << "maze current room: "; myRoom.print(); cout << endl;


        newMoveRoom = myRoom.nextMove(); 

        cout << "maze current room: "; newMoveRoom.print(); cout << endl;
        if (myMaze.move(newMoveRoom))
            cout << "move to newMoveRoom is successful" << endl;
        else
            cout << "move to newMoveRoom failed" << endl;

        cout << "maze current room: "; newMoveRoom.print(); cout << endl;
        // myRoom = myMaze.getCurrentRoom();
        // cout << "maze current room: "; myRoom.print(); cout << endl;
        


    }
 
}

