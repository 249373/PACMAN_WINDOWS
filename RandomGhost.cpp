//
// Created by konrad on 28.05.19.
//

#include "RandomGhost.h"

RandomGhost::RandomGhost(Data &b) : Ghost(b), data(b) {


}
void RandomGhost::moveGhost() {
    chooseDir();
    move();

}

void RandomGhost::chooseDir() {
    if(data.getPacState()==AGRESSIVE)runAway();
    else randomMove();
}

