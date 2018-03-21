#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <memory>
#include <vector>

#include "object.h"

using namespace std;

class Battlefield
{
protected:
    int height;
    int width;
    vector< vector< shared_ptr<Object> > > field;
    void createBorders();
public:
    Battlefield(int heightIn, int widthIn);
    int getHeight();
    int getWidth();
    void drawField();
    bool addObject(shared_ptr<Object> objIn);
    bool moveObject(int fromX, int fromY, int whereX, int whereY);
    void deleteObject(int objX, int objY);
};

#endif // BATTLEFIELD_H
