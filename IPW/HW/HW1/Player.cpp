#include "Player.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Player::Player(const string name, const bool is_human, Position start){
    name_ = name;
    is_human_ = is_human;
    pos_ = start;
    points_ = 0;
}

void Player::ChangePoints(const int x){
    points_ = x;
}

void Player::SetPosition(Position pos){
    pos_ = pos; 
}

string Player::ToRelativePosition(Position other){
    if(other.row == this->pos_.row && other.col != this->pos_.col){
        if(other.col < this->pos_.col){
            return "UP";
        }else{
            return "DOWN";
        }
    }if(other.row != this->pos_.row && other.col == this->pos_.col){
        if(other.row < this->pos_.row){
            return "LEFT";
        }else{
            return "RIGHT";
        }
    }else{
        return "NOT REACHABLE";
    }
}

string Player::Stringify(){
    string s0 = "has";
    string s1 = "points";
    string s2 = to_string(points_);
    string s = name_ + " " + s0 + " " + s2 + " " + s1;
    return s;
    
}

