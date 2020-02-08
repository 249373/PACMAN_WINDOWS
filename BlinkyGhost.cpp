//
// Created by konrad on 29.05.19.
//

#include "BlinkyGhost.h"

BlinkyGhost::BlinkyGhost(Data &b) : Ghost(b), data(b) {

}
void BlinkyGhost::moveGhost() {
    chooseDir();
    move();

}

void BlinkyGhost::chooseDir() {

    if (data.getPacState() == AGRESSIVE)runAway();
    else {

        timeSetDir += clockSetDir.restart();
        if (timeSetDir >= sf::milliseconds(getSpeed() * 6)) {
            timeSetDir -= sf::milliseconds(getSpeed() * 6);

            if (clockRandomMove.getElapsedTime() < sf::seconds(1)) {
                randomMove();
            } else {
                int r = rand() % 2;
                if (data.getPacY() == getYData() or data.getPacX() == getX()) {
                    if (data.getPacY() == getYData()) {
                        if (data.getPacX() > getXData())probablyDir = RIGHT;
                        if (data.getPacX() < getXData())probablyDir = LEFT;
                    }
                    if (data.getPacX() == getXData()) {
                        if (data.getPacY() > getYData())probablyDir = DOWN;
                        if (data.getPacY() < getYData())probablyDir = UP;
                    }
                } else {
                    if (getXData() > data.getPacX()) {
                        if (getYData() < data.getPacY()) {
                            if (r == 0)probablyDir = DOWN;
                            if (r == 1)probablyDir = LEFT;
                        }
                        if (getYData() > data.getPacY()) {
                            if (r == 0)probablyDir = UP;
                            if (r == 1)probablyDir = LEFT;
                        }
                    }
                    if (getXData() < data.getPacX()) {
                        if (getYData() < data.getPacY()) {
                            if (r == 0)probablyDir = DOWN;
                            if (r == 1)probablyDir = RIGHT;
                        }
                        if (getYData() > data.getPacY()) {
                            if (r == 0)probablyDir = UP;
                            if (r == 1)probablyDir = RIGHT;
                        }
                    }
                }
                if (tabX[0] == tabX[1] and tabX[1] == tabX[2] and tabY[0] == tabY[1] and tabY[1] == tabY[2])
                    clockRandomMove.restart();
            }
            if (tabI == 3)tabI = 0;
            tabX[tabI] = getXData();
            tabY[tabI] = getYData();
            tabI++;
        }
    }

}