/* Render.cpp
 * This is the heart of the game code. This file has a lot of stuff on player
 * management, scene management and view management that I think can be
 * structured a lot better.
 *
 * */

void onOverrideRender(sf::RenderWindow& window);
int framecount = 0;

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

void playerLoop() {
    if (!player.moving)
        player.currentAnimFrame = 0;
    else if (framecount % (REFRESH_RATE * PLAYER_ANIM_SPEED / 1000) == 0) {
        player.currentAnimFrame++;
        if (player.currentAnimFrame > PLAYER_ANIM_FRAMES)
            player.currentAnimFrame = 1;
    }

    if (player.moving) {
        player.prevPosition = player.sprite.getPosition();


        if (player.movementVector.x/PLAYER_MOVE_MULTIPLIER == -1) player.direction = PLAYER_SPRITE_LEFT;
        if (player.movementVector.x/PLAYER_MOVE_MULTIPLIER == 1) player.direction = PLAYER_SPRITE_RIGHT;
        if (player.movementVector.y/PLAYER_MOVE_MULTIPLIER == -1) player.direction = PLAYER_SPRITE_UP;
        if (player.movementVector.y/PLAYER_MOVE_MULTIPLIER == 1) player.direction = PLAYER_SPRITE_DOWN;

        // Validate new player position before moving the player sprite

        if (PhysicsValidatePosition(sf::Vector2f(player.sprite.getPosition().x + player.movementVector.x, player.sprite.getPosition().y)))
            player.sprite.move(sf::Vector2f(player.movementVector.x, 0));

        if (PhysicsValidatePosition(sf::Vector2f(player.sprite.getPosition().x, player.sprite.getPosition().y + player.movementVector.y)))
            player.sprite.move(sf::Vector2f(0, player.movementVector.y));

        if (player.movementVector.x == 0 && player.movementVector.y == 0)
            player.moving = false;
    }
        


    sf::IntRect positionRect = sf::IntRect(player.currentAnimFrame * PLAYER_SPRITE_WIDTH, player.direction * PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
    player.sprite.setTextureRect(positionRect);

    setView();
}

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

void Render(sf::RenderWindow& window) {
    window.clear();
    if (currentScene.type == SCENE_GAME){
        if (currentScene.playerEnabled)
            playerLoop();

        window.setView(currentScene.view);
        window.draw(currentScene.backgroundSprite);
        if (currentScene.playerEnabled)
            window.draw(player.sprite);
    }
    framecount++;
    if (framecount > REFRESH_RATE) framecount = 0;
    onOverrideRender(window);
}
