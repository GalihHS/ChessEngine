#include "../inc/Board.hpp"

int main(){
    int square = 9;
    Pawn *knight = new Pawn(square, Color::WHITE);

    Knight *k1 = new Knight(18, Color::BLACK);
    Knight *k2 = new Knight(16, Color::BLACK);
    Board *b = new Board(knight);
    b->addPiece(k1);
    b->addPiece(k2);
    b->printBoard();
    b->getBoardPos(square)->calculatePossibleMoves(b->getContext());
    int mvs = b->getBoardPos(square)->getNbOfPossibleMoves();
    std::cout << mvs << std::endl;

    for (int i = 0; i < mvs; i++){
        b->getBoardPos(square)->getPossibleMove(i)->printCoordinates();
    }
    

    delete knight;
    delete b;
    delete k1;
}