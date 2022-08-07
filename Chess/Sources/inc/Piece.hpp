#ifndef PIECE_HPP_
#define PIECE_HPP_

#include "Coordinates.hpp"
#include <vector>
#include <iostream>
#include <math.h>

enum class Color{BLACK, WHITE};

class Piece{
    public:
    Piece(int coord, Color color);
    Piece(const Coordinates *coord, Color color);
    ~Piece();

    Color getColor() const;
    Coordinates *getCoord() const;
    void move(const Coordinates *coord);

    virtual void calculatePossibleMoves(const std::vector<Piece*> *context) =0;
    unsigned short int getNbOfPossibleMoves() const;
    Coordinates* getPossibleMove(const unsigned long int k) const;

    virtual void printPiece() const =0;
    
    protected:
    bool canGoOnSquare(int raw, int column, const std::vector<Piece*> *context) const;

    Color color;
    Coordinates* currentPosition;
    std::vector<Coordinates*> possibleMoves;
};

class Knight : public Piece{
    public:
    Knight(int coord, Color color);
    Knight(const Coordinates *coord, Color color);
    Knight(const Knight* knight);
    virtual ~Knight();

    void calculatePossibleMoves(const std::vector<Piece*> *context);

    void printPiece() const;
};

class Bishop : public Piece{
    public:
    Bishop(int coord, Color color);
    Bishop(const Coordinates *coord, Color color);
    Bishop(const Bishop* bishop);
    virtual ~Bishop();

    void calculatePossibleMoves(const std::vector<Piece*> *context);

    void printPiece() const;
};

class Rook : public Piece{
    public:
    Rook(int coord, Color color);
    Rook(const Coordinates *coord, Color color);
    Rook(const Rook* rook);
    virtual ~Rook();

    void calculatePossibleMoves(const std::vector<Piece*> *context);

    void printPiece() const;
};

class Queen : public Piece{
    public:
    Queen(int coord, Color color);
    Queen(const Coordinates *coord, Color color);
    Queen(const Queen* queen);
    virtual ~Queen();

    void calculatePossibleMoves(const std::vector<Piece*> *context);

    void printPiece() const;
};

class King : public Piece{
    public:
    King(int coord, Color color);
    King(const Coordinates *coord, Color color);
    King(const King* king);
    virtual ~King();

    void calculatePossibleMoves(const std::vector<Piece*> *context);

    void printPiece() const;
};

class Pawn : public Piece{
    public:
    Pawn(int coord, Color color);
    Pawn(const Coordinates *coord, Color color);
    Pawn(const Pawn* pawn);
    virtual ~Pawn();

    void calculatePossibleMoves(const std::vector<Piece*> *context);

    void printPiece() const;
};

#endif