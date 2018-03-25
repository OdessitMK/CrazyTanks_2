#include "battlefield.h"
#include "wall.h"
#include <iostream>
#include <windows.h>

void setCursor(const int &x, const int &y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Battlefield::createBorders()
{
    for (int x = 0; x < width; x++)
    {
        addObject( shared_ptr<Object>( new Wall( x, 0, 9999) ) );
        addObject( shared_ptr<Object>( new Wall( x, height - 1, 9999) ) );
    }
    for (int y = 1; y < height - 1; y++)
    {
        addObject( shared_ptr<Object>( new Wall( 0, y, 9999) ) );
        addObject( shared_ptr<Object>( new Wall( width - 1, y, 9999) ) );
    }
}

Battlefield::Battlefield(const int heightIn, const int widthIn):height(heightIn), width(widthIn)
{
    for (int y = 0; y < height; y++)
    {
        auto newVec = new vector< shared_ptr<Object> >; //"to implement" reserve( size_type new_cap );
        for (int x = 0; x < width; x++)
            newVec->push_back(nullptr);
        field.push_back(*newVec);
    }
    createBorders();
}

int Battlefield::getHeight()
{
    return height;
}

int Battlefield::getWidth()
{
    return width;
}

void Battlefield::drawField()
{
    for ( int y = 0; y < height; y++)
    {
        for ( int x = 0; x < width; x++)
            if ( field[y][x] != nullptr )
                drawPosition(x,y);
    }
}

bool Battlefield::addObject(shared_ptr<Object> objIn)
{
    bool returnBool;
    if ( (objIn.get()->getY() < height) && (objIn.get()->getX() < width) )
    {
        if (field.at( objIn.get()->getY() ).at( objIn.get()->getX() ) == nullptr )
        {
            field.at( objIn.get()->getY() ).at( objIn.get()->getX() ) = objIn;
            drawPosition(objIn.get()->getX(), objIn.get()->getY());
            returnBool = true;
        }
        else
        if ( ( objIn.get()->getType() == AI_BULLET ) || ( objIn.get()->getType() == PLAYER_BULLET ) )
        {
            field.at( objIn.get()->getY() ).at( objIn.get()->getX() ).get()->collision( objIn );
            drawPosition(objIn.get()->getX(), objIn.get()->getY());
            returnBool = false;
        } else returnBool = false;
    }    
    return returnBool;
}

bool Battlefield::moveObject(const int &fromX, const int &fromY, const int &whereX, const int &whereY)
{
    bool returnMove;
    if (field.at( whereY ).at( whereX ) == nullptr )
    {
        field.at( fromY ).at( fromX ).get()->move( whereX, whereY );
        field.at( whereY ).at( whereX ).swap( field.at( fromY ).at( fromX ) );
        drawPosition(fromX, fromY);
        drawPosition(whereX, whereY);
        returnMove = true;
    }
    else
    {
       field.at( whereY ).at( whereX ).get()->collision( field.at( fromY ).at( fromX ) );
       field.at( fromY ).at( fromX ).get()->collision(field.at( whereY ).at( whereX ));
       returnMove = false;
    }
    return returnMove;
}

void Battlefield::deleteObject(const int &objX, const int &objY)
{
    field.at( objY ).at( objX ) = nullptr;
    drawPosition(objX, objY);
}

void Battlefield::drawPosition(const int &objX, const int &objY)
{
    setCursor( objX * 2, objY + 1);
    if ( field.at( objY ).at( objX ) == nullptr )
    {
        cout << "  ";
    }
    else
    {
        cout << field[objY].at(objX).get()->getVisualization() << field[objY].at(objX).get()->getVisualization(); //2 time for visualy pleasant view
    }
}
