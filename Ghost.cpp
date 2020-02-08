//
// Created by konrad on 18.05.19.
//

#include "Ghost.h"

Ghost::Ghost(Data &b):data(b) {
      RectSize=data.getRectSize();
}

void Ghost::move() {
    if(data.getPacState()==AGRESSIVE)speed=30;
    if(data.getPacState()==DEFEND)speed=25;

    myEventTimerTab += deltaClockTab.restart();
    if (myEventTimerTab >= sf::milliseconds(speed*6)) {
        myEventTimerTab -= sf::milliseconds(speed*6);
        if(data.canMove(probablyDir, xData, yData))dir=probablyDir;
        if(xData==1){
            dir=RIGHT;
        }
        if(xData==27) {
            dir = LEFT;
        }
        if (dir == LEFT) {
            if(data.canMove(LEFT, xData, yData)) {
                tmpXData=xData;
                tmpYData=yData;
                xData = xData - 1;
                x=3+(tmpXData-1)*RectSize+RectSize/2;
                y=50+tmpYData*RectSize+RectSize/2;
                isMoving=true;
            }
            else isMoving=false;
        }
        if (dir == RIGHT) {
            if (data.canMove(RIGHT, xData, yData)) {
                tmpXData=xData;
                tmpYData=yData;
                xData = xData + 1;
                x=3+(tmpXData-1)*RectSize+RectSize/2;
                y=50+tmpYData*RectSize+RectSize/2;
                isMoving=true;
            }
            else isMoving=false;
        }
        if (dir == UP) {
            if(data.canMove(UP, xData, yData)) {
                tmpXData=xData;
                tmpYData=yData;
                yData = yData - 1;
                x=3+(tmpXData-1)*RectSize+RectSize/2;
                y=50+tmpYData*RectSize+RectSize/2;
                isMoving=true;
            }
            else isMoving=false;
        }
        if (dir == DOWN) {
            if(data.canMove(DOWN, xData, yData)) {
                tmpXData=xData;
                tmpYData=yData;
                yData = yData + 1;
                x=3+(tmpXData-1)*RectSize+RectSize/2;
                y=50+tmpYData*RectSize+RectSize/2;
                isMoving=true;
            }
            else isMoving=false;
        }
    }
    myEventTimer += deltaClock.restart();
    if (myEventTimer >= sf::milliseconds(speed)) {
        myEventTimer -= sf::milliseconds(speed);

        if(isMoving) {
            if (dir == LEFT) {
                x = x - (RectSize/6);
            }
            if (dir == RIGHT) {
                x = x + (RectSize/6);
            }
            if (dir == UP) {
                y = y - (RectSize/6);
            }
            if (dir == DOWN) {
                y = y + (RectSize/6);
            }
        }
    }
}


void Ghost::randomMove() {
    if (dir == UP or dir == DOWN) {
        int r = rand() % 3;
        switch (r) {
            case 1:
                if (data.canMove(RIGHT, getXData(), getYData()))probablyDir = RIGHT;
                break;
            case 2:
                if (data.canMove(LEFT, getXData(), getYData()))probablyDir = LEFT;
                break;
            default:
                break;

        }
    }
    if (dir == LEFT or dir == RIGHT) {
        int r = rand() % 3;
        switch (r) {
            case 1:
                if (data.canMove(UP, getXData(), getYData()))probablyDir = UP;
                break;
            case 2:
                if (data.canMove(DOWN, getXData(), getYData()))probablyDir = DOWN;
                break;
            case 3:
                break;
            default:
                break;
        }
    }


    if (Dir.getElapsedTime() > sf::milliseconds(4000)) {
        probablyDir = (Direction) (rand() % 4);
        Dir.restart();
    }

    while (data.canMove(probablyDir, getXData(), getYData()) == 0)
        probablyDir = (Direction) (rand() % 4);

}

void Ghost::runAway() {
    timeSetDir += clockSetDir.restart();
    if (timeSetDir >= sf::milliseconds(getSpeed() * 6)) {
        timeSetDir -= sf::milliseconds(getSpeed() * 6);

        if (clockRandomMove.getElapsedTime() < sf::milliseconds(5000)) {
            randomMove();
        } else {
            int r = rand() % 2;
            if (data.getPacY() == getYData() or data.getPacX() == getX()) {
                if (data.getPacY() == getYData()) {
                    if (data.getPacX() > getXData())probablyDir = LEFT;
                    if (data.getPacX() < getXData())probablyDir = RIGHT;
                }
                if (data.getPacX() == getXData()) {
                    if (data.getPacY() > getYData())probablyDir = UP;
                    if (data.getPacY() < getYData())probablyDir = DOWN;
                }
            } else {
                if (getXData() > data.getPacX()) {
                    if (getYData() < data.getPacY()) {
                        if (r == 0)probablyDir = UP;
                        if (r == 1)probablyDir = RIGHT;
                    }
                    if (getYData() > data.getPacY()) {
                        if (r == 0)probablyDir = DOWN;
                        if (r == 1)probablyDir = RIGHT;
                    }
                }
                if (getXData() < data.getPacX()) {
                    if (getYData() < data.getPacY()) {
                        if (r == 0)probablyDir = UP;
                        if (r == 1)probablyDir = LEFT;
                    }
                    if (getYData() > data.getPacY()) {
                        if (r == 0)probablyDir = DOWN;
                        if (r == 1)probablyDir = LEFT;
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



