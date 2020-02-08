//
// Created by konrad on 14.05.19.
//

#ifndef PACMAN_DATA_H
#define PACMAN_DATA_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <SFML/System/Clock.hpp>

enum Direction {LEFT,RIGHT,UP,DOWN};


enum PointState {CLEAN,NOTCLEAN};

enum GameState{RUNNING,FINISHED};

enum PacState{AGRESSIVE,DEFEND};



struct Field
{
    bool isPoint=false;
    bool isPac=false;
    bool isWall=false;
    bool isGhost=false;
    bool isApple=false;
};
class Data {
    Field tab[100][100];
    int Width=27;
    int Height=16;
    int PacX=1;
    int PacY=8;
    Direction PacDir=RIGHT;
    int RectSize=30;
    int &Score;
    int GhoastDataX[4];
    int GhoastDataY[4];
    int GhoastDataI=0;
    GameState gameState=RUNNING;
    PacState  pacState=AGRESSIVE;
    sf::Clock agressiveClock;
public:
    Data(int &s);

    void debug();
    bool canMove(Direction dir, int x, int y);

    void collisionPacPoint(int x,int y);
    void collisionPacApple(int x, int y);
    bool collisionPacGhoast(int xPac,int yPac,int xGhoast,int yGhoast);

    PointState getPointState();
    GameState getGameState()const{ return gameState;};
    PacState getPacState()const{return pacState;};
    char getFieldInfo(int x,int y);
    int getWidth(){return Width;};
    int getHeight(){return Height;}
    int getRectSize(){return RectSize;}
    std::string getScore();

    int getPacX()const{return PacX;};
    int getPacY()const{return PacY;}
    int getPacDir()const{return PacDir;};
    sf::Clock &getPacClock(){return agressiveClock;}

    void setPac(int x, int y,Direction dir);
    void setEndGame(){gameState=FINISHED;};
    void restetScore(){Score=0;};
};


#endif //PACMAN_DATA_H
