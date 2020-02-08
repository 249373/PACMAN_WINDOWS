//
// Created by konrad on 14.05.19.
//

#include "View.h"

View::View(Engine &e):engine(e) {

    if (!Font.loadFromFile("Arial.ttf")) {
        abort();
    }
    RectangleShape.setSize(sf::Vector2f(RectSize,RectSize));
    Point.setFillColor(sf::Color::White);
    Point.setFillColor(sf::Color::White);
    Point.setOrigin(RectSize/9,RectSize/9);
    Point.setRadius(RectSize/9);
    ApplePoint.setFillColor(sf::Color::Red);
    ApplePoint.setOrigin(RectSize/6,RectSize/6);
    ApplePoint.setRadius(RectSize/6);
    ghostRect.setSize(sf::Vector2f(RectSize/2,RectSize/2));
    ghostRect.setFillColor(sf::Color::Red);
    ghostRect.setOrigin(RectSize/4,RectSize/4);

    ScoreText.setCharacterSize(RectSize);\
    ScoreText.setFont(Font);
    ScoreText.setFillColor(sf::Color::Yellow);
    ScoreText.setPosition(5,5);
    ScoreText.setString("SCORE:");

    MapText.setCharacterSize(RectSize);\
    MapText.setFont(Font);
    MapText.setFillColor(sf::Color::Yellow);
    MapText.setPosition(300,5);
    MapText.setString("MAP:");

    finishedText.setFont(Font);
    finishedText.setFillColor(sf::Color(222,255,0,200));
    finishedText.setPosition(225,190);
    finishedText.setString("FINISHED GAME");
    finishedText.setCharacterSize(50);

    finishedText2.setFont(Font);
    finishedText2.setFillColor(sf::Color(222,255,0,200));
    finishedText2.setPosition(165,350);
    finishedText2.setString("PRESS SPACE TO PLAY AGAIN");
    finishedText2.setCharacterSize(35);

    Score.setCharacterSize(RectSize);\
    Score.setFont(Font);
    Score.setFillColor(sf::Color::Yellow);
    Score.setPosition(120,5);

    Map.setCharacterSize(RectSize);\
    Map.setFont(Font);
    Map.setFillColor(sf::Color::Yellow);
    Map.setPosition(390,5);

    PacTexture[0].loadFromFile("Pac1.png");
    if (!PacTexture[0].loadFromFile("Pac1.png")) std::cout << "Textur error";
    PacTexture[1].loadFromFile("Pac2.png");
    if (!PacTexture[1].loadFromFile("Pac2.png")) std::cout << "Textur error";
    PacTexture[2].loadFromFile("Pac3.png");
    if (!PacTexture[2].loadFromFile("Pac3.png")) std::cout << "Textur error";
    PacTexture[3].loadFromFile("Pac4.png");
    if (!PacTexture[3].loadFromFile("Pac4.png")) std::cout << "Textur error";
    PacTexture[4].loadFromFile("Pac5.png");
    if (!PacTexture[4].loadFromFile("Pac5.png")) std::cout << "Textur error";
    PacTexture[5].loadFromFile("Pac6.png");
    if (!PacTexture[5].loadFromFile("Pac6.png")) std::cout << "Textur error";
    PacDead.loadFromFile("deadpac.png");
    if (!PacDead.loadFromFile("deadpac.png")) std::cout << "Textur error";
    PacSprite.setTexture(PacTexture[0]);
    PacSprite.setColor(sf::Color(255, 255, 255,255));
    PacSprite.setOrigin((sf::Vector2f(45,45)));
    PacSprite.setScale(sf::Vector2f(Scale,Scale));

    blinkyTexture[0].loadFromFile("duch31.png");
    if (!blinkyTexture[0].loadFromFile("duch31.png")) std::cout << "Textur error";
    blinkyTexture[1].loadFromFile("duch32.png");
    if (!blinkyTexture[1].loadFromFile("duch32.png")) std::cout << "Textur error";
    blinkyTexture[2].loadFromFile("duch33.png");
    if (!blinkyTexture[2].loadFromFile("duch33.png")) std::cout << "Textur error";
    blinkySprite.setTexture(blinkyTexture[2]);
    blinkySprite.setColor(sf::Color(255,255,255,255));
    blinkySprite.setOrigin((sf::Vector2f(45,45)));
    blinkySprite.setScale(sf::Vector2f(Scale,Scale));


    randomTexture[0].loadFromFile("duch21.png");
    if (!randomTexture[0].loadFromFile("duch21.png")) std::cout << "Textur error";
    randomTexture[1].loadFromFile("duch22.png");
    if (!randomTexture[1].loadFromFile("duch22.png")) std::cout << "Textur error";
    randomTexture[2].loadFromFile("duch23.png");
    if (!randomTexture[2].loadFromFile("duch23.png")) std::cout << "Textur error";
    randomSprite.setTexture(randomTexture[2]);
    randomSprite.setColor(sf::Color(255,255,255,255));
    randomSprite.setOrigin((sf::Vector2f(45,45)));
    randomSprite.setScale(sf::Vector2f(Scale,Scale));

    pinkyTexture[0].loadFromFile("duch11.png");
    if (!pinkyTexture[0].loadFromFile("duch11.png")) std::cout << "Textur error";
    pinkyTexture[1].loadFromFile("duch12.png");
    if (!pinkyTexture[1].loadFromFile("duch12.png")) std::cout << "Textur error";
    pinkyTexture[2].loadFromFile("duch13.png");
    if (!pinkyTexture[2].loadFromFile("duch13.png")) std::cout << "Textur error";
    pinkySprite.setTexture(pinkyTexture[2]);
    pinkySprite.setColor(sf::Color(255,255,255,255));
    pinkySprite.setOrigin((sf::Vector2f(45,45)));
    pinkySprite.setScale(sf::Vector2f(Scale,Scale));

    fearTexture[0].loadFromFile("duchprzemiana1.png");
    if (!fearTexture[0].loadFromFile("duchprzemiana1.png")) std::cout << "Textur error";
    fearTexture[1].loadFromFile("duchprzemiana3.png");
    if (!fearTexture[1].loadFromFile("duchprzemiana3.png")) std::cout << "Textur error";
    fearTexture[2].loadFromFile("duchprzemiana2.png");
    if (!fearTexture[2].loadFromFile("duchprzemiana2.png")) std::cout << "Textur error";
    fearSprite.setTexture(fearTexture[2]);
    fearSprite.setColor(sf::Color(255,255,255,255));
    fearSprite.setOrigin((sf::Vector2f(45,45)));
    fearSprite.setScale(sf::Vector2f(Scale,Scale));

    finishedRect.setFillColor(sf::Color(50,50,200,200));
    finishedRect.setPosition(110,108);
    finishedRect.setSize(sf::Vector2f(600,393));

    for(int i=0 ; i<4 ; i++) {
        ghost[i] = engine.getGhost((EnumGhost)i);
    }
}

void View::draw(sf::RenderWindow &win) {
        agressiveClock = data->getPacClock();

        for (int i = 0; i < 4; i++) {
            if (!ghost[i]->isAlive()) {
                ghost[i] = engine.rebuildGhost((EnumGhost) i);
            }
        }
        if(engine.getMustGet()){
            data = engine.getBoard();
            pac = engine.getPac();
            for (int i = 0; i < 4; i++) {
                ghost[i] = engine.getGhost((EnumGhost) i);
            }
        }
        for (int y = 0; y <= data->getHeight(); y++) {
            for (int x = 0; x <= data->getWidth(); x++) {
                RectangleShape.setPosition(3 + (x - 1) * RectSize, 50 + y * RectSize);
                if ((data->getFieldInfo(x, y)) == 'W') {
                    RectangleShape.setFillColor(sf::Color(96, 112, 150));
                    win.draw(RectangleShape);
                }
                if (data->getFieldInfo(x, y) == 'p') {
                    Point.setPosition(3 + (x - 1) * RectSize + RectSize / 2, 50 + y * RectSize + RectSize / 2);
                    win.draw(Point);
                }
                if (data->getFieldInfo(x, y) == 'A') {
                    Point.setFillColor(sf::Color::Red);
                    Point.setRadius(RectSize / 4);
                    Point.setOrigin(RectSize / 4, RectSize / 4);
                    Point.setPosition(3 + (x - 1) * RectSize + RectSize / 2, 50 + y * RectSize + RectSize / 2);
                    win.draw(Point);
                    Point.setFillColor(sf::Color::White);
                    Point.setOrigin(RectSize / 9, RectSize / 9);
                    Point.setRadius(RectSize / 9);
                }
            }
        }
        setTexture();

        PacSprite.setPosition(pac->getX(), pac->getY());
        setRotation(PacSprite);
        win.draw(PacSprite);

        blinkySprite.setPosition(ghost[0]->getX(), ghost[0]->getY());
        win.draw(randomSprite);

        randomSprite.setPosition(ghost[1]->getX(), ghost[1]->getY());
        win.draw(blinkySprite);

        pinkySprite.setPosition(ghost[2]->getX(), ghost[2]->getY());
        win.draw(pinkySprite);

        blinkySprite.setPosition(ghost[3]->getX(), ghost[3]->getY());
        win.draw(blinkySprite);

        win.draw(ScoreText);
        Score.setString(data->getScore());
        win.draw(Score);
        win.draw(MapText);

        Map.setString(engine.getMap());
        win.draw(Map);

         if(data->getGameState()==FINISHED) {
             win.draw(finishedRect);
             win.draw(finishedText);
             win.draw((finishedText2));
         }
}

void View::setRotation(sf::Sprite &s) {
    s.setScale(sf::Vector2f(Scale,Scale));
    if(pac->getDirections()==LEFT){
        s.setRotation(0);
        s.setScale(sf::Vector2f(-Scale,Scale));
    }
    if(pac->getDirections()==RIGHT)s.setRotation(0);
    if(pac->getDirections()==UP)s.setRotation(270);
    if(pac->getDirections()==DOWN)s.setRotation(90);

}

void View::setTexture() {

    time1 += clock1.restart();
    if (time1 >= sf::milliseconds(50)) {
        time1 -= sf::milliseconds(50);

        if (TextureSwitch == 1) {
            if(agressiveClock.getElapsedTime()>sf::milliseconds(5000)) {
                blinkySprite.setTexture(blinkyTexture[iGhost]);
                randomSprite.setTexture(randomTexture[iGhost]);
                pinkySprite.setTexture(pinkyTexture[iGhost]);
            }
            else {
                blinkySprite.setTexture(fearTexture[iGhost]);
                randomSprite.setTexture(fearTexture[iGhost]);
                pinkySprite.setTexture(fearTexture[iGhost]);
            }

            if(agressiveClock.getElapsedTime()>sf::seconds(3)) {

                if (iGhost >= 2)iGhost = 0;
                else iGhost++;
            }
            else if(agressiveClock.getElapsedTime()<sf::seconds(3)){
                if (iGhost >= 1)iGhost = 0;
                else iGhost++;
            }
        }

        if(data->getGameState()!=FINISHED) {
            if (TextureSwitch == 1) {
                PacSprite.setTexture(PacTexture[0]);
            }
            if (TextureSwitch == 2) {
                PacSprite.setTexture(PacTexture[1]);

            }
            if (TextureSwitch == 3) {
                PacSprite.setTexture(PacTexture[2]);
               // blinkySprite.setTexture(blinkyTexture[1]);
            }
            if (TextureSwitch == 4) {
                PacSprite.setTexture(PacTexture[3]);

            }
            if (TextureSwitch == 5) {
                PacSprite.setTexture(PacTexture[4]);
               // blinkySprite.setTexture(blinkyTexture[2]);
            }
            if (TextureSwitch == 6) {
                PacSprite.setTexture(PacTexture[5]);

            }
        }
            if (TextureSwitch == 5)TextureSwitch = 0;
            else TextureSwitch++;


    } else if (data->getGameState() == FINISHED) PacSprite.setTexture((PacDead));

}

