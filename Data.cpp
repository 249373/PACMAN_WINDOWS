//

#include "Data.h"

Data::Data(int &s):Score(s){


    for(int x=1 ; x<=Width ; x++){
        if(x==1 or x==Width ){
            for(int y=0; y<=Height ; y++){
                if(y==8)continue;
                tab[x][y].isWall=true;
            }
        }
        if(x>1 and x<Width){
            tab[x][0].isWall=true;
            tab[x][Height].isWall=true;
        }
    }
    tab[4][4].isApple=true;
    tab[24][4].isApple=true;
    tab[7][11].isApple=true;
    tab[24][12].isApple=true;
    tab[27][8].isPoint=true;
    tab[3][2].isWall=true;
    tab[3][14].isWall=true;
    tab[3][13].isWall= true;
    tab[3][12].isWall=true;
    tab[3][11].isWall=true;
    tab[3][10].isWall=true;
    tab[3][9].isWall=true;
    tab[3][7].isWall=true;
    tab[3][6].isWall=true;
    tab[3][5].isWall=true;
    tab[3][4].isWall=true;
    tab[3][3].isWall=true;
    tab[4][12].isWall=true;
    tab[4][5].isWall=true;
    tab[4][2].isWall=true;
    tab[5][15].isWall=true;
    tab[5][14].isWall=true;
    tab[5][12].isWall=true;
    tab[5][11].isWall=true;
    tab[5][10].isWall=true;
    tab[5][9].isWall=true;
    tab[4][9].isWall=true;
    tab[5][6].isWall=true;
    tab[5][4].isWall=true;
    tab[5][7].isWall=true;
    tab[6][3].isWall=true;
    tab[6][2].isWall=true;
    tab[7][7].isWall=true;
    tab[7][14].isWall=true;
    tab[7][13].isWall=true;
    tab[7][12].isWall=true;
    tab[7][10].isWall=true;
    tab[7][11].isWall=true;
    tab[7][9].isWall=true;
    tab[7][6].isWall=true;
    tab[7][5].isWall=true;
    tab[8][13].isWall=true;
    tab[8][11].isWall=true;
    tab[8][7].isWall=true;
    tab[8][4].isWall=true;
    tab[8][2].isWall=true;
    tab[9][14].isWall=true;
    tab[9][13].isWall=true;
    tab[9][12].isWall=true;
    tab[9][11].isWall=true;
    tab[9][9].isWall=true;
    tab[9][6].isWall=true;
    tab[9][5].isWall=true;
    tab[10][9].isWall=true;
    tab[11][8].isWall=true;
    tab[9][7].isWall=true;
    tab[10][3].isWall=true;
    tab[10][2].isWall=true;
    tab[11][14].isWall=true;
    tab[11][13].isWall=true;
    tab[11][11].isWall=true;
    tab[11][9].isWall=true;
    tab[11][7].isWall=true;
    tab[11][6].isWall=true;
    tab[11][5].isWall=true;
    tab[11][4].isWall=true;
    tab[11][2].isWall=true;
    tab[12][14].isWall=true;
    tab[12][12].isWall=true;
    tab[12][11].isWall=true;
    tab[12][4].isWall=true;
    tab[12][2].isWall=true;
    tab[13][14].isWall=true;
    tab[13][12].isWall=true;
    tab[13][11].isWall=true;
    tab[13][9].isWall=true;
    tab[13][7].isWall=true;
    tab[13][6].isWall=true;
    tab[13][5].isWall=true;
    tab[13][4].isWall=true;
    tab[13][2].isWall=true;
    tab[14][9].isWall=true;
    tab[14][2].isWall=true;
    tab[15][14].isWall=true;
    tab[15][13].isWall=true;
    tab[15][12].isWall=true;
    tab[15][11].isWall=true;
    tab[15][9].isWall=true;
    tab[15][7].isWall=true;
    tab[15][6].isWall=true;
    tab[15][5].isWall=true;
    tab[15][4].isWall=true;
    tab[16][15].isWall=true;
    tab[16][14].isWall=true;
    tab[16][11].isWall=true;
    tab[16][9].isWall=true;
    tab[16][4].isWall=true;
    tab[16][2].isWall=true;
    tab[17][14].isWall=true;
    tab[17][13].isWall=true;
    tab[17][11].isWall=true;
    tab[17][9].isWall=true;
    tab[17][8].isWall=true;
    tab[17][7].isWall=true;
    tab[17][5].isWall=true;
    tab[17][4].isWall=true;
    tab[17][2].isWall=true;
    tab[18][9].isWall=true;
    tab[19][14].isWall=true;
    tab[19][13].isWall=true;
    tab[19][12].isWall=true;
    tab[19][11].isWall=true;
    tab[19][7].isWall=true;
    tab[19][6].isWall=true;
    tab[19][5].isWall=true;
    tab[19][2].isWall=true;
    tab[19][4].isWall=true;
    tab[20][13].isWall=true;
    tab[20][11].isWall=true;
    tab[20][9].isWall=true;
    tab[20][6].isWall=true;
    tab[20][4].isWall=true;
    tab[20][2].isWall=true;
    tab[21][14].isWall=true;
    tab[21][13].isWall=true;
    tab[21][12].isWall=true;
    tab[21][9].isWall=true;
    tab[21][7].isWall=true;
    tab[21][6].isWall=true;
    tab[21][5].isWall=true;
    tab[21][2].isWall=true;
    tab[22][10].isWall=true;
    tab[22][9].isWall=true;
    tab[22][3].isWall=true;
    tab[22][2].isWall=true;
    tab[23][14].isWall=true;
    tab[23][13].isWall=true;
    tab[23][12].isWall=true;
    tab[23][11].isWall=true;
    tab[23][9].isWall=true;
    tab[23][7].isWall=true;
    tab[23][6].isWall=true;
    tab[23][5].isWall=true;
    tab[24][11].isWall=true;
    tab[24][9].isWall=true;
    tab[24][7].isWall=true;
    tab[24][5].isWall=true;
    tab[24][3].isWall=true;
    tab[24][2].isWall=true;
    tab[25][14].isWall=true;
    tab[25][13].isWall=true;
    tab[25][12].isWall=true;
    tab[25][11].isWall=true;
    tab[25][7].isWall=true;
    tab[25][6].isWall=true;
    tab[25][5].isWall=true;
    tab[25][4].isWall=true;
    tab[25][3].isWall=true;
    tab[26][9].isWall=true;
    tab[25][2].isWall=true;
    tab[29][7].isWall=true;
    tab[29][9].isWall=true;
    tab[30][7].isWall=true;
    tab[30][9].isWall=true;
    tab[0][7].isWall=true;
    tab[0][9].isWall=true;

    for(int y=1 ; y<Height ; y++) {
        for (int x = 2; x < Width; x++) {

            if(tab[x][y].isWall==0)tab[x][y].isPoint=true;
        }
    }
    tab[8][5].isPoint=false;
    tab[8][6].isPoint=false;
    tab[24][6].isPoint=false;
    tab[20][5].isPoint=false;
    tab[4][11].isPoint=false;
    tab[8][12].isPoint=false;
    tab[20][12].isPoint=false;
    tab[PacX][PacY].isPac=true;
    tab[17][12].isPoint=false;
    tab[16][12].isPoint=false;
    tab[16][13].isPoint=false;
    tab[4][10].isPoint=false;
}

char Data::getFieldInfo(int x, int y) {
    tab[28][7].isWall=true;
    tab[28][9].isWall=true;
    if(tab[x][y].isWall==1)return'W';
    if(tab[x][y].isApple==1)return'A';
    if(tab[x][y].isPoint==1)return'p';
    return 'E';

}

PointState Data::getPointState(){
    for(int x=0 ; x<=Width ; x++) {
        for(int y=0 ; y<=Height ; y++){

            if (tab[x][y].isPoint)return NOTCLEAN;
        }
    }
    return CLEAN;
}


void Data::debug() {
    for(int y=0 ; y<Height ; y++)  {
        for(int x=0 ; x<Width ; x++)  {

            std::cout<<"[";
            if(tab[x][y].isPac==1)std::cout<<"P";
            else std::cout<<".";
            if(tab[x][y].isWall==1)std::cout<<"W";
            else std::cout<<".";
            if(tab[x][y].isGhost==1)std::cout<<"G";
            else std::cout<<".";
            if(tab[x][y].isApple==1)std::cout<<"A";
            else std::cout<<".";
            if(tab[x][y].isPoint==1)std::cout<<"p";
            else std::cout<<".";
            std::cout<<"]";


        }std::cout<<std::endl;
    }std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
}

bool Data::canMove(Direction dir, int x, int y) {
    if (dir == LEFT) {
        if(tab[x-1][y].isWall==1)return false;
        if(tab[x-1][y].isWall==0)return true;
    }
    if (dir == RIGHT) {
        if(tab[x+1][y].isWall==1)return false;
        if(tab[x+1][y].isWall==0)return true;
    }
    if (dir == UP) {
        if(tab[x][y-1].isWall==1)return false;
        if(tab[x][y-1].isWall==0)return true;
    }
    if (dir == DOWN) {
        if(tab[x][y+1].isWall==1)return false;
        if(tab[x][y+1].isWall==0)return true;
    }
}

void Data::setPac(int x, int y,Direction dir) {

    tab[PacX][PacY].isPac=false;
    tab[x][y].isPac=true;
    PacX=x;
    PacY=y;
    PacDir=dir;

}

std::string Data::getScore() {
    std::stringstream ss;
    ss<<Score;
    std::string str= ss.str();
    return str;
}


bool Data::collisionPacGhoast(int x, int y,int xGhoast,int yGhoast) {

    double module=sqrt((x-xGhoast)*(x-xGhoast)+(y-yGhoast)*(y-yGhoast));
    if(module<RectSize*3/5){
        return true;

    }return false;


}

void Data::collisionPacPoint(int x, int y) {

    if(tab[x][y].isPoint){
        tab[x][y].isPoint=false;
        Score++;
    }

}

void Data::collisionPacApple(int x, int y) {

    if(pacState==DEFEND) {
        if (tab[x][y].isApple) {
            tab[x][y].isApple = false;
            pacState = AGRESSIVE;
            agressiveClock.restart();
        }
    }
        if (pacState == AGRESSIVE) {
            if (agressiveClock.getElapsedTime() > sf::milliseconds(5000)) {
                pacState = DEFEND;
            }

        }

}








