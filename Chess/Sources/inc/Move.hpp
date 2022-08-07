#include "Coordinates.hpp"

class Move{
    public:
    Move(const Coordinates *start, const Coordinates *end);
    ~Move();

    Coordinates *getStart();
    Coordinates *getEnd();

    private:
    Coordinates *start;
    Coordinates *end;
};