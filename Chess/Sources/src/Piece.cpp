#include "../inc/Piece.hpp"

Piece::Piece(int coord, Color color){
    currentPosition = new Coordinates(coord);
    this->color = color;
}

Piece::Piece(const Coordinates *coord, Color color){
    currentPosition = new Coordinates(coord);
    this->color = color;
}

Piece::~Piece(){
    delete currentPosition;
}

Coordinates *Piece::getCoord() const{
    return currentPosition;
}

Color Piece::getColor() const{
    return color;
}

void Piece::move(const Coordinates *coord){
    delete currentPosition;
    currentPosition = new Coordinates(coord);
}

unsigned short int Piece::getNbOfPossibleMoves() const{
    return possibleMoves.size();
}

Coordinates *Piece::getPossibleMove(const unsigned long int k) const{
    return possibleMoves[k];
}

King::King(int coord, Color color) : Piece(coord, color){}

King::King(const Coordinates *coord, Color color) : Piece(coord, color){}

King::King(const King* king) : Piece(king->getCoord(), king->getColor()){}

King::~King(){}

void King::calculatePossibleMoves(std::vector<Piece*> *context){

}

void King::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "K";
}

Queen::Queen(int coord, Color color) : Piece(coord, color){}

Queen::Queen(const Coordinates *coord, Color color) : Piece(coord, color){}

Queen::Queen(const Queen* queen) : Piece(queen->getCoord(), queen->getColor()){}

Queen::~Queen(){}

void Queen::calculatePossibleMoves(std::vector<Piece*> *context){
    
}

void Queen::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "Q";
}

Rook::Rook(int coord, Color color) : Piece(coord, color){}

Rook::Rook(const Coordinates *coord, Color color) : Piece(coord, color){}

Rook::Rook(const Rook* rook) : Piece(rook->getCoord(), rook->getColor()){}

Rook::~Rook(){}

void Rook::calculatePossibleMoves(std::vector<Piece*> *context){
    
}

void Rook::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "R";
}

Bishop::Bishop(int coord, Color color) : Piece(coord, color){}

Bishop::Bishop(const Coordinates *coord, Color color) : Piece(coord, color){}

Bishop::Bishop(const Bishop* bishop) : Piece(bishop->getCoord(), bishop->getColor()){}

Bishop::~Bishop(){}

void Bishop::calculatePossibleMoves(std::vector<Piece*> *context){
    unsigned short int k = 1;
    while(currentPosition->getRaw() + k < 8 && currentPosition->getColumn() + k < 8){
        possibleMoves.push_back(new Coordinates(currentPosition->getRaw() + k, currentPosition->getColumn() + k));
        k++;
    }
}

void Bishop::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "B";
}

Knight::Knight(int coord, Color color) : Piece(coord, color){}

Knight::Knight(const Coordinates *coord, Color color) : Piece(coord, color){}

Knight::Knight(const Knight* knight) : Piece(knight->getCoord(), knight->getColor()){}

Knight::~Knight(){}

void Knight::calculatePossibleMoves(std::vector<Piece*> *context){
    
}

void Knight::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "Kn";
}

Pawn::Pawn(int coord, Color color) : Piece(coord, color){}

Pawn::Pawn(const Coordinates *coord, Color color) : Piece(coord, color){}

Pawn::Pawn(const Pawn* pawn) : Piece(pawn->getCoord(), pawn->getColor()){}

Pawn::~Pawn(){}

void Pawn::calculatePossibleMoves(std::vector<Piece*> *context){
    
}

void Pawn::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "P";
}