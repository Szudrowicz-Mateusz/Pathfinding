#include "gameTile.h"
#include "gameWorld.h"

#include <cmath>
#include <iostream>


inline void binder(GameWorld& gameWorld,char y, char x, sf::Vector2<char>& parent_pos);

void winner(GameWorld& gameWorld, sf::Vector2<char>& parent_pos, sf::RenderWindow &window);

inline void setHCost(GameWorld& gameWorld,sf::Vector2<char>& pos);

inline void setGCost(GameWorld& gameWorld,sf::Vector2<char>& pos);

inline void setFCost(GameWorld& gameWorld,sf::Vector2<char>& pos);

void AStar(GameWorld& gameWorld, sf::RenderWindow &window);