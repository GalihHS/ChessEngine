#include "../inc/Board.hpp"

Board::Board(){
    nextPositions = std::vector<Board*>(0);
    position = std::vector<Piece*>(64, 0);
    /*for(unsigned long int k = 0; k < 8; k++){
        position[8 + k] = new Pawn(8 + k, Color::WHITE);
        position[48 + k] = new Pawn(48 + k, Color::BLACK);
    }*/

   
    position[1] = new Knight(1, Color::WHITE);
    position[6] = new Knight(6, Color::WHITE);
    

    position[57] = new Knight(57, Color::BLACK);
    position[62] = new Knight(62, Color::BLACK);
    
}

Board::Board(const Board* b){
    for(unsigned long int k = 0; k < 64; k++){
        Piece *p = b->getBoardPos(k);
        if(p == 0){
            position.push_back(0);
        }
        else{
            if(typeid(*p) == typeid(Knight)){
                position.push_back(new Knight((Knight*)p));
            }
            else if(typeid(*p) == typeid(Bishop)){
                position.push_back(new Bishop((Bishop*)p));
            }
            else if(typeid(*p) == typeid(Rook)){
                position.push_back(new Rook((Rook*)p));
            }
            else if(typeid(*p) == typeid(Queen)){
                position.push_back(new Queen((Queen*)p));
            }
            else if(typeid(*p) == typeid(King)){
                position.push_back(new King((King*)p));
            }
            else if(typeid(*p) == typeid(Pawn)){
                position.push_back(new Pawn((Pawn*)p));
            }
        }
    }

    nextPositions = std::vector<Board*>(0);
    for(unsigned long int k = 0; k < b->getNbOfNextPositons(); k++){
        nextPositions.push_back(b->getPosition(k));
    }
}

Board::Board(Piece* p){
    unsigned short int coord = p->getCoord()->getMergedCoord();
    nextPositions = std::vector<Board*>(0);
    position = std::vector<Piece*>(64, 0);
    if(typeid(*p) == typeid(Knight)){
        position[coord] = new Knight((Knight*)p);
    }
    else if(typeid(*p) == typeid(Bishop)){
        position[coord] = new Bishop((Bishop*)p);
    }
    else if(typeid(*p) == typeid(Rook)){
        position[coord] = new Rook((Rook*)p);
    }
    else if(typeid(*p) == typeid(Queen)){
        position[coord] = new Queen((Queen*)p);
    }
    else if(typeid(*p) == typeid(King)){
        position[coord] = new King((King*)p);
    }
    else if(typeid(*p) == typeid(Pawn)){
        position[coord] = new Pawn((Pawn*)p);
    }
}

Board::~Board(){
    for(unsigned long int k = 0; k < position.size(); k++){
        if(position[k] != 0){
            delete position[k];
        }
    }

    for(unsigned long int k = 0; k < nextPositions.size(); k++){
        delete nextPositions[k];
    }
}

const std::vector<Piece*> *Board::getContext() const{
    return &position;
}

unsigned long int Board::getNbOfNextPositons() const{
    return nextPositions.size();
}

Board* Board::getPosition(const unsigned long int k) const{
    return nextPositions[k];
}

void Board::addPosition(const Board* b){
    nextPositions.push_back(new Board(b));
}

void Board::addPiece(const Piece* p){
    unsigned short int coord = p->getCoord()->getMergedCoord();
    if(typeid(*p) == typeid(Knight)){
        position[coord] = new Knight((Knight*)p);
    }
    else if(typeid(*p) == typeid(Bishop)){
        position[coord] = new Bishop((Bishop*)p);
    }
    else if(typeid(*p) == typeid(Rook)){
        position[coord] = new Rook((Rook*)p);
    }
    else if(typeid(*p) == typeid(Queen)){
        position[coord] = new Queen((Queen*)p);
    }
    else if(typeid(*p) == typeid(King)){
        position[coord] = new King((King*)p);
    }
    else if(typeid(*p) == typeid(Pawn)){
        position[coord] = new Pawn((Pawn*)p);
    }
}

Piece* Board::getBoardPos(const unsigned long int k) const{
    return position[k];
}

void Board::printBoard() const{
    for(short int line = 7; line >= 0; line--){
        std::cout << std::endl;
        for(short int column = 0; column < 8; column++){
            if(position[line * 8 + column] != 0){
                position[line * 8 + column]->printPiece();
                std::cout << " ";
            }
            else{
                std::cout << " V ";
            }
        }
    }
    std::cout << std::endl;
}