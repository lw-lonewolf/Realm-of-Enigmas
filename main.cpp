#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/Constants.h"
#include "src/Sprites.h"
#include "src/Render.cpp"
#include "src/Physics.cpp"
#include "src/EventHandler.cpp"

#include "src/scenes/DemoScene.cpp"


int main() {
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), WINDOW_TITLE);
    window.setFramerateLimit(REFRESH_RATE);

    loadScene(initDemoScene());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {                
            EventHandler(event);
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        PhysicsLoop();
        Render(window);
        window.display();
    }

    return 0;    
}