int framecount = 0;

Scene currentScene;

void playerLoop() {
    if (!player.moving) 
        player.currentAnimFrame = 0;
    else if (framecount % (REFRESH_RATE * PLAYER_ANIM_SPEED / 1000) == 0) {
        player.currentAnimFrame++;
        if (player.currentAnimFrame > PLAYER_ANIM_FRAMES)
            player.currentAnimFrame = 1;
    }

    if (player.moving) {
        player.sprite.move(player.movementVector);
        if (player.movementVector.x == 0 && player.movementVector.y == 0)
            player.moving = false;

        if (player.movementVector.x == -1) player.direction = PLAYER_SPRITE_LEFT;
        if (player.movementVector.x == 1) player.direction = PLAYER_SPRITE_RIGHT;
        if (player.movementVector.y == -1) player.direction = PLAYER_SPRITE_UP;
        if (player.movementVector.y == 1) player.direction = PLAYER_SPRITE_DOWN;
    }
        

    std::cout << player.currentAnimFrame * PLAYER_SPRITE_SIZE << " " << player.direction * PLAYER_SPRITE_SIZE << std::endl;
    
    // sf::IntRect positionRect = sf::IntRect(0, 0, 64, 64);
    sf::IntRect positionRect = sf::IntRect(player.currentAnimFrame * PLAYER_SPRITE_SIZE, player.direction * PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE);
    player.sprite.setTextureRect(positionRect);
}

void loadScene(Scene scene) {
    currentScene = scene;

    if (!currentScene.background.loadFromFile(currentScene.backgroundSpritePath))
        std::cout << "Failed to load from file: " << currentScene.backgroundSpritePath << std::endl;

    currentScene.backgroundSprite.setTexture(currentScene.background);
    
    if (!player.texture.loadFromFile(PLAYER_SPRITE_PATH))
        std::cout << "Failed to load from file: " << PLAYER_SPRITE_PATH << std::endl;
    
    player.sprite.setTexture(player.texture);
    player.sprite.setPosition(currentScene.defaultPlayerPos);

    player.moving = false;
    player.currentAnimFrame = 0;
    player.direction = currentScene.defaultPlayerDir;

    playerLoop();
}

void Render(sf::RenderWindow& window) {
    window.clear();
    playerLoop();

    window.draw(currentScene.backgroundSprite);
    window.draw(player.sprite);
    framecount++;
    if (framecount > REFRESH_RATE) framecount = 0;
}
