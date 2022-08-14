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

const int Piece::canGoOnSquare(int raw, int column, const std::vector<Piece*> *context) const{
    if ((*context)[raw * 8 + column] == 0 ){
        return 1;
    }
    else if ((*context)[raw * 8 + column]->getColor() != color){
        return 2;
    }
    else{
        return 0;
    }
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
                    const int freeSquare = canGoOnSquare(newRaw, newColumn, context);
                    if (freeSquare > 0){
                        possibleMoves.push_back(new Coordinates(newRaw, newColumn));
                    }
                }
            }
        }
        newColumn = column + pow(-1, i) * 2;
        if (newColumn >= 0 && newColumn < 8){
            for (int j = 0; j < 2; j++){
                newRaw = raw + pow(-1, j);
                if (newRaw >= 0 && newRaw < 8){
                    const int freeSquare = canGoOnSquare(newRaw, newColumn, context);
                    if (freeSquare > 0){
                        possibleMoves.push_back(new Coordinates(newRaw, newColumn));
                    }
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
                const int freeSquare = canGoOnSquare(newRaw, newColumn, context);
                if (freeSquare > 0){
                    possibleMoves.push_back(new Coordinates(newRaw, newColumn));
                    newRaw = newRaw + pow(-1, i);
                    newColumn = newColumn + pow(-1, j);
                }
                if(freeSquare != 1){
                    break;
                }
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
        while (newRaw >= 0 & newRaw < 8){
            const int freeSquare = canGoOnSquare(newRaw, column, context);
            if (freeSquare > 0){
                possibleMoves.push_back(new Coordinates(newRaw, column));
                newRaw = newRaw + pow(-1, i);
            }
            if (freeSquare != 1){
                break;
            }
        }

        newColumn = column + pow(-1, i);
        while (newColumn >= 0 && newColumn < 8){
            const int freeSquare = canGoOnSquare(raw, newColumn, context);
            if (freeSquare > 0){
                possibleMoves.push_back(new Coordinates(raw, newColumn));
                newColumn = newColumn + pow(-1, i);
            }
            if (freeSquare != 1){
                break;
            }
        }
    }
}

void Rook::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "R";
}

Queen::Queen(int coord, Color color) : Piece(coord, color){}

Queen::Queen(const Coordinates *coord, Color color) : Piece(coord, color){}

Queen::Queen(const Queen* queen) : Piece(queen->getCoord(), queen->getColor()){}

Queen::~Queen(){}

void Queen::calculatePossibleMoves(const std::vector<Piece*> *context){
    int raw = getCoord()->getRaw();
    int column = getCoord()->getColumn();
    int newRaw = 0;
    int newColumn = 0;

    /* Rook moves */
    for (int i = 0; i < 2; i++){
        newRaw = raw + pow(-1, i);
        while (newRaw >= 0 & newRaw < 8){
            const int freeSquare = canGoOnSquare(newRaw, column, context);
            if (freeSquare > 0){
                possibleMoves.push_back(new Coordinates(newRaw, column));
                newRaw = newRaw + pow(-1, i);
            }
            if (freeSquare != 1){
                break;
            }
        }

        newColumn = column + pow(-1, i);
        while (newColumn >= 0 && newColumn < 8){
            const int freeSquare = canGoOnSquare(raw, newColumn, context);
            if (freeSquare > 0){
                possibleMoves.push_back(new Coordinates(raw, newColumn));
                newColumn = newColumn + pow(-1, i);
            }
            if (freeSquare != 1){
                break;
            }
        }
    }

    /* Bishop Moves */
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            newRaw = raw + pow(-1, i);
            newColumn = column + pow(-1, j);
            while (newRaw >= 0 && newRaw < 8 && newColumn >= 0 && newColumn < 8){
                const int freeSquare = canGoOnSquare(newRaw, newColumn, context);
                if (freeSquare > 0){
                    possibleMoves.push_back(new Coordinates(newRaw, newColumn));
                    newRaw = newRaw + pow(-1, i);
                    newColumn = newColumn + pow(-1, j);
                }
                if(freeSquare != 1){
                    break;
                }
            }
        }
    }
}

void Queen::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "Q";
}

King::King(int coord, Color color) : Piece(coord, color){}

King::King(const Coordinates *coord, Color color) : Piece(coord, color){}

King::King(const King* king) : Piece(king->getCoord(), king->getColor()){}

King::~King(){}

void King::calculatePossibleMoves(const std::vector<Piece*> *context){
    int raw = getCoord()->getRaw();
    int column = getCoord()->getColumn();

    for (int i = raw - 1; i < raw + 2; i++){
        for (int j = column - 1; j < column + 2; j++){
            if((i != column || j != raw) && i >= 0 && i < 8 && j >= 0 && j < 8){
                const int freeSquare = canGoOnSquare(i, j, context);
                if (freeSquare > 0){
                    possibleMoves.push_back(new Coordinates(i, j));
                }
            }
        }
    }
}

void King::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "K";
}

Pawn::Pawn(int coord, Color color) : Piece(coord, color){}

Pawn::Pawn(const Coordinates *coord, Color color) : Piece(coord, color){}

Pawn::Pawn(const Pawn* pawn) : Piece(pawn->getCoord(), pawn->getColor()){}

Pawn::~Pawn(){}

void Pawn::calculatePossibleMoves(const std::vector<Piece*> *context){
    int raw = getCoord()->getRaw();
    int column = getCoord()->getColumn();

    int columnTakesLeft = column - 1;
    int columnTakesRight = column + 1;

    if (color == Color::WHITE){
        if (raw == 1 && (*context)[(raw + 1) * 8 + column] == 0 && (*context)[(raw + 2) * 8 + column] == 0){
            possibleMoves.push_back(new Coordinates(raw + 2, column));
        }
        if (raw + 1 < 8){
            if ((*context)[(raw + 1) * 8 + column] == 0){
                possibleMoves.push_back(new Coordinates(raw + 1, column));
            }

            if (columnTakesLeft >= 0 && (*context)[(raw + 1) * 8 + columnTakesLeft] != 0 && (*context)[(raw + 1) * 8 + columnTakesLeft]->getColor() == Color::BLACK){
                possibleMoves.push_back(new Coordinates(raw + 1, columnTakesLeft));
            }

            if (columnTakesRight < 8 && (*context)[(raw + 1) * 8 + columnTakesRight] != 0 && (*context)[(raw + 1) * 8 + columnTakesRight]->getColor() == Color::BLACK){
                possibleMoves.push_back(new Coordinates(raw + 1, columnTakesRight));
            }
        }
    }
    else{
        if (raw == 6 && (*context)[(raw - 1) * 8 + column] == 0 && (*context)[(raw - 2) * 8 + column] == 0){
            possibleMoves.push_back(new Coordinates(raw - 2, column));
        }
        if (raw - 1 >= 0){
            if ((*context)[(raw - 1) * 8 + column] == 0){
                possibleMoves.push_back(new Coordinates(raw - 1, column));
            }

            if (columnTakesLeft >= 0 && (*context)[(raw - 1) * 8 + columnTakesLeft] != 0 && (*context)[(raw - 1) * 8 + columnTakesLeft]->getColor() == Color::WHITE){
                possibleMoves.push_back(new Coordinates(raw - 1, columnTakesLeft));
            }
            
            if (columnTakesRight < 8 && (*context)[(raw - 1) * 8 + columnTakesRight] != 0 && (*context)[(raw - 1) * 8 + columnTakesRight]->getColor() == Color::WHITE){
                possibleMoves.push_back(new Coordinates(raw - 1, columnTakesRight));
            }
        }
    }
}

void Pawn::printPiece() const{
    std::cout << (color == Color::WHITE? "w" : "b") << "P";
}