//

#include "PacMan.h"


PacMan::PacMan(Data &board):data(board) {
    RectSize=board.getRectSize();
    xData=1;
    yData=8;
    tmpXData=0;
    tmpYData=8;
    x=7+(tmpXData-1)*RectSize+RectSize/2;
    y=50+tmpYData*RectSize+RectSize/2;
}

void PacMan::setProbablyDir(Direction p) {
    probablyDir=p;
}

void PacMan::movePac() {
    if(data.getPacState()==AGRESSIVE)speed=27;
    if(data.getPacState()==DEFEND)speed=23;

    myEventTimerTab += deltaClockTab.restart();
        if (myEventTimerTab >= sf::milliseconds(speed*6)) {
            myEventTimerTab -= sf::milliseconds(speed*6);

            data.collisionPacPoint(xData, yData);
            data.collisionPacApple(xData, yData);

        if (xData == 18 and yData < 13 and yData > 10);
        else if (data.canMove(probablyDir, xData, yData))dir = probablyDir;


        if (xData <= 0) {
            xData = 28;
            tmpXData = 29;
        }
        if (xData > 28 ) {
            xData = 0;
            dir = RIGHT;
            probablyDir = RIGHT;
        }
        if (dir == LEFT) {
            if (data.canMove(LEFT, xData, yData)) {
                tmpXData = xData;
                tmpYData = yData;
                xData = xData - 1;
                x = 3 + (tmpXData - 1) * RectSize + RectSize / 2;
                y = 50 + tmpYData * RectSize + RectSize / 2;
                isMoving = true;
            } else isMoving = false;
        }
        if (dir == RIGHT) {
            if (data.canMove(RIGHT, xData, yData)) {
                tmpXData = xData;
                tmpYData = yData;
                xData = xData + 1;
                x = 3 + (tmpXData - 1) * RectSize + RectSize / 2;
                y = 50 + tmpYData * RectSize + RectSize / 2;
                isMoving = true;
            } else isMoving = false;
        }
        if (dir == UP) {
            if (data.canMove(UP, xData, yData)) {
                tmpXData = xData;
                tmpYData = yData;
                yData = yData - 1;
                x = 3 + (tmpXData - 1) * RectSize + RectSize / 2;
                y = 50 + tmpYData * RectSize + RectSize / 2;
                isMoving = true;
            } else isMoving = false;
        }
        if (dir == DOWN) {
            if (data.canMove(DOWN, xData, yData)) {
                tmpXData = xData;
                tmpYData = yData;
                yData = yData + 1;
                x = 3 + (tmpXData - 1) * RectSize + RectSize / 2;
                y = 50 + tmpYData * RectSize + RectSize / 2;
                isMoving = true;
            } else isMoving = false;
        }
        data.setPac(xData,yData,dir);
    }

    myEventTimer += deltaClock.restart();
    if (myEventTimer >= sf::milliseconds(speed)) {
        myEventTimer -= sf::milliseconds(speed);
        if (isMoving) {
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













