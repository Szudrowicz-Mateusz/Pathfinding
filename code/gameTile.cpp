#include "gameTile.h"

GameTile::GameTile(float x, float y,sf::Vector2f recSize)
{
    // Tunning variables
    pos = sf::Vector2f(x,y);

    // Setting up rectangles
    rec.setPosition(pos);
    rec.setSize(recSize);
    rec.setFillColor(sf::Color::Blue);
    rec.setOutlineThickness(1.f);
    rec.setOutlineColor(sf::Color::Black);

    // Setting up booleans
    isFree=true;
    isStart=false;
    isExit=false;

    // Setting up for Dijkstra
    value=SIZE_MAX;

    // Setting up for A*
    F_cost=SIZE_MAX;
}

void GameTile::changeToWall()
{
    if(isFree)
    {
    rec.setFillColor(sf::Color::White);
    isFree=false;
    }
}

void GameTile::changeToStaritingPoint()
{
    rec.setFillColor(sf::Color::Green);
    isFree=false;
    isStart=true;
}

void GameTile::changeToExitPoint()
{
    rec.setFillColor(sf::Color::Red);
    isFree=true;
    isExit=true;
}

void GameTile::noLongerStart()
{
    rec.setFillColor(sf::Color::Blue);
    isFree=true;
    isStart=false;
}

void GameTile::noLongerEnd()
{
    rec.setFillColor(sf::Color::Blue);
    isFree=true;
    isExit=false;
}

void GameTile::changeColor()
{
        if(!isExit && !isStart)
            rec.setFillColor(sf::Color::Magenta);
}

void GameTile::winner()
{
    if(!isStart)
        rec.setFillColor(sf::Color::Yellow);
}

void GameTile::reset()
{
    rec.setFillColor(sf::Color::Blue);
    isExit=false;
    isStart=false;
    isFree=true;

    G_cost = SIZE_MAX;
    H_cost = SIZE_MAX;
    F_cost = SIZE_MAX;
}