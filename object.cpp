#include "object.h"

const ACTION Object::collisionTable[6][6] = {{A_STOP,A_STOP,A_STOP,A_STOP,A_STOP,A_HIT},
                                             {A_STOP,A_STOP,A_STOP,A_STOP,A_HIT,A_STOP},
                                             {A_CONTINUE,A_CONTINUE,A_STOP,A_STOP,A_HIT,A_HIT},
                                             {A_STOP,A_HIT,A_STOP,A_STOP,A_STOP,A_HIT},
                                             {A_DESTROY,A_DESTROY,A_DESTROY,A_DESTROY,A_DESTROY,A_DESTROY},
                                             {A_DESTROY,A_DESTROY,A_DESTROY,A_DESTROY,A_DESTROY,A_DESTROY},};

Object::Object(int xIn, int yIn, int healthPointsIn, DIRECTION directionIn, ACTION nextActionIn):coordX(xIn),coordY(yIn),healthPoints(healthPointsIn),direction(directionIn),nextAction(nextActionIn)
{

}

void Object::move(int xIn, int yIn)
{
    coordX = xIn;
    coordY = yIn;
}

int Object::getX()
{
    return coordX;
}

int Object::getY()
{
    return coordY;
}

TYPE Object::getType()
{
    return type;
}

char Object::getVisualization()
{
    return visualizasion;
}

DIRECTION Object::getDirection()
{
    return direction;
}

void Object::changeDirection(DIRECTION directionIn)
{
    direction = directionIn;
}

int Object::getHealthPoints()
{
    return healthPoints;
}

void Object::hit()
{
    --healthPoints;
    if (healthPoints < 1) nextAction = A_DESTROY;
}

ACTION Object::getAction()
{
        ACTION acc = nextAction;
        changeAction( A_STOP );
        return acc;
}

void Object::changeAction(ACTION actionIn)
{
    if ((nextAction != A_HIT) || (nextAction != A_DESTROY))
    {nextAction = actionIn;}
}

void Object::collision(shared_ptr<Object> objIn)
{
    if (Object::collisionTable[ this->getType() ][ objIn.get()->getType() ] != A_CONTINUE)
        changeAction( Object::collisionTable[ this->getType() ][ objIn.get()->getType() ] );
}
