#include "Dijkstra.h"

void changeToVisited(GameWorld& gameWorld,short& y,short& x)
{
    gameWorld.tiles[y][x].isFree=false;
    gameWorld.tiles[y][x].changeColor();
}

void searchForTheSmallest(GameWorld& gameWorld,short y,short x,float& min,sf::Vector2<short>& pos)
{

    if(gameWorld.tiles[y][x].isFree)
    {
        //std::cout<<"VALUE:"<<gameWorld.tiles[y][x].value<<"  Y:"<<y<<"   X:"<<x<<'\n';
        if(gameWorld.tiles[y][x].value < min)
        {
            min=gameWorld.tiles[y][x].value;
            pos.y=y;
            pos.x=x;
        }
    }
}

void straightPoints(GameWorld& gameWorld,short& y,short& x,std::queue<sf::Vector2<short>>& path_queue)
{
    float min_value=MAXFLOAT;
    sf::Vector2<short> pos;

    /*
    Y is first parameter so it means that y must go first
    X is second parameter
    */

    // Bottom side
    if(y < gameWorld.length)
    {   
        // Bottom
        if(gameWorld.tiles[y+1][x].value > gameWorld.tiles[y][x].value +1)
            gameWorld.tiles[y+1][x].value = gameWorld.tiles[y][x].value +1;
            
        searchForTheSmallest(gameWorld,y+1,x,min_value,pos);
        
        //gameWorld.tiles[y+1][x].changeColor();
        //std::cout<<"BOT:"<<gameWorld.tiles[y+1][x].value<<" "<<gameWorld.tiles[y+1][x].isFree<<'\n';

        

        // Left Bottom cornenr
        if(x > 0)
        {
            if(gameWorld.tiles[y+1][x-1].value > gameWorld.tiles[y][x].value + 1.41f)
                gameWorld.tiles[y+1][x-1].value = gameWorld.tiles[y][x].value + 1.41f;

            searchForTheSmallest(gameWorld,y+1,x-1,min_value,pos);

            //gameWorld.tiles[y+1][x-1].changeColor();
            //std::cout<<"L BOT:"<<gameWorld.tiles[y+1][x-1].value<<" "<<gameWorld.tiles[y+1][x-1].isFree<<'\n';
        }            

        // Right Bottom Corner
        if(x < gameWorld.width)
        {
            if(gameWorld.tiles[y+1][x+1].value > gameWorld.tiles[y][x].value + 1.41f)
                gameWorld.tiles[y+1][x+1].value = gameWorld.tiles[y][x].value + 1.41f;
               
            searchForTheSmallest(gameWorld,y+1,x+1,min_value,pos);

            //gameWorld.tiles[y+1][x+1].changeColor();
            //std::cout<<"R BOT:"<<gameWorld.tiles[y+1][x+1].value<<" "<<gameWorld.tiles[y+1][x+1].isFree<<'\n';
        }
    }

    // Top
    if(y > 0)
    {
        // Top
        if(gameWorld.tiles[y-1][x].value > gameWorld.tiles[y][x].value +1)
            gameWorld.tiles[y-1][x].value = gameWorld.tiles[y][x].value +1;

        searchForTheSmallest(gameWorld,y+1,x,min_value,pos);

            //gameWorld.tiles[y-1][x].changeColor();
            //std::cout<<"TOP:"<<gameWorld.tiles[y-1][x].value<<" "<<gameWorld.tiles[y-1][x].isFree<<'\n';

        // Left Top Corner
        if(x > 0)
        {
            if(gameWorld.tiles[y-1][x-1].value > gameWorld.tiles[y][x].value + 1.41f)
                gameWorld.tiles[y-1][x-1].value = gameWorld.tiles[y][x].value + 1.41f;

            searchForTheSmallest(gameWorld,y-1,x-1,min_value,pos);

            //gameWorld.tiles[y-1][x-1].changeColor();
            //std::cout<<"L TOP:"<<gameWorld.tiles[y-1][x-1].value<<" "<<gameWorld.tiles[y-1][x-1].isFree<<'\n';
        }

        // Right Top Corner
        if(x < gameWorld.width)
        {
            if(gameWorld.tiles[y-1][x+1].value > gameWorld.tiles[y][x].value + 1.41f)
                gameWorld.tiles[y-1][x+1].value = gameWorld.tiles[y][x].value + 1.41f;

            searchForTheSmallest(gameWorld,y-1,x+1,min_value,pos);

            //gameWorld.tiles[y-1][x+1].changeColor();
            //std::cout<<"R TOP:"<<gameWorld.tiles[y-1][x+1].value<<" "<<gameWorld.tiles[y-1][x+1].isFree<<'\n';
        }

    }


    // Left
    if(x > 0)
    {
        if(gameWorld.tiles[y][x-1].value > gameWorld.tiles[y][x].value +1)
            gameWorld.tiles[y][x-1].value = gameWorld.tiles[y][x].value +1;
            
        searchForTheSmallest(gameWorld,y,x-1,min_value,pos);
        //gameWorld.tiles[y][x-1].changeColor();
        //std::cout<<"Left:"<<gameWorld.tiles[y][x-1].value<<" "<<gameWorld.tiles[y][x-1].isFree<<'\n';
    }
    
    // Right
    if(x < gameWorld.width)
    {
        if(gameWorld.tiles[y][x+1].value > gameWorld.tiles[y][x].value +1)
            gameWorld.tiles[y][x+1].value = gameWorld.tiles[y][x].value +1;

        searchForTheSmallest(gameWorld,y,x+1,min_value,pos);

            //gameWorld.tiles[y][x+1].changeColor();
            //std::cout<<"Right:"<<gameWorld.tiles[y][x+1].value<<" "<<gameWorld.tiles[y][x+1].isFree<<'\n';
      
    }

    path_queue.push(pos);
}


void dijkstraAlgorithm(GameWorld& gameWorld,sf::RenderWindow& window)
{
sf::Vector2<short> start_position;

std::cout<<"_______________________"<<'\n';

    for(int i=0;i<gameWorld.width;i++)
    {
        for(int j=0;j<gameWorld.length;j++)
        {
                if(gameWorld.tiles[i][j].isStart)
                    {
                        start_position.y=i;
                        start_position.x=j;
                    }
        }
    }

    std::queue<sf::Vector2<short>> path_queue;
    path_queue.push(start_position);

    //std::cout<<"Nie: "<<start_position.x<<" "<<start_position.y<<'\n';
    //std::cout<<"QUEUE: "<<path_queue.front().x<<" "<<path_queue.front().y<<'\n';

    gameWorld.tiles[start_position.y][start_position.x].value=0;

    while(!path_queue.empty())
    {
        straightPoints(gameWorld,path_queue.front().y,path_queue.front().x,path_queue);
        changeToVisited(gameWorld,path_queue.front().y,path_queue.front().x);
        //std::cout<<path_queue.back().x<<" "<<path_queue.back().y<<'\n';

        std::cout<<"_______________________"<<'\n';

        // Drawing
        window.clear();
        gameWorld.draw(window);
        window.display();

        if(gameWorld.tiles[path_queue.front().x][path_queue.front().y].isExit)
        {
            //winner(path_queue.front(),gameWorld);
            break;
        }

        path_queue.pop();
    }
    
}

