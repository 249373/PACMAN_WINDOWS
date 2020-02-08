//
// Created by konrad on 14.05.19.
//

#ifndef PACMAN_ENGINE_H
#define PACMAN_ENGINE_H


#include "Event.h"
#include "Ghost.h"
#include "RandomGhost.h"
#include "BlinkyGhost.h"
#include "PinkyGhost.h"

enum EnumGhost{BLINKY,RANDOM,PINKY,BLINKY2};
class Engine {
    Data *data;
    PacMan *pac;
    Event *eve;
    Ghost *ghost[4];
    int Score=0;
    int Map=1;
    bool mustGetAll=false;

public:
    explicit Engine();
    void runEngine();
    Data *getBoard(){return data;};
    PacMan *getPac(){return pac;};
    Ghost* getGhost(EnumGhost g);
    std::string getMap();

    Ghost* rebuildGhost(EnumGhost g);
    void collision();
    void rebuildMap();
    void playAgain();
    bool getMustGet(){return mustGetAll;};
    void handleEvent(sf::Event & event);


};


#endif //PACMAN_ENGINE_H
