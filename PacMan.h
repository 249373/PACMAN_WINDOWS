//
// Created by konrad on 16.05.19.
//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include <SFML/System/Clock.hpp>
#include "Data.h"
#include <cmath>
#include "Ghost.h"
#include "RandomGhost.h"

class PacMan {
    int xData;
    int yData;
    int x;
    int y;
    int tmpXData;
    int tmpYData;
    bool isMoving=true;
    int speed=23;


    sf::Clock deltaClockTab;
    sf::Time myEventTimerTab;
    sf::Clock deltaClock;
    sf::Time myEventTimer;
    int RectSize;
    Direction dir=RIGHT;
    Direction probablyDir=RIGHT;

    Data &data;

public:
    PacMan(Data &board);
    int getY(){return y;}
    int getX(){return x;}
    Direction getDirections()const { return dir;};
    void movePac();
    void setProbablyDir(Direction d);
    int getRectSize(){ return RectSize;};


};


#endif //PACMAN_PACMAN_H
