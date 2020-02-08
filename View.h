//
// Created by konrad on 14.05.19.
//

#ifndef PACMAN_VIEW_H
#define PACMAN_VIEW_H

#include "Engine.h"

#include <SFML/Graphics.hpp>


class View {
    Engine &engine;
    Data *data=engine.getBoard();
    PacMan *pac=engine.getPac();
    Ghost *ghost[4];
    sf::RectangleShape RectangleShape;
    sf::RectangleShape ghostRect;
    sf::CircleShape Point;
    sf::CircleShape ApplePoint;
    int RectSize=pac->getRectSize();
    sf::Text Score;
    sf::Text ScoreText;
    sf::Text Map;
    sf::Text MapText;
    sf::Font Font;
    sf::Sprite PacSprite;
    sf::Texture PacTexture[6];
    sf::Texture PacDead;
    sf::Sprite blinkySprite;
    sf::Sprite randomSprite;
    sf::Sprite pinkySprite;
    sf::Sprite fearSprite;
    sf::Texture blinkyTexture[3];
    sf::Texture randomTexture[3];
    sf::Texture pinkyTexture[3];
    sf::Texture fearTexture[3];
    sf::Clock clock1;
    sf::Time time1;
    sf::Clock &agressiveClock=data->getPacClock();
    int TextureSwitch=0;
    int iGhost=0;
    double Scale=((double)RectSize)/90;
    sf::RectangleShape finishedRect;
    sf::Text finishedText;
    sf::Text finishedText2;
public:
    View(Engine &e);
    void setRotation(sf::Sprite &s);
    void draw(sf::RenderWindow&win);
    void setTexture();
};

#endif //PACMAN_VIEW_H
