#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "gameTile.h"
#include <vector>

class GameWorld{
public:

    // Variable
    std::vector< std::vector<GameTile>> tiles;
    int width;
    int length;
    sf::Vector2<char> pos_end;
    sf::Vector2<char> pos_start;

    // Constructor & Destructors
    GameWorld(int _width, int _length);
    GameWorld()=delete;
    ~GameWorld()=default;

    // Functions
    void setUpWorld();
    void createWalls(sf::Vector2i mouse_pos);
    void startingPosition(sf::Vector2i mouse_pos);
    void endingPosition(sf::Vector2i mouse_pos);
    void reset();

    // Functions to destroy old points
    void destroyingOldStart();
    void destroyingOldEnd();

    // Drawing funtions
    void draw(sf::RenderWindow &window);
};