#pragma once

#include "gameTile.h"
#include "gameWorld.h"

#include <queue>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

void changeToVisited(GameWorld& gameWorld,short& y,short& x);

void straightPoints(GameWorld& gameWorld,short& y,short& x,std::queue<sf::Vector2<short>>& path_queue);

void dijkstraAlgorithm(GameWorld& gameWorld,sf::RenderWindow& window);