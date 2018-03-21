#ifndef WALL_H
#define WALL_H

#include "object.h"


class Wall : public Object
{
public:
    Wall(int xIn, int yIn,  int healthPointsIn = 1, DIRECTION directionIn = UP, ACTION nextActionIn = A_STOP);
};

#endif // WALL_H
