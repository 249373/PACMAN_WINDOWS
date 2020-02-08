//
// Created by konrad on 29.05.19.
//

#ifndef PACMAN_BLINKYGHOST_H
#define PACMAN_BLINKYGHOST_H

#include "Ghost.h"


class BlinkyGhost:public Ghost{
    Direction &probablyDir=getprobablyDir();
    Direction &dir=getDir();
    Data &data;
    int tabX[3];
    int tabY[3];
    int tabI=0;
    sf::Clock clockRandomMove;
    sf::Clock clockSetDir;
    sf::Time timeSetDir;

public:
    explicit BlinkyGhost(Data &b);
    ~BlinkyGhost(){}


    void chooseDir();
    void moveGhost();


};


#endif //PACMAN_BLINKYGHOST_H
