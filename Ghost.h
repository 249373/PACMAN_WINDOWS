//
// Created by konrad on 18.05.19.
//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include <SFML/System/Clock.hpp>
#include "Data.h"

class Ghost {
    int xData=16;
    int yData=13;
    int x=7+(tmpXData-1)*RectSize+RectSize/2;
    int y=50+tmpYData*RectSize+RectSize/2;;
    int tmpXData=xData;
    int tmpYData=yData-1;
    bool isMoving=true;
    int RectSize;
    Data &data;
    bool alive=true;
    sf::Clock deltaClockTab;
    sf::Time myEventTimerTab;
    sf::Clock deltaClock;
    sf::Time myEventTimer;
    int speed=25;
    Direction dir=DOWN;
    Direction probablyDir=DOWN;
    int tabX[3];
    int tabY[3];
    int tabI=0;
    sf::Clock clockRandomMove;
    sf::Clock clockSetDir;
    sf::Time timeSetDir;
public:
    sf::Clock Dir;
    explicit Ghost(Data &b);
    virtual ~Ghost(){};
    int getXData(){return xData;}
    int getYData(){return yData;}
    int getY()const{return y;}
    int getX()const{return x;}
    int getSpeed()const{ return speed;}
    Direction &getDir(){return dir;}
    Direction &getprobablyDir(){return probablyDir;}

    bool isAlive()const{return alive;}
    void setAlive(bool i){alive=i;}
    void setDir(Direction d){dir=d;}
    void setProbablyDir(Direction d){probablyDir=d;}

    void move();
    virtual void moveGhost()=0;
    virtual void chooseDir()=0;
    void randomMove();
    void runAway();
};


#endif //PACMAN_GHOST_H
