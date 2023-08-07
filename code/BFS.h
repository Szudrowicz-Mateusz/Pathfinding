#pragma once

#include "gameTile.h"
#include "gameWorld.h"

#include <queue>
#include <chrono>
#include <thread>
#include <iostream>

void posiblePaths(std::queue<sf::Vector2<char>>& path_queue,sf::Vector2<char>& actual_queue,GameWorld &gameWorld);

void BFS(GameWorld &gameWorld,sf::RenderWindow &window);

void winner(sf::Vector2<char> s,GameWorld &gameWorld);