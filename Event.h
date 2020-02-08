//
// Created by konrad on 17.05.19.
//

#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H


#include <SFML/Window/Event.hpp>
#include "PacMan.h"
#include "Data.h"


class Event {

    PacMan &pac;
    Data &data;
    bool newGame=false;

public:
    Event(PacMan &p,Data &data);
    void handleEvent(sf::Event & event);
    bool getnewGame();
};


#endif //PACMAN_EVENT_H
