#include "../inc/Board.hpp"

int main(){
    int square = 0;
    King *knight = new King(square, Color::WHITE);
    Board *b = new Board(knight);
    b->printBoard();
    b->getBoardPos(square)->calculatePossibleMoves(b->getContext());
    int mvs = b->getBoardPos(square)->getNbOfPossibleMoves();
    std::cout << mvs << std::endl;

    for (int i = 0; i < mvs; i++){
        b->getBoardPos(square)->getPossibleMove(i)->printCoordinates();
    }
    

    delete knight;
    delete b;
}