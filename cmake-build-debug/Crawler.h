//
// Created by manzoor on 03/04/2025.
//

#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <list>
#include <vector>

// Define the Position struct
struct Position {
    int x;
    int y;
};

// Define the direction enum
enum class Direction {
    North = 1,
    East,
    South,
    West
};


class Crawler {

  public:
    Crawler();

     public:
    int id;
    Position position;
    Direction direction;
    int size;
    bool alive;
    std::list<Position> path;

    Crawler(int id, Position startPos, Direction startDir, int initialSize);

    void move(int boardWidth, int boardHeight);
    bool isWayBlocked(int boardWidth, int boardHeight);

private:
    Direction getRandomDirection();

};



#endif //CRAWLER_H
