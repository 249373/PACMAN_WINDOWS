//
// Created by konrad on 28.05.19.
//

#ifndef PACMAN_RANDOMGHOST_H
#define PACMAN_RANDOMGHOST_H

#include "Ghost.h"

class RandomGhost :public Ghost{
    Data &data;

public:
    explicit  RandomGhost(Data &b);
    ~RandomGhost(){}
    void chooseDir();
    void moveGhost();

};


#endif //PACMAN_RANDOMGHOST_H
