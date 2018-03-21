#include "battlefield.h"
#include "wall.h"
#include <iostream>

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

Battlefield::Battlefield(int heightIn, int widthIn)
{
    for (int y = 0; y < heightIn; y++)
    {
        auto newVec = new std::vector< shared_ptr<Object> >; //"to implement" reserve( size_type new_cap );
        for (int x = 0; x < widthIn; x++)
            newVec->push_back(nullptr);
        field.push_back(*newVec);
    }
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
    cout << endl;
    for ( int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
            if ( field[i][j] == nullptr ) cout << "  ";
            else cout << field[i].at(j).get()->getVisualization() << field[i].at(j).get()->getVisualization(); //2 time for visualy pleasant view
        cout << endl;
    }
}

bool Battlefield::addObject(shared_ptr<Object> objIn)
{
    if ( (objIn.get()->getY() < height) && (objIn.get()->getX() < width) )
    {
        if (field.at( objIn.get()->getY() ).at( objIn.get()->getX() ) == nullptr )
        {
            field.at( objIn.get()->getY() ).at( objIn.get()->getX() ) = objIn;
            return true;
        }
        else
        if ( ( objIn.get()->getType() == AI_BULLET ) || ( objIn.get()->getType() == PLAYER_BULLET ) )
            field.at( objIn.get()->getY() ).at( objIn.get()->getX() ).get()->collision( objIn );
    }
    return false;
}

bool Battlefield::moveObject(int fromX, int fromY, int whereX, int whereY)
{
    if (field.at( whereY ).at( whereX ) == nullptr )
    {
        field.at( fromY ).at( fromX ).get()->move( whereX, whereY );
        field.at( whereY ).at( whereX ).swap( field.at( fromY ).at( fromX ) );
    }
    else
    {
       field.at( whereY ).at( whereX ).get()->collision( field.at( fromY ).at( fromX ) );
       field.at( fromY ).at( fromX ).get()->collision(field.at( whereY ).at( whereX ));
    }
    return true;
}

void Battlefield::deleteObject(int objX, int objY)
{
    field.at( objY ).at( objX ) = nullptr;
}
