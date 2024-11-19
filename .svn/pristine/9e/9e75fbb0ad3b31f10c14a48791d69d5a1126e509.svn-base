//Nathan Yoak 11/5/24

#include <iostream>
#include "maze.hpp"
#include "maze.cpp"

using std::cout; using std::cin; using std::endl;

int main() {

    srand(time(nullptr)); // random seed

    Maze myMaze;
    Room startRoom; startRoom.makeStartRoom();
    Room cheeseRoom; cheeseRoom.makeCheeseRoom();
    myMaze.start();
    myMaze.build();
    cout << "maze with walls:"; myMaze.print(); cout << endl;
    // cout << "maze with no walls: "; myMaze.print(); cout << endl;
    while(!matchRoom(myMaze.getCurrentRoom(), cheeseRoom)){
        Room myRoom = myMaze.getCurrentRoom();
        cout << "current position: "; myRoom.print(); cout << endl;
        Room newMoveRoom = myRoom.nextMove();
    
        if (myMaze.move(newMoveRoom)){
            cout << "move to next room successful" << endl;
        }
        else{
            cout << "move to next room failed" << endl;
        }
    }
        cout << endl << "You made it to the cheese room. congrats." << endl;
    
}