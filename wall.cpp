#include "wall.h"

Wall::Wall( int xIn, int yIn, int healthPointsIn, DIRECTION directionIn, ACTION nextActionIn ): Object( xIn, yIn, healthPointsIn, directionIn, nextActionIn )
{
    type = WALL;
    visualizasion = 'X';
}
