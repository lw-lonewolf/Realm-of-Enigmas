/* Override.cpp *
 * This file has functions that override the default Render() and EventHandler()
 * for any custom scene that would need access to these functions.
 *
 * */

void onOverrideEvent(sf::Event event) {
    switch (currentScene.type) {
        /* Each of these cases will detect which specific scene is running
         * currently, and passes the event handling to a function for that
         * scene.
         * */

        case SCENE_MENU:
            menuEventHandler(event);
            break;
    }
}

void onOverrideRender(sf::RenderWindow& window) {
    switch (currentScene.type) {
        /* Each of these cases will detect which specific scene is running
         * currently, and passes the render handling to a function for that
         * scene.
         * */

        case SCENE_MENU:
            onMenuRender(window);
            break;
    }
}