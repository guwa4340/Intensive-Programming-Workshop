#include "Maze.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

string SquareTypeStringify(SquareType sq){
    string s;
    if(sq == SquareType::Human){
        s = " 🧍 ";
    }if(sq == SquareType::Wall){
        s = " ❌ ";
    }if(sq == SquareType::Enemy){
        s = " 👹 ";
    }if(sq == SquareType::Exit){
        s = " ✅ ";
    }if(sq == SquareType::Empty){
        s = " 🟩 ";
    }if(sq == SquareType::Treasure){
        s = " 🍔 ";
    }
    return s;
}

Board::Board(){
    rows_ =  sizeof arr_ / sizeof arr_[0]; //rows  
    cols_ = sizeof arr_[0] / sizeof(SquareType); //cols
}

SquareType Board::get_square_value(Position pos) const{
    int r = pos.row;
    int c = pos.col;
    return arr_[r][c];
}

void Board::SetSquareValue(Position pos, SquareType value){
    //cout << "In SetSquare" << endl;
    //cout << pos.col << pos.row << endl;
    int r = pos.row;
    int c = pos.col;
    arr_[r][c] = value;
}

vector<Position> Board::GetMoves(Player *p){
    //cout << "In GetMoves Function" << endl;
    //cout << rows_ << cols_ << endl;
    Position player_pos = p -> get_position();
   // cout << player_pos.col << player_pos.row << endl;
    SquareType w = SquareType::Wall;
    vector<Position> moves;
    //cout << "Right After Vector DEcleration" << endl;
    //check up
    int tmpr = player_pos.row + 1;
    int tmpc = player_pos.col;
    Position tmp;
    tmp.row = tmpr;
    tmp.col = tmpc;
    if (tmpr < rows_){
        //check for wall
        if(get_square_value(tmp) != w){        
            moves.push_back(tmp);
            //cout << tmp.col << tmp.row << endl;
        }
    }
    //cout << "Checked for up" << endl;
    tmpr = player_pos.row - 1;
    tmpc = player_pos.col;
    //cout << "Temp =" << tmpr << tmpc << endl;
    tmp.row = tmpr;
    tmp.col = tmpc;
    //cout << "New pos =" << tmp.row << tmp.col << endl;
    //cout << "declerations" << endl;
    //cout << tmpr << endl;
    if (tmpr >= 1){
        //cout << "Within if Statement" << endl;
        //check for wall
        if(get_square_value(tmp) != w){   
            //cout << "Within Second if statement" << endl;
            moves.push_back(tmp);
           // cout << tmp.col << tmp.row << endl;
        }
    }
    //cout << "Checked for down" << endl;
    tmpr = player_pos.row;
    tmpc = player_pos.col -1;
    tmp.row = tmpr;
    tmp.col = tmpc;
    if (tmpc >= 1){
        //check for wall
        if(get_square_value(tmp) != w){        
            moves.push_back(tmp);
            //cout << tmp.col << tmp.row << endl;
        }
    }
    //cout << "Checked for Left" << endl; 
    tmpr = player_pos.row;
    tmpc = player_pos.col + 1;
    tmp.row = tmpr;
    tmp.col = tmpc;
    if (tmpr < cols_ ){
        //check for wall
        if(get_square_value(tmp) != w){        
            moves.push_back(tmp);
            //cout << tmp.col << tmp.row << endl;
        }
    }
    //cout << "Checked for Right" << endl;
    //cout << "Right BEfore REturn statement in GETMOVES" << endl;
    return moves;
}

bool Board::MovePlayer(Player *p, Position pos){
        Position old_pos = p->get_position();
        p->SetPosition(pos);
        //cout << "Within MovePlayer" << endl;
        //cout << "Old Position = " << old_pos.col << old_pos.row << endl;
        //cout << "New Position = " << pos.col << pos.row << endl;
        if(p->is_human()){
            SetSquareValue(pos,SquareType::Human);
            SetSquareValue(old_pos,SquareType::Empty);
        }
        else{
            if(get_square_value(pos) == SquareType::Human){
                cout << "Human Killed By Monsters!";
            }else{
                SetSquareValue(pos,SquareType::Enemy);
                SetSquareValue(old_pos,SquareType::Empty);
            }
        }
        if(get_square_value(p->get_position()) == SquareType::Treasure){
            p->ChangePoints(p->get_points() + 100);
        }
        return true;
}

/*
The rules for board layout are as follows:
-The player always starts in the upper left corner-The exit is always in the lower right corner
-Walls appear with a 20% chance in the spacesthat are not the beginning space or the exit
-Treasures appear with a 10% chance in spacesthat are not walls, the beginning space, or the exit
-You can decide where the enemies start, so longas they do not start on a wall or the exit
*/

Maze::Maze(){
    board_ = new Board();
}

void Maze::NewGame(Player *human, const int enemies){
    //implement number of enemies
    srand(time(NULL));
    int RandIndex;
    const int a[10] = {0,0,0,0,0,0,0,1,1,2};
    Position pos;
    for(int i = 0;i < board_->get_cols();i++){
        for(int j = 0; j < board_->get_rows();j++){
            //cout<< "i=" << i << endl;
            //cout << "j=" << j << endl;
            pos.col = i;
            pos.row = j;
            //cout << "pos=" << pos.col << pos.row << endl;
            if(i == 0 && j == 0){
                //cout << "Set Human" << endl;
                board_->SetSquareValue(pos,SquareType::Human);
            }
            else if(i == 3 && j == 3){
                board_->SetSquareValue(pos,SquareType::Exit);
            }
            else if(i == 2 && j == 0){
                board_->SetSquareValue(pos,SquareType::Enemy);
                //intitlize enemy player
            }
            else if(i == 3 && j == 0){
                board_->SetSquareValue(pos,SquareType::Enemy);
                //initilize enemy player
            }
            else{
                //cout << "In Random" << endl;
                RandIndex = rand() % 10;
                if(a[RandIndex] == 0){
                    board_->SetSquareValue(pos,SquareType::Empty);
                }
                else if(a[RandIndex] == 1){
                    board_->SetSquareValue(pos,SquareType::Wall);
                }
                else if(a[RandIndex] == 2){
                    board_->SetSquareValue(pos,SquareType::Treasure);
                }
            }
        }
    }
}

bool Maze::TakeTurn(Player *p){
    //cout << "In Take Turn" << endl;
    //cout << "Get Moves =" << board_ -> GetMoves(p) << endl;
    vector<Position> moves;
    string nmove;
    string move;
    //bool exit = false;
    //cout << "Past Vector Decleration" << endl;
    moves = board_->GetMoves(p);
    //cout << "got moves" << endl;
    //cout << p->get_name() << " has possible moves: ";
    int s = moves.size();
    if(s == 0){
        cout << "No Possible Moves Game Over" << endl;
        return false;
    }
    //cout << "Size = " << s << endl;
    //cout << moves[0].col << moves[0].row << endl;
    for(int i=0;i<s;i++){
        move = p->ToRelativePosition(moves[i]);
        cout << move << ", ";
    }
    //cout << "Size of Moves" << moves << endl;
    cout << endl;
    cout << "Please Enter Your Next Moves" << endl;
    cin >> nmove;
    Position old = p->get_position();
    //cout << "Old Position = " << old.col << old.row << endl;
        if (nmove == "LEFT"){
            //move player position left
            old.col = old.col - 1;
            //cout << "New Position = " << old.col << old.row << endl;
            board_ -> MovePlayer(p,old);
        }
        else if (nmove == "RIGHT"){
            //move player position left;
            old.col = old.col + 1;
            //cout << "New Position = " << old.col << old.row << endl;
            board_ -> MovePlayer(p,old);
        }
        else if (nmove == "UP"){
            //move player position left
            old.col = old.row - 1;
           // cout << "New Position = " << old.col << old.row << endl;
            board_ -> MovePlayer(p,old);
        }
        else if (nmove == "DOWN"){
            old.col = old.row + 1;
            //cout << "New Position = " << old.col << old.row << endl;
            board_ -> MovePlayer(p,old);
        }
        else
            cout << "Please enter valid input" << endl;
    return true;
}

bool Maze::IsGameOver(Player *p){
    Position ifend = p->get_position();
    if(ifend.row == board_->get_rows() && ifend.col == board_->get_cols()){
        return true;
    }
    else{
        return false;
    }
}

void Maze::GenerateReport(Player* p){
    if(IsGameOver(p)){
        cout << "GAME OVER" << endl;
        string name = p->get_name();
        int points = p->get_points();
        cout << name << "Finished With" << points << "Points" << endl;
    }
    else{
        int count = 0;
        cout << p->Stringify() << endl;
        Position pos;
        for(int i=0;i<board_->get_cols();i++){
            for(int j=0;j<board_->get_rows();j++){
                pos.col = i;
                pos.row = j;
                SquareType sv = board_->get_square_value(pos);
                if(count != board_->get_cols()-1){
                    cout << SquareTypeStringify(sv) << " ";
                    count++;
                }
                else{
                    cout << SquareTypeStringify(sv) << endl;
                    count = 0;
                }
            }
        }
    }
}