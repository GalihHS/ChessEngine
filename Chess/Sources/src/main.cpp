#include "../inc/Board.hpp"

int main(){
    Rook *r = new Rook(2, Color::WHITE);
    Rook *r2 = new Rook(10, Color::BLACK);
     Rook *r3 = new Rook(5, Color::WHITE);
    Board *b = new Board(r);
    b->addPiece(r2);
    b->addPiece(r3);
    b->printBoard();

    const std::vector<Piece*> *context = b->getContext();
    int total_moves = 0;

    for (int i = 0; i < 64; i++){
        if((*context)[i] != 0 && (*context)[i]->getColor() == Color::WHITE){
            (*context)[i]->calculatePossibleMoves(context);
            total_moves = total_moves + (*context)[i]->getNbOfPossibleMoves();
        }
    }
    std::cout << total_moves << std::endl;

    for (int i = 0; i < (*context)[2]->getNbOfPossibleMoves(); i++){
        (*context)[2]->getPossibleMove(i)->printCoordinates();
    }
    
    delete b;
    delete r;
    delete r2;
    delete r3;
}