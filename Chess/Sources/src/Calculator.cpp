#include "../inc/Calculator.hpp"

Calculator::Calculator(){
    possibleMoves = std::vector<Move*>(0);
    b = new Board();
}

Calculator::~Calculator(){
    delete b;
    
    for(unsigned long int k = 0; k < possibleMoves.size(); k++){
        delete possibleMoves[k];
    }
}

unsigned long int Calculator::getNbOfPossibleMoves() const{
    return possibleMoves.size();
}

Move* Calculator::getMove(const unsigned long int k) const{
    return possibleMoves[k];
}