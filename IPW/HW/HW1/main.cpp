#include "Player.h"
#include "Maze.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    /* Testing for Player class
    string n = "Gunther";
    Player p1(n,true);
    cout << p1.get_name() << endl;
    cout << p1.is_human() << endl;
    p1.ChangePoints(100);
    cout << p1.get_points() << endl;
    Position pos1;
    pos1.row = 0;
    pos1.col = 0;
    p1.SetPosition(pos1);
    Position pos2 = p1.get_position();
    cout << pos2.col << "," << pos2.row << endl;
    cout << p1.Stringify() << endl;
    //test for relative position
    Position pos_2;
    pos_2.row = 0;
    pos_2.col = 1;
    cout << p1.ToRelativePosition(pos_2) << endl;
    //should print that it is RIGHT
    Position pos3;
    pos3.row = 0;
    pos3.col = -1;
    cout << p1.ToRelativePosition(pos3) << endl;
    //should print LEFT
    Position pos4;
    pos4.row = 1;
    pos4.col = 0;
    cout << p1.ToRelativePosition(pos4) << endl;
    //should print UP
    Position pos5;
    pos5.row = -1;
    pos5.col = 0;
    cout << p1.ToRelativePosition(pos5) << endl;
    //Should print DOWN
    Position pos6;
    pos6.row = 1;
    pos6.col = 1;
    cout << p1.ToRelativePosition(pos6) << endl;
    //should print unreachable
    */
    string n = "Gunther";
    string en1 = "Monster 1";
    string en2 = "Monster 2";
    Position sp1;
    sp1.row = 0;
    sp1.col = 0;
    Position sp2;
    sp2.row = 2;
    sp2.col = 0;
    Position sp3;
    sp3.row = 3;
    sp3.col = 0;
    Player p1(n,true,sp1);
    Player e1(en1,false,sp2);
    Player e2(en2,false,sp3);
    Maze m;
    m.NewGame(&p1,2);
    bool game = true;
    vector<Player> players = {p1,e1,e2};
    int size = players.size();
    Player select = p1;
    while (game == true){
        for(int i = 0; i < size;i++){
            select = players[i];
            m.GenerateReport(&select);
            m.TakeTurn(&select);
            if(m.IsGameOver(&select)){
                game = false;
            }
        }
    }
    return 0;
}