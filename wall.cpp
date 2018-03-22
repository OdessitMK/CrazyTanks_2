#include "wall.h"

Wall::Wall(const int &xIn, const int &yIn, const int &healthPointsIn, const DIRECTION &directionIn, const ACTION &nextActionIn ): Object( xIn, yIn, healthPointsIn, directionIn, nextActionIn )
{
    type = WALL;
    visualizasion = 'X';
}
