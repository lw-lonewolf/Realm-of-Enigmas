#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/Constants.h"
#include "src/Render.cpp"
#include "src/EventHandler.cpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), WINDOW_TITLE);
    window.setFramerateLimit(REFRESH_RATE);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {                
            EventHandler(event);
            
            if (event.type == sf::Event::Closed)
            
                window.close();
        }

        window.clear();
        Render(window);
        window.display();
    }

    return 0;    
}