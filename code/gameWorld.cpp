#include "gameWorld.h"

GameWorld::GameWorld(int _width,int _length){
    width=_width;
    length=_length;
    setUpWorld();
}

void GameWorld::setUpWorld()
{
    float x=0,y=0;
    for(int i=0;i<width;i++)
    {
        std::vector<GameTile>rows;
        for(int j=0;j<length;j++)
        {
            rows.emplace_back(GameTile(x,y,sf::Vector2f(15.f,15.f)));
            x+=15.f;
        }
        tiles.emplace_back(rows);
        y+=15.f;
        x=0.f;
    }
}

void GameWorld::createWalls(sf::Vector2i mouse_pos)
{
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(tiles[i][j].rec.getGlobalBounds().contains(sf::Vector2f(mouse_pos.x,mouse_pos.y)))
                    tiles[i][j].changeToWall();
            }
        }
}

void GameWorld::destroyingOldStart()
{
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(tiles[i][j].isStart)
                    tiles[i][j].noLongerStart();
            }

        }
}

void GameWorld::startingPosition(sf::Vector2i mouse_pos)
{
    // Removing old starting point
    destroyingOldStart();


        for(int i=0;i<width;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(tiles[i][j].rec.getGlobalBounds().contains(sf::Vector2f(mouse_pos.x,mouse_pos.y)))
                    tiles[i][j].changeToStaritingPoint();
            }

        }

        //Checking to get only one starting point
        int counter=0;
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(tiles[i][j].isStart)
                {
                    counter++;
                    if(counter>1)
                        tiles[i][j].noLongerStart();
                    
                    pos_start.y=i;
                    pos_start.x=j;
                }
                
            }

        }
}

void GameWorld::destroyingOldEnd()
{
            for(int i=0;i<width;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(tiles[i][j].isExit)
                    tiles[i][j].noLongerEnd();
            }

        }
}

void GameWorld::endingPosition(sf::Vector2i mouse_pos)
{
    // Removing old starting point
    destroyingOldEnd();


        for(int i=0;i<width;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(tiles[i][j].rec.getGlobalBounds().contains(sf::Vector2f(mouse_pos.x,mouse_pos.y)))
                    tiles[i][j].changeToExitPoint();
            }

        }

        //Checking to get only one starting point
        int counter=0;
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(tiles[i][j].isExit==true)
                {
                    counter++;
                    if(counter>1)
                        tiles[i][j].noLongerStart();

                    pos_end.y=i;
                    pos_end.x=j;
                }
                
            }

        }
}


void GameWorld::draw(sf::RenderWindow &window)
{
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<length;j++)
            {
                window.draw(tiles[i][j].rec);
            }
        }
}

void GameWorld::reset()
{
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<length;j++)
        {
            tiles[i][j].reset();
        }
    }
}