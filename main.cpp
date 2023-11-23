/* SFML */
#include <SFML/Graphics.hpp>

/* Native */
#include <iostream>
#include <math.h>

/* Header files */
#include "include/Constants.h"
#include "include/Assets.h"
#include "include/Globals.h"

/* Data loading files */
#include "src/Dialog.cpp"
#include "src/Preload.cpp"

/* Scene files */
#include "src/scenes/DemoScene.cpp"
#include "src/scenes/MenuScene.cpp"
#include "src/scenes/TestScene.cpp"

/* Source files */
#include "src/Helper.cpp"
#include "src/UI.cpp"
#include "src/Physics.cpp"
#include "src/Game.cpp"
#include "src/Render.cpp"
#include "src/EventHandler.cpp"
#include "src/Override.cpp"

int main() {
    // Code starts off here, setting up the window:

    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), WINDOW_TITLE);
    window.setFramerateLimit(REFRESH_RATE);

    uiView = sf::View(sf::Vector2f(SCREEN_W/2, SCREEN_H/2), sf::Vector2f(SCREEN_W, SCREEN_H));
    
    // Preloading the fonts and UI spritesheet:
    loadAssets();

    // Loading the first scene, the MenuScene.cpp: (initMenuScene is defined in
    // MenuScene.cpp)

    loadScene(initTestScene());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {                
            // All events go straight to the EventHandler in the
            // EventHandler.cpp file. The event handling is forked down to
            // various levels in that file.
            EventHandler(event);
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // This PhysicsLoop (Physics.cpp) ensures the player is not inside of any
        // hitboxes before any rendering occurs.

        PhysicsLoop();

        // Finally, when everything is set, the Render (Render.cpp) renders all
        // the relevant stuff onto the screen. (This also manages other stuff
        // that may occur while rendering.

        Render(window);
        window.display();
    }

    return 0;
}