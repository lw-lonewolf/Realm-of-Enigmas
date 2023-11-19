/* MenuScene.cpp *
 * A non-game scene file. This will be the main menu of the game in production.
 * This scene disables the player movement, and has its methods for Event
 * handling and rendering. (Custom override methods must be defined properly in
 * the onOverrideEvent and onOverrideRender methods properly).
 *
 * */
MenuItem menuCurrentSelection = MENU_PLAY;
const int menuItemsLength = 3;
std::string menuItemNames[menuItemsLength] = {
    "Play",
    "Settings",
    "Quit",
};
void onMenuNavigation(InputAction action, int value = 0) {
    switch (action) {
        case INPUT_NAVIGATE:
            // Incrementing an enum (Casting back and forth between int and enum MenuItem):
            // https://stackoverflow.com/a/3475181
            menuCurrentSelection = (MenuItem)((int)menuCurrentSelection + value);

            if ((int)menuCurrentSelection < 0) menuCurrentSelection = (MenuItem)(menuItemsLength - 1);
            else if ((int)menuCurrentSelection >= menuItemsLength) menuCurrentSelection = (MenuItem)(0);
            break;

        case INPUT_SELECT:
            switch (menuCurrentSelection) {
                case MENU_PLAY:
                    loadScene(initDemoScene());
                    break;

                case MENU_SETTINGS:
                    std::cout << "settings" << std::endl;
                    break;

                case MENU_QUIT:
                    exit(0);
                    break;

            }
            break;

    }
}

void onMenuRender(sf::RenderWindow& window) {
    sf::Text menuTitle("Main menu", UI_FONT_HEAD);
    menuTitle.setCharacterSize(UI_HEAD_1_SIZE);
    menuTitle.setPosition(40, 0);
    menuTitle.setFillColor(sf::Color(200, 200, 200));

    sf::Text menuItems[3];


    for (int i = 0; i < 3; i++) {
        menuItems[i].setString(menuItemNames[i]);
        menuItems[i].setFont(UI_FONT_BODY);
        menuItems[i].setCharacterSize(UI_BODY_1_SIZE);
        menuItems[i].setPosition(40, 45 * (i + 2));
        menuItems[i].setFillColor(sf::Color::White);

        if (menuCurrentSelection == i) {
            sf::Text menuSelection;
            menuSelection.setString(">");
            menuSelection.setFont(UI_FONT_BODY);
            menuSelection.setCharacterSize(UI_BODY_1_SIZE);
            menuSelection.setPosition(10, 45 * (i + 2));
            menuSelection.setFillColor(sf::Color(0, 255, 0));

            menuItems[i].setFillColor(sf::Color(0, 255, 0));
            menuItems[i].setString(menuItemNames[i] + " <");

            window.draw(menuSelection);
        }

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

