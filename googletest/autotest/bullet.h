#ifndef BULLET_H
#define BULLET_H

#include "object.h"

class Bullet : public Object
{
public:
    Bullet( shared_ptr<Object> owner);
    ACTION getAction();
};

#endif // BULLET_H
