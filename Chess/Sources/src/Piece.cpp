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

    for (int i = 0; i < possibleMoves.size(); i++){
        delete possibleMoves[i];
    }
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

Knight::Knight(int coord, Color color) : Piece(coord, color){}

Knight::Knight(const Coordinates *coord, Color color) : Piece(coord, color){}

Knight::Knight(const Knight* knight) : Piece(knight->getCoord(), knight->getColor()){}

Knight::~Knight(){
}

void Knight::calculatePossibleMoves(const std::vector<Piece*> *context){
    int raw = getCoord()->getRaw();
    int column = getCoord()->getColumn();
    int newRaw = 0;
    int newColumn = 0;
    for (int i = 0; i < 2; i++){
        newRaw = raw + pow(-1, i) * 2;
        if (newRaw >= 0 && newRaw < 8){
            for (int j = 0; j < 2; j++){
                newColumn = column + pow(-1, j);
                if (newColumn >= 0 && newColumn < 8){
                    possibleMoves.push_back(new Coordinates(newRaw, newColumn));
                }
            }
        }
        newColumn = column + pow(-1, i) * 2;
        if (newColumn >= 0 && newColumn < 8){
            for (int j = 0; j < 2; j++){
                newRaw = raw + pow(-1, j);
                if (newRaw >= 0 && newRaw < 8){
                    possibleMoves.push_back(new Coordinates(newRaw, newColumn));
                }
            }
        }
    }
}

void Knight::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "Kn";
}

Bishop::Bishop(int coord, Color color) : Piece(coord, color){}

Bishop::Bishop(const Coordinates *coord, Color color) : Piece(coord, color){}

Bishop::Bishop(const Bishop* bishop) : Piece(bishop->getCoord(), bishop->getColor()){}

Bishop::~Bishop(){}

void Bishop::calculatePossibleMoves(const std::vector<Piece*> *context){
    int raw = getCoord()->getRaw();
    int column = getCoord()->getColumn();
    int newRaw = 0;
    int newColumn = 0;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            newRaw = raw + pow(-1, i);
            newColumn = column + pow(-1, j);
            while (newRaw >= 0 && newRaw < 8 && newColumn >= 0 && newColumn < 8){
                possibleMoves.push_back(new Coordinates(newRaw, newColumn));
                newRaw = newRaw + pow(-1, i);
                newColumn = newColumn + pow(-1, j);
            }
        }
    }
    

}

void Bishop::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "B";
}

Rook::Rook(int coord, Color color) : Piece(coord, color){}

Rook::Rook(const Coordinates *coord, Color color) : Piece(coord, color){}

Rook::Rook(const Rook* rook) : Piece(rook->getCoord(), rook->getColor()){}

Rook::~Rook(){}

void Rook::calculatePossibleMoves(const std::vector<Piece*> *context){
    int raw = getCoord()->getRaw();
    int column = getCoord()->getColumn();
    int newRaw = 0;
    int newColumn = 0;

    for (int i = 0; i < 2; i++){
        newRaw = raw + pow(-1, i);
        newColumn = column + pow(-1, i);

        while (newRaw >= 0 && newRaw < 8){
            possibleMoves.push_back(new Coordinates(newRaw, column));
            newRaw = newRaw + pow(-1, i);
        }

        while (newColumn >= 0 && newColumn < 8){
            possibleMoves.push_back(new Coordinates(raw, newColumn));
            newColumn = newColumn + pow(-1, i);
        }
    }
    

}

void Rook::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "R";
}