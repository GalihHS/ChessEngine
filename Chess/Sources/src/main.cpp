#include "../inc/Board.hpp"

int main(){
    Bishop *bis = new Bishop(17, Color::WHITE);
    Board *b = new Board(bis);
    b->printBoard();
    b->getBoardPos(17)->calculatePossibleMoves(b->getContext());
    std::cout << b->getBoardPos(17)->getNbOfPossibleMoves() << std::endl;

    delete bis;
    delete b;
}