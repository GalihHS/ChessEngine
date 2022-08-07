#include "../inc/Coordinates.hpp"
#include <iostream>

using namespace std;

Coordinates::Coordinates(unsigned short int n){
    mergedCoord = n;
    column = n % 8;
    raw = n / 8;
}

Coordinates::Coordinates(unsigned short int raw, unsigned short int column){
    this->raw = raw;
    this->column = column;
    mergedCoord = raw * 8 + column;
}

Coordinates::Coordinates(const Coordinates *coord){
    mergedCoord = coord->getMergedCoord();
    column = coord->getColumn();
    raw = coord->getRaw();
}

Coordinates::~Coordinates(){
}

unsigned short int Coordinates::getColumn() const{
    return column;
}

unsigned short int Coordinates::getRaw() const{
    return raw;
}

unsigned short int Coordinates::getMergedCoord() const{
    return mergedCoord;
}

void Coordinates::setNewCoords(unsigned short int column, unsigned short int raw){
    this->column = column;
    this->raw = raw;
    mergedCoord = raw * 8 + column;
}

void Coordinates::setNewCoords(unsigned short int n){
    mergedCoord = n;
    column = n % 8;
    raw = n / 8;
}

void Coordinates::printCoordinates() const{
    std::cout << "Raw is: " << raw;
    std::cout << ", column is: " << column; 
    std::cout << ", so the merged coordinates are: " << mergedCoord << std::endl; 
}