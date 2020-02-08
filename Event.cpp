//
// Created by konrad on 17.05.19.
//

#include "Event.h"

Event::Event(PacMan &p,Data &d):pac(p),data(d) {

}

void Event::handleEvent(sf::Event &event) {


    if (event.type == sf::Event::KeyPressed) {

        if (event.key.code == sf::Keyboard::Right) {
            pac.setProbablyDir(RIGHT);

        }
        if (event.key.code == sf::Keyboard::Left) {
            pac.setProbablyDir(LEFT);
        }
        if (event.key.code == sf::Keyboard::Down) {
            pac.setProbablyDir(DOWN);
        }
        if (event.key.code == sf::Keyboard::Up) {
            pac.setProbablyDir(UP);
        }
        if (event.key.code == sf::Keyboard::Space) {
            if (data.getGameState() == FINISHED)newGame = true;
        }
    }
}
bool Event::getnewGame() {
    if(newGame) {
        newGame = false;
        return true;
    }
    else
    return false;
}
