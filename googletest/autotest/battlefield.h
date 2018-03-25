#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

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
    Battlefield(const int heightIn, const int widthIn);
    int getHeight();
    int getWidth();
    void drawField();
    bool addObject(shared_ptr<Object> objIn);
    bool moveObject(const int &fromX, const int &fromY, const int &whereX, const int &whereY);
    void deleteObject(const int &objX, const int &objY);
    void drawPosition(const int &objX, const int &objY);
};

#endif // BATTLEFIELD_H
