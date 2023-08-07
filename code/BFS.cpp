#include "BFS.h"

inline void changeToVisitedTile(GameWorld &gameWorld,char x, char y)
{
        gameWorld.tiles[x][y].isFree=false;
        gameWorld.tiles[x][y].changeColor();
} 

// Function that adding every posilbe path for BFS 
void posiblePaths(std::queue<sf::Vector2<char>>& path_queue,sf::Vector2<char>& actual_queue,GameWorld &gameWorld)
{
    // Left
    if(actual_queue.x-1>=0 && gameWorld.tiles[actual_queue.x-1][actual_queue.y].isFree){
        path_queue.push(sf::Vector2<char>(actual_queue.x-1,actual_queue.y));

        changeToVisitedTile(gameWorld,actual_queue.x-1,actual_queue.y);
        // Parent postion sing in tile
        gameWorld.tiles[actual_queue.x-1][actual_queue.y].parent_pos=actual_queue;
    }

    // Right
    if(actual_queue.x+1 < gameWorld.width && gameWorld.tiles[actual_queue.x+1][actual_queue.y].isFree){
        path_queue.push(sf::Vector2<char>(actual_queue.x+1,actual_queue.y));

        changeToVisitedTile(gameWorld,actual_queue.x+1,actual_queue.y);
        // Parent position sign in tile
        gameWorld.tiles[actual_queue.x+1][actual_queue.y].parent_pos=actual_queue;
    }
        
    // Top
    if(actual_queue.y+1<gameWorld.length && gameWorld.tiles[actual_queue.x][actual_queue.y+1].isFree){
        path_queue.push(sf::Vector2<char>(actual_queue.x,actual_queue.y+1));

        changeToVisitedTile(gameWorld,actual_queue.x,actual_queue.y+1);

        gameWorld.tiles[actual_queue.x][actual_queue.y+1].parent_pos=actual_queue;
    }
    
    // Bottom
    if(actual_queue.y-1>=0 && gameWorld.tiles[actual_queue.x][actual_queue.y-1].isFree){
        path_queue.push(sf::Vector2<char>(actual_queue.x,actual_queue.y-1));

        changeToVisitedTile(gameWorld,actual_queue.x,actual_queue.y-1);

        gameWorld.tiles[actual_queue.x][actual_queue.y-1].parent_pos=actual_queue;
    }
        
}


void BFS(GameWorld &gameWorld,sf::RenderWindow &window)
{

sf::Vector2<char> start_position;

    for(int i=0;i<gameWorld.width;i++)
    {
        for(int j=0;j<gameWorld.length;j++)
        {
                if(gameWorld.tiles[i][j].isStart)
                    {
                        start_position.x=i;
                        start_position.y=j;
                    }
        }
    }

    std::queue<sf::Vector2<char>> path_queue;
    path_queue.push(start_position);

    changeToVisitedTile(gameWorld,start_position.x,start_position.y);

    while(!path_queue.empty())
    {
        posiblePaths(path_queue,path_queue.front(),gameWorld);

        path_queue.pop();

        // Draw
        window.clear();
        gameWorld.draw(window);
        window.display();

        // Sleep
        //std::this_thread::sleep_for(std::chrono::milliseconds(5));

        if(gameWorld.tiles[path_queue.front().x][path_queue.front().y].isExit)
        {
            winner(path_queue.front(),gameWorld);
            break;
        }
    }


}

void winner(sf::Vector2<char> s,GameWorld &gameWorld)
{   
    // h1 stands for holder varriables
    sf::Vector2<char> h1=s;
    h1 = gameWorld.tiles[h1.x][h1.y].parent_pos;

    while(!gameWorld.tiles[h1.x][h1.y].isStart)
    {
        gameWorld.tiles[h1.x][h1.y].winner();
        h1 = gameWorld.tiles[h1.x][h1.y].parent_pos;
    }
}