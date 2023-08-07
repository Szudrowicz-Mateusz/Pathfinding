#include "Astar.h"

// Binder
inline void binder(GameWorld& gameWorld,char y, char x, sf::Vector2<char>& parent_pos)
{
    sf::Vector2<char> pos;
    pos.y=y;
    pos.x=x;

    gameWorld.tiles[pos.y][pos.x].parent_pos=parent_pos;

    setHCost(gameWorld,pos);
    setGCost(gameWorld,pos);
    setFCost(gameWorld,pos);
}

// Distance from end position to our end point
inline void setHCost(GameWorld& gameWorld,sf::Vector2<char>& pos)
{
    gameWorld.tiles[pos.y][pos.x].H_cost = sqrt( pow((pos.x - gameWorld.pos_end.x),2) + pow((pos.y - gameWorld.pos_end.y),2) );
}

// Distnace from start position to our start point
inline void setGCost(GameWorld& gameWorld,sf::Vector2<char>& pos)
{
    gameWorld.tiles[pos.y][pos.x].G_cost = sqrt( pow((pos.x - gameWorld.pos_start.x),2) + pow((pos.y - gameWorld.pos_start.y),2) );
}

// Sum of both distance H + G = F
inline void setFCost(GameWorld& gameWorld, sf::Vector2<char>& pos)
{
    gameWorld.tiles[pos.y][pos.x].F_cost = gameWorld.tiles[pos.y][pos.x].H_cost + gameWorld.tiles[pos.y][pos.x].G_cost;
}

inline void isVisited(GameWorld& gameWorld, sf::Vector2<char>& pos)
{
    gameWorld.tiles[pos.y][pos.x].isFree=false;
    gameWorld.tiles[pos.y][pos.x].changeColor();
}

void settingCostOfNeigbour(GameWorld& gameWorld, sf::Vector2<char>& pos)
{
    // Top
    if(pos.y - 1 >= 0) 
    {
        if(gameWorld.tiles[pos.y-1][pos.x].isFree)
            binder(gameWorld, pos.y-1, pos.x, pos);

        // Top RIGHT
        if(pos.x + 1 < gameWorld.width && gameWorld.tiles[pos.y-1][pos.x+1].isFree)
            binder(gameWorld, pos.y-1, pos.x+1, pos);

        // Top LEFT
        if(pos.x - 1 >= 0 && gameWorld.tiles[pos.y-1][pos.x-1].isFree)
            binder(gameWorld, pos.y-1, pos.x-1, pos);
    }   

    // Bottom
    if(pos.y + 1 < gameWorld.length) 
    {
        if(gameWorld.tiles[pos.y+1][pos.x].isFree)
            binder(gameWorld, pos.y+1, pos.x, pos);

        // Bottom RIGHT
        if(pos.x + 1 < gameWorld.width && gameWorld.tiles[pos.y+1][pos.x+1].isFree)
            binder(gameWorld, pos.y+1, pos.x+1, pos);

        // Bottom LEFT
        if(pos.x - 1 >= 0 && gameWorld.tiles[pos.y+1][pos.x-1].isFree)
            binder(gameWorld, pos.y+1, pos.x-1, pos); 
    }

    // Right
    if(pos.x + 1 < gameWorld.width && gameWorld.tiles[pos.y][pos.x+1].isFree)
        binder(gameWorld, pos.y, pos.x+1, pos);

    // Left
    if(pos.x - 1 >= 0 && gameWorld.tiles[pos.y][pos.x-1].isFree)
        binder(gameWorld, pos.y, pos.x-1, pos);
}

void AStar(GameWorld& gameWorld, sf::RenderWindow &window)
{
    float minF = SIZE_MAX;
    float minH = SIZE_MAX;
    sf::Vector2<char> pos;
    settingCostOfNeigbour(gameWorld,gameWorld.pos_start);
    isVisited(gameWorld, gameWorld.pos_start);

    while(true)
    {
        // We are searching for the smallest one
        for(int y=0;y<gameWorld.width;y++)
        {
            for(int x=0;x<gameWorld.length;x++)
            {
                if(gameWorld.tiles[y][x].isFree)
                    if(gameWorld.tiles[y][x].F_cost < minF)
                        if(gameWorld.tiles[y][x].H_cost < minH)
                        {
                        minF = gameWorld.tiles[y][x].F_cost;
                        minH = gameWorld.tiles[y][x].H_cost;
                        pos.y = y;
                        pos.x = x;
                        } 
            }

        }
    /*
        std::cout<<int(pos.y)<<" "<<int(pos.x)<<'\n'<<"G_cost: "<<gameWorld.tiles[pos.y][pos.x].G_cost<<'\n'<<
        "H_cost: "<<gameWorld.tiles[pos.y][pos.x].H_cost<<'\n'<<
        "F_cost: "<<gameWorld.tiles[pos.y][pos.x].F_cost<<'\n'
        <<"__________________"<<'\n';
      */  
        settingCostOfNeigbour(gameWorld,pos);
        isVisited(gameWorld, pos);

        // Drawing
        window.clear();
        gameWorld.draw(window);
        window.display();

        if(gameWorld.tiles[pos.y][pos.x].H_cost==0)
        {
            winner(gameWorld,gameWorld.tiles[pos.y][pos.x].parent_pos,window);
            break;
        }

        minF = SIZE_MAX;
        minH = SIZE_MAX;
    }
}

void winner(GameWorld& gameWorld, sf::Vector2<char>& parent_pos,sf::RenderWindow &window)
{
    sf::Vector2<char> h1=parent_pos;
    h1 = gameWorld.tiles[h1.y][h1.x].parent_pos;

    while(gameWorld.tiles[h1.y][h1.x].G_cost > 1.50)
    {
        gameWorld.tiles[h1.y][h1.x].winner();

        window.clear();
        gameWorld.draw(window);
        window.display();

        h1 = gameWorld.tiles[h1.y][h1.x].parent_pos;
    }

    gameWorld.tiles[h1.y][h1.x].winner();
}
