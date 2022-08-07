#include "../inc/Board.hpp"

int main(){
    Board *b = new Board();
    b->printBoard();

    const std::vector<Piece*> *context = b->getContext();
    int total_moves = 0;

    for (int i = 0; i < 64; i++){
        if((*context)[i] != 0 && (*context)[i]->getColor() == Color::BLACK){
            (*context)[i]->calculatePossibleMoves(context);
            total_moves = total_moves + (*context)[i]->getNbOfPossibleMoves();
        }
    }
    std::cout << total_moves << std::endl;
    
    delete b;
}