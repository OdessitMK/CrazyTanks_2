#ifndef WALL_H
#define WALL_H

#include "object.h"


class Wall : public Object
{
public:
    Wall(const int &xIn, const int &yIn, const int &healthPointsIn = 1, const DIRECTION &directionIn = UP, const ACTION &nextActionIn = A_STOP);
};

#endif // WALL_H
