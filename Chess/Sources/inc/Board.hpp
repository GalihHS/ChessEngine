#include "Piece.hpp"
#include <typeinfo>

class Board{
    public:
    Board();
    Board(Piece *p);
    Board(const Board* b);
    ~Board();

    const std::vector<Piece*> *getContext() const;

    unsigned long int getNbOfNextPositons() const;
    Board* getPosition(const unsigned long int k) const;
    void addPosition(const Board* b);

    void addPiece(const Piece* p);

    Piece* getBoardPos(const unsigned long int k) const;
    void printBoard() const;

    private:
    std::vector<Piece*> position;
    std::vector<Board*> nextPositions;
};