//
// Created by konrad on 14.05.19.
//

#include "Engine.h"


Engine::Engine(){
    data=new Data(Score);
    ghost[RANDOM]=new RandomGhost(*data);
    ghost[BLINKY]=new BlinkyGhost(*data);
    ghost[PINKY]=new PinkyGhost(*data);
    ghost[BLINKY2]=new BlinkyGhost(*data);
    pac=new PacMan(*data);
    eve=new Event(*pac,*data);
}

void Engine::runEngine() {
    if(data->getGameState()!=FINISHED){

        pac->movePac();
    }
    for(int i=0 ; i<4 ; i++){
        if(ghost[i]->isAlive())ghost[i]->moveGhost();
    }
    collision();
    if(eve->getnewGame()){
        playAgain();
        mustGetAll=true;
    }
    if(data->getPointState() == CLEAN){
        rebuildMap();
        mustGetAll=true;
    }
}

void Engine::rebuildMap() {
    delete data;
    delete pac;
    for(int i=0 ; i<4 ; i++){
        delete ghost[i];
    }
    delete eve;
    data=new Data(Score);
    ghost[RANDOM]=new RandomGhost(*data);
    ghost[BLINKY]=new BlinkyGhost(*data);
    ghost[PINKY]=new PinkyGhost(*data);
    ghost[BLINKY2]=new BlinkyGhost(*data);
    pac=new PacMan(*data);
    eve=new Event(*pac,*data);
    Map++;

}

void Engine::collision() {

    for(int i=0 ; i<4 ; i++){
        if (data->collisionPacGhoast(pac->getX(), pac->getY(), ghost[i]->getX(), ghost[i]->getY())) {
            if (data->getPacState() == AGRESSIVE) {
                ghost[i]->setAlive(false);
                Score = Score + 15;
            }
            if(data->getPacState()==DEFEND)data->setEndGame();
        }
    }
   //point and ,,apple" collision better work in pac class;
}

Ghost *Engine::getGhost(EnumGhost g) {
    if(g==RANDOM)return ghost[RANDOM];
    if(g==BLINKY)return ghost[BLINKY];
    if(g==PINKY)return ghost[PINKY];
    if(g==BLINKY2)return ghost[BLINKY2];


}

Ghost *Engine::rebuildGhost(EnumGhost g) {
    if(g==RANDOM){
        delete ghost[RANDOM];
        ghost[RANDOM]=new RandomGhost(*data);
        return ghost[RANDOM];
    }
    if(g==BLINKY){
        delete ghost[BLINKY];
        ghost[BLINKY]=new BlinkyGhost(*data);
        return ghost[BLINKY];
    }
    if(g==PINKY){
        delete ghost[PINKY];
        ghost[PINKY]=new PinkyGhost(*data);
        return ghost[PINKY];
    }

    if(g==BLINKY2){
        delete ghost[BLINKY2];
        ghost[BLINKY2]=new PinkyGhost(*data);
        return ghost[BLINKY2];
    }
}

void Engine::playAgain() {
    data->restetScore();
    rebuildMap();
    Map=1;

}

void Engine::handleEvent(sf::Event &event) {
    eve->handleEvent(event);
}

std::string Engine::getMap() {
    std::stringstream ss;
    ss<<Map;
    std::string str= ss.str();
    return str;
}


