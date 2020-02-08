#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.h"
#include "View.h"
#include <cstdlib>

int main() {


    //liczniki czasu w całym programie wzorowane na https://4programmers.net/Forum/C_i_C++/256710-sfml_timer_oraz_przekazywanie_elemntow_vector_do_stosu
    //moje liczniki z pierwszych wersji nadawały się tylko do jednorazowego pomiaru czasu(potrzeba cykilcznego)
    //do testowania polecam zmniejszyć ilośc białych punktów do zbierania(W konstruktorze Data.cpp)
    srand(time(NULL));

    sf::ContextSettings settings;
    settings.antialiasingLevel=16;

    sf::RenderWindow win(sf::VideoMode(820, 562), "PacMan",sf::Style::Default,settings);
    win.setFramerateLimit(60);

    Engine engine;
    View view(engine);

    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();
                engine.handleEvent(event);

        }
        engine.runEngine();

        win.clear(sf::Color(35,42,52));

        view.draw(win);

        win.display();

    }
    return 0;
}