#include "bullet.h"

Bullet::Bullet(shared_ptr<Object> owner, int xIn, int yIn):Object(xIn, yIn)
{
    if ( owner.get()->getType() == AI )
    {
        type = AI_BULLET;
        visualizasion = 'o';
    }
    else
    {
        type = PLAYER_BULLET;
        visualizasion = '*';
    }
    healthPoints = 0;
    direction = owner.get()->getDirection();
    switch(direction)
    {
    case UP: nextAction = A_UP;
        break;
    case DOWN: nextAction = A_DOWN;
        break;
    case RIGHT: nextAction = A_RIGHT;
        break;
    case LEFT: nextAction = A_LEFT;
        break;
    }
}
