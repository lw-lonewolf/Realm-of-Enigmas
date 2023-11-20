/* Render.cpp
 * This is the heart of the game code. This file has a lot of stuff on player
 * management, scene management and view management that I think can be
 * structured a lot better.
 *
 * */

/* The setView function (should be called "setCamera") sets the camera
 * coordinates according to the position of the character (camera follows player
 * system)
 * */
void setView() {
    if (!currentScene.playerEnabled) return;

    sf::Vector2f playerPos = player.sprite.getPosition();
    sf::Vector2f viewCenter;

    currentScene.view.setCenter(sf::Vector2f(playerPos.x + (PLAYER_SPRITE_WIDTH/2), playerPos.y + (PLAYER_SPRITE_HEIGHT/2)));
    viewCenter = currentScene.view.getCenter();
//    std::cout << "view center: x: " << viewCenter.x << " y: " << viewCenter.y << std::endl;

    int leftCorner = currentScene.view.getSize().x/2;
    int rightCorner = currentScene.background.getSize().x - leftCorner;
    int topCorner = currentScene.view.getSize().y/2;
    int bottomCorner = currentScene.background.getSize().y - topCorner;

    bool isViewPassingLeftSide = viewCenter.x < leftCorner;
    bool isViewPassingTopSide = viewCenter.y < topCorner;

    bool isViewPassingRightSide = viewCenter.x > rightCorner;
    bool isViewPassingBottomSide = viewCenter.y > bottomCorner;


    if (isViewPassingLeftSide && isViewPassingTopSide)
        currentScene.view.setCenter(leftCorner, topCorner);

    else if (isViewPassingRightSide && isViewPassingTopSide)
        currentScene.view.setCenter(rightCorner, topCorner);

    else if (isViewPassingRightSide && isViewPassingBottomSide)
        currentScene.view.setCenter(rightCorner, bottomCorner);

    else if (isViewPassingLeftSide && isViewPassingBottomSide)
        currentScene.view.setCenter(leftCorner, bottomCorner);


    else if (isViewPassingLeftSide)
            currentScene.view.setCenter(leftCorner, viewCenter.y);

    else if (isViewPassingTopSide)
            currentScene.view.setCenter(viewCenter.x, topCorner);

    else if (isViewPassingRightSide)
        currentScene.view.setCenter(rightCorner, viewCenter.y);

    else if (isViewPassingBottomSide)
        currentScene.view.setCenter(viewCenter.x, bottomCorner);
}


/* The loadScene simply loads up the scene passed as the parameter. The previous
 * scene objects are automatically stashed.
 *
 * */
void loadScene(Scene scene) {
    currentScene = scene;

    if (!currentScene.background.loadFromFile(currentScene.backgroundSpritePath))
        std::cout << "Failed to load from file: " << currentScene.backgroundSpritePath << std::endl;

    currentScene.backgroundSprite.setTexture(currentScene.background);
    
    if (!player.texture.loadFromFile(PLAYER_SPRITE_PATH))
        std::cout << "Failed to load from file: " << PLAYER_SPRITE_PATH << std::endl;
    
    player.sprite.setTexture(player.texture);
    player.sprite.setPosition(currentScene.defaultPlayerPos.x - PLAYER_SPRITE_WIDTH/2, currentScene.defaultPlayerPos.y - PLAYER_SPRITE_HEIGHT/2);

    player.moving = false;
    player.currentAnimFrame = 0;
    player.direction = currentScene.defaultPlayerDir;

    playerLoop();
}

void renderInteraction(sf::RenderWindow& window, InteractionPoint interaction) {

    sf::Text interactionTx;
    interactionTx.setString("[E]");
    interactionTx.setFont(UI_FONT_BODY);
    interactionTx.setCharacterSize(UI_BODY_3_SIZE);
    interactionTx.setFillColor(sf::Color::White);
    interactionTx.setPosition(interaction.position.x, interaction.position.y - UI_BODY_3_SIZE);
    interactionTx.setOrigin(UI_BODY_3_SIZE/2, UI_BODY_3_SIZE/2);

    window.draw(interactionTx);
}

/* The UILayer function renders the UI of the game. It renders above the game
 * objects, right after setting the uiView as the view (window.setView).
 *
 * */
void UILayer(sf::RenderWindow& window) {


    if (uiStatus.length()) {// this will be true when the uiStatus has text
        sf::RectangleShape uiStatusBg(sf::Vector2f(SCREEN_W, UI_BODY_2_SIZE + 10));
        uiStatusBg.setPosition(0, SCREEN_H - 10);
        uiStatusBg.setOrigin(sf::Vector2f(0, UI_BODY_2_SIZE));
        uiStatusBg.setFillColor(sf::Color(0, 0, 0, 100));
        window.draw(uiStatusBg);
    }

    sf::Text uiStatusTx;
    uiStatusTx.setString(uiStatus);
    uiStatusTx.setFont(UI_FONT_BODY);
    uiStatusTx.setCharacterSize(UI_BODY_2_SIZE);
    uiStatusTx.setFillColor(sf::Color::White);
    uiStatusTx.setPosition(0, SCREEN_H);
    uiStatusTx.setOrigin(-10, UI_BODY_2_SIZE + 10);

    window.draw(uiStatusTx);
}

/* Debug mode render:
 * This only runs when the DEBUG_MODE is enabled in Constants.h.
 *
 * */
void renderDebug(sf::RenderWindow& window) {
    for (int i = 0; currentScene.interactibles[i].name != INTERACTION_NULL; i++) {
        sf::RectangleShape rect(sf::Vector2f(INTERACTIBLE_THRESHOLD, INTERACTIBLE_THRESHOLD));
        rect.setPosition(sf::Vector2f(currentScene.interactibles[i].position.x - (INTERACTIBLE_THRESHOLD/2), currentScene.interactibles[i].position.y - (INTERACTIBLE_THRESHOLD/2)));
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
    }

    for (int i = 0; !(currentScene.colliderHitboxes[i].width - currentScene.colliderHitboxes[i].height == currentScene.colliderHitboxes[i].width); i++) {
        sf::IntRect hitbox = currentScene.colliderHitboxes[i];

        sf::RectangleShape rect(sf::Vector2f(hitbox.width, hitbox.height));
        rect.setPosition(sf::Vector2f(hitbox.left, hitbox.top));
        rect.setFillColor(sf::Color(255, 0, 0, 100));
        window.draw(rect);
    }
}

void Render(sf::RenderWindow& window) {
    window.clear();

    if (currentScene.type == SCENE_GAME){
        if (currentScene.playerEnabled)
            playerLoop();

        window.setView(currentScene.view);
        window.draw(currentScene.backgroundSprite);

        interactionLoop(window);

        if (currentScene.playerEnabled)
            window.draw(player.sprite);

    }

    onOverrideRender(window);

    if (DEBUG_MODE) renderDebug(window);
    window.setView(uiView);
    UILayer(window);

    framecount++;
    if (framecount > REFRESH_RATE) framecount = 0;

}
