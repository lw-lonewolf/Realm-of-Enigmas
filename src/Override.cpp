/* Override.cpp *
 * This file has functions that override the default Render() and EventHandler()
 * for any custom scene that would need access to these functions.
 *
 * */

void onOverrideEvent(sf::Event event) {
    switch (currentScene.location) {
        /* Each of these cases will detect which specific scene is running
         * currently, and passes the event handling to a function for that
         * scene.
         * */

        case SCENE_MAIN_MENU:
            menuEventHandler(event);
            break;

        /* An example would be:

        case SCENE_TEST_SCENE:
            testSceneEvent(window);
            break;
         */
        }
    }

void onOverrideRender(sf::RenderWindow& window) {
    switch (currentScene.location) {
        /* Each of these cases will detect which specific scene is running
         * currently, and passes the render handling to a function for that
         * scene.
         * */

        case SCENE_MAIN_MENU:
            onMenuRender(window);
            break;

        case SCENE_CREDITS:
            onCreditsRender(window);
            break;

        case SCENE_INTRO:
            onIntroRender(window);
            break;

        /* An example would be:

        case SCENE_TEST_SCENE:
            onTestRender(window);
            break;
        */
    }
}