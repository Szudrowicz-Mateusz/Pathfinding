#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



class GameTile{
public:

    // Shape off tile
    sf::RectangleShape rec;

    // Varriables
    bool isFree;
    bool isExit;
    bool isStart;
    sf::Vector2f pos;

    // Varriables for BFS
    sf::Vector2<char> parent_pos;

    // Varriables for Dijsktra
    float value;

    // Varriables for A*
    float G_cost;
    float H_cost;
    float F_cost;

    // Functions Creating Map
    void changeToWall();
    void changeToStaritingPoint();
    void changeToExitPoint();
    void changeColor();

    // Functions Cleaning Map
    void noLongerStart();
    void noLongerEnd();
    void reset();

    // Functions to win BFS
    void winner();
    
    // Construtors & Destructors
    GameTile(float x, float y, sf::Vector2f recSize);
    GameTile()=delete;
    ~GameTile()=default;
};