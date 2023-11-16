/* SFML */
#include <SFML/Graphics.hpp>

/* Native */
#include <iostream>
#include <math.h>

/* Header files */
#include "src/Constants.h"
#include "src/Sprites.h"

/* Source files */
#include "src/Physics.cpp"
#include "src/Render.cpp"
#include "src/EventHandler.cpp"

/* Scene files */
#include "src/scenes/DemoScene.cpp"

int main() {
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