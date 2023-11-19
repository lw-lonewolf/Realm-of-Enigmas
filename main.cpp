/* SFML */
#include <SFML/Graphics.hpp>

/* Native */
#include <iostream>
#include <math.h>

/* Header files */
#include "include/Constants.h"
#include "include/Assets.h"

/* Scene files */
#include "src/scenes/DemoScene.cpp"
#include "src/scenes/MenuScene.cpp"

/* Source files */
#include "src/Physics.cpp"
#include "src/Render.cpp"
#include "src/EventHandler.cpp"

/* Override methods: *
 * Functions that override the default Render() and EventHandler() for
 * any custom scene that would need access to these functions.
 *
 * */

void onOverrideEvent(sf::Event event) {
    switch (currentScene.type) {
        case SCENE_MENU:
            menuEventHandler(event);
            break;
    }
}

void onOverrideRender(sf::RenderWindow& window) {
    switch (currentScene.type) {
        case SCENE_MENU:
            onMenuRender(window);
            break;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), WINDOW_TITLE);
    window.setFramerateLimit(REFRESH_RATE);

    UI_FONT_HEAD.loadFromFile(UI_FONT_HEAD_LOCATION);
    UI_FONT_BODY.loadFromFile(UI_FONT_BODY_LOCATION);

    loadScene(initMenuScene());

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