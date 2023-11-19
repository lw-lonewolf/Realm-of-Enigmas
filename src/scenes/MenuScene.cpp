/* MenuScene.cpp *
 * A non-game scene file. This will be the main menu of the game in production.
 * This scene disables the player movement, and has its methods for Event
 * handling and rendering. (Custom override methods must be defined properly in
 * the onOverrideEvent and onOverrideRender methods properly).
 *
 * */

void onMenuNavigation(InputAction action, int value = 0) {

}

void onMenuRender(sf::RenderWindow& window) {
    sf::Text menuTitle("Main menu", UI_FONT_HEAD);
    menuTitle.setCharacterSize(UI_HEAD_1_SIZE);
    menuTitle.setPosition(25, 0);
    menuTitle.setFillColor(sf::Color(200, 200, 200));

    sf::Text menuItems[3];
    std::string menuItemNames[3] = {
            "Play",
            "Settings",
            "Quit",
    };

    for (int i = 0; i < 3; i++) {
        menuItems[i].setString(menuItemNames[i]);
        menuItems[i].setFont(UI_FONT_BODY);
        menuItems[i].setCharacterSize(UI_BODY_1_SIZE);
        menuItems[i].setCharacterSize(UI_BODY_1_SIZE);
        menuItems[i].setPosition(25, 45 * (i + 2));
        menuItems[i].setFillColor(sf::Color::White);
        window.draw(menuItems[i]);
    }

    window.draw(menuTitle);
}


Scene initMenuScene() {
    Scene scene;

    scene.name = "Main menu";
    scene.type = SCENE_MENU;
    scene.backgroundSpritePath = BACKGROUND_TEST_PATH;
    scene.playerEnabled = false;


    return scene;
}

