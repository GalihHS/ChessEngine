#include "../inc/Board.hpp"

int main(){
    Board *b = new Board();
    b->printBoard();
    
    delete b;
}