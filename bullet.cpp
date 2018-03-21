#include "bullet.h"

Bullet::Bullet(shared_ptr<Object> owner):Object(0, 0)
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
    case UP: nextAction = A_UP;  coordX = owner.get()->getX(); coordY = owner.get()->getY() - 1;
        break;
    case DOWN: nextAction = A_DOWN; coordX = owner.get()->getX(); coordY = owner.get()->getY() + 1;
        break;
    case RIGHT: nextAction = A_RIGHT; coordX = owner.get()->getX() + 1; coordY = owner.get()->getY();
        break;
    case LEFT: nextAction = A_LEFT; coordX = owner.get()->getX() - 1; coordY = owner.get()->getY();
        break;
    }
}
