
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "gameTile.h"
#include "gameWorld.h"
#include "BFS.h"
#include "Dijkstra.h"
#include "Astar.h"


int main(){
    sf::RenderWindow window(sf::VideoMode(510,510),"SFML Tiles", sf::Style::Close | sf::Style::Resize);
    
    // Variable of whole TileMap
    GameWorld gameWorld(34,34);

    while(window.isOpen()){

        // Events
        sf::Event event;
        while(window.pollEvent(event)){
            switch ((event.type)){

                case sf::Event::Closed:
                window.close();
                break;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    gameWorld.startingPosition(sf::Mouse::getPosition(window));
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    gameWorld.endingPosition(sf::Mouse::getPosition(window));
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                gameWorld.createWalls(sf::Mouse::getPosition(window));
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
            {
                BFS(gameWorld,window);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                dijkstraAlgorithm(gameWorld,window);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                AStar(gameWorld,window);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                gameWorld.reset();
            }
        }

        

        window.clear(sf::Color::Black);
        

        // Drawing map
        //for(int i=0;i<gameWorld.width;i++)
        //{
            //for(int j=0;j<gameWorld.length;j++)
            //{
               // window.draw(gameWorld.tiles[i][j]->rec);
            //}
        //}
        gameWorld.draw(window);

        window.display();

    }
}