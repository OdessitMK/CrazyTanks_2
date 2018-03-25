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
    A_HIT,
    A_CONTINUE
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
    Object( const int &xIn, const int &yIn,const int &healthPointsIn = 1, const DIRECTION &directionIn = UP, const ACTION &nextActionIn = A_STOP);
    void move(const int &xIn, const int &yIn);
    int getX();
    int getY();
    TYPE getType();
    char getVisualization();
    DIRECTION getDirection();
    void changeDirection( const DIRECTION &directionIn );
    int getHealthPoints();
    virtual void hit();
    virtual ACTION getAction();
    void changeAction( const ACTION &actionIn );
    void collision(const shared_ptr<Object> objIn);
};

#endif // OBJECT_H















