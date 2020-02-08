//
// Created by konrad on 04.06.19.
//

#ifndef PACMAN_PINKYGHOST_H
#define PACMAN_PINKYGHOST_H

#include "Ghost.h"

class PinkyGhost:public Ghost {
    Direction &probablyDir=getprobablyDir();
    Direction &dir=getDir();
    Data &data;
    int tabX[3];
    int tabY[3];
    int tabI=0;
    sf::Clock clockRandomMove;
    sf::Clock clockSetDir;
    sf::Time timeSetDir;
    int pacX;
    int pacY;

public:
    explicit PinkyGhost(Data &b);
    ~PinkyGhost(){}
    void chooseDir();
    void moveGhost();




};


#endif //PACMAN_PINKYGHOST_H
