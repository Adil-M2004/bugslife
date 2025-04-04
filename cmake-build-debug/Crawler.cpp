// Crawler.cpp
#include "Crawler.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>


Crawler::Crawler(int id, Position startPos, Direction startDir, int initialSize) :
    id(id), position(startPos), direction(startDir), size(initialSize), alive(true) {
    path.push_back(startPos);
}

void Crawler::move(int boardWidth, int boardHeight) {
    while (isWayBlocked(boardWidth, boardHeight)) {
        direction = getRandomDirection();
    }

    Position nextPos = position;
    switch (direction) {
    case Direction::North:
        nextPos.y--;
        break;
    case Direction::East:
        nextPos.x++;
        break;
    case Direction::South:
        nextPos.y++;
        break;
    case Direction::West:
        nextPos.x--;
        break;
    }

    position = nextPos;
    path.push_back(position);
}

bool Crawler::isWayBlocked(int boardWidth, int boardHeight) {
    switch (direction) {
    case Direction::North:
        return position.y == 0;
    case Direction::East:
        return position.x == boardWidth - 1;
    case Direction::South:
        return position.y == boardHeight - 1;
    case Direction::West:
        return position.x == 0;
    default:
        return false;
    }
}

Direction Crawler::getRandomDirection() {
    int random = rand() % 4 + 1; // Generates 1, 2, 3, or 4
    return static_cast<Direction>(random);
}