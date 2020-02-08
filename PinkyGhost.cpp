//
// Created by konrad on 04.06.19.
//

#include "PinkyGhost.h"

PinkyGhost::PinkyGhost(Data &b) : Ghost(b), data(b) {


}
void PinkyGhost::moveGhost() {
    chooseDir();
    move();

}

void PinkyGhost::chooseDir() {

    if (data.getPacState() == AGRESSIVE)runAway();
    else {
        if (data.getPacDir() == LEFT) {
            pacX = data.getPacX() - 6;
            pacY = data.getPacY();
        }
        if (data.getPacDir() == RIGHT) {
            pacX = data.getPacX() + 6;
            pacY = data.getPacY();
        }
        if (data.getPacDir() == DOWN) {
            pacX = data.getPacX();
            pacY = data.getPacY() + 5;
        }
        if (data.getPacDir() == UP) {
            pacX = data.getPacX() - 5;
            pacY = data.getPacY();
        }


        timeSetDir += clockSetDir.restart();
        if (timeSetDir >= sf::milliseconds(getSpeed() * 6)) {
            timeSetDir -= sf::milliseconds(getSpeed() * 6);

            if (clockRandomMove.getElapsedTime() < sf::seconds(1)) {
                randomMove();
            } else {
                int r = rand() % 2;
                if (pacY == getYData() or pacX == getXData()) {
                    if (pacY == getYData()) {
                        if (pacX > getXData())probablyDir = RIGHT;
                        if (pacX < getXData())probablyDir = LEFT;
                    }
                    if (pacX == getXData()) {
                        if (pacY > getYData())probablyDir = DOWN;
                        if (pacY < getYData())probablyDir = UP;
                    }
                } else {
                    if (getXData() > pacX) {
                        if (getYData() < pacY) {
                            if (r == 0)probablyDir = DOWN;
                            if (r == 1)probablyDir = LEFT;
                        }
                        if (getYData() > pacY) {
                            if (r == 0)probablyDir = UP;
                            if (r == 1)probablyDir = LEFT;
                        }
                    }
                    if (getXData() < pacX) {
                        if (getYData() < pacY) {
                            if (r == 0)probablyDir = DOWN;
                            if (r == 1)probablyDir = RIGHT;
                        }
                        if (getYData() > pacY) {
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
