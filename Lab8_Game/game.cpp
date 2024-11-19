//Nate Yoak
// 10/30

#include "maze.cpp"
#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main(){
    srand(time(nullptr)); // random seed
    //srand(1); // fixed seed
    RoomPair myMaze[numWalls]; // array of walls in the maze

    clearWalls(myMaze); //assigning -1 and '*' to all rooms of the walls 
 
    // // // printing walls of the maze
    cout << "uninitialized maze walls: ";  printMaze(myMaze); cout << endl;

    build(myMaze); // placing walls at random locations in the maze
    
    Room myRoom = startRoom;
    cout << "Start: find the cheese room: "; printRoom(startRoom); cout << endl;
    cout << "Would you like to see the wall positions? 'y' or 'n' " << endl;
    char usr;
    cin >> usr;
    if(usr == 'y'){
        cout << "here are the wall positions: ";  printMaze(myMaze); cout << endl;
    }
    while(matchRoom(myRoom, cheeseRoom)== false){
        RoomPair myWall = { {2,'b'}, {2,'c'} };
        RoomPair myWallCheck;
        Room newMoveRoom;
        bool check = true;

        do{
            newMoveRoom = nextMove(myRoom);
            myWallCheck.one = myRoom;
            myWallCheck.two = newMoveRoom;
        }while(checkMaze(myMaze, myWallCheck));
         // asks user for new adjacent room
        cout << newMoveRoom.x << newMoveRoom.y << endl;
        myRoom = newMoveRoom;


        
        
        // cout << check << endl;
        // cout << "wall there. try again"; 
        

        // // if (matchPair(myWall, myWallCheck)){
        // //     cout << "there is a wall between these two rooms" << endl;
        // // }
        // // else{
        // //     cout << "there is no wall between these two rooms" << endl;
        // // }

        // myRoom = nextMove(newMoveRoom);
        // cout << myRoom.x << myRoom.y << endl;
       
        // myWallCheck.one = newMoveRoom;
        // myWallCheck.two = myRoom;

        // check = checkMaze(myMaze, myWallCheck);
        // cout << check << endl;
        // cout << "wall there. try again"; 
        // cout << myRoom.x << myRoom.y << endl;
        

        // // if (matchPair(myWall, myWallCheck)){
        // //     cout << "there is a wall between these two rooms" << endl;
        // // }
        // // else{
        // //     cout << "there is no wall between these two rooms" << endl;
        // // }



    }
    if(matchRoom(myRoom, cheeseRoom)){
        cout << "You got the cheese!";
    }


}