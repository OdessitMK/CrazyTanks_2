#ifndef OBJECT_H
#define OBJECT_H

#include <memory>

using namespace std;

enum ACTION
{
    A_UP,
    A_DOWN,
    A_LEFT,
    A_RIGHT,
    A_SHOOT,
    A_DESTROY,
    A_STOP,
    A_HIT
};

enum DIRECTION
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum TYPE
{
    PLAYER,
    AI,
    WALL,
    GOLD,
    PLAYER_BULLET,
    AI_BULLET
};

class Object
{
protected:
    TYPE type;
    int coordX;
    int coordY;
    int healthPoints;
    char visualizasion;
    DIRECTION direction;
    ACTION nextAction;
    const static ACTION collisionTable[6][6];
public:
    Object( int xIn, int yIn, int healthPointsIn = 1, DIRECTION directionIn = UP, ACTION nextActionIn = A_STOP);
    void move(int xIn, int yIn);
    int getX();
    int getY();
    TYPE getType();
    char getVisualization();
    DIRECTION getDirection();
    void changeDirection( DIRECTION directionIn );
    int getHealthPoints();
    void hit();
    ACTION getAction();
    void changeAction( ACTION actionIn );
    void collision(shared_ptr<Object> objIn);

    //char operator<<( Object &obj );

};

#endif // OBJECT_H















