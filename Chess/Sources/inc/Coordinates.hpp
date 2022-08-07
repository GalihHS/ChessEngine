#ifndef COORDINATES_HPP_
#define COORDINATES_HPP_

class Coordinates{
    public:
    Coordinates(unsigned short int n);
    Coordinates(unsigned short int raw, unsigned short int column);
    Coordinates(const Coordinates *coord);
    ~Coordinates();

    unsigned short int getColumn() const;
    unsigned short int getRaw() const;
    unsigned short int getMergedCoord() const;

    void setNewCoords(unsigned short int column, unsigned short int raw);
    void setNewCoords(unsigned short int n);

    void printCoordinates() const;
    
    private:
    unsigned short int raw;
    unsigned short int column;
    unsigned int mergedCoord;
};

#endif