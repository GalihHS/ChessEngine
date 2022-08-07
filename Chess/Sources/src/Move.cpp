#include "../inc/Coordinates.hpp"

Move::Move(const Coordinates *start, const Coordinates* end){
    this->start = new Coordinates(start);
    this->end = new Coordinates(end);
}

Move::~Move(){
    delete start;
    delete end;
}

Coordinates *Move::getStart(){
    return start;
}

Coordinates *Move::getEnd(){
    return end;
}