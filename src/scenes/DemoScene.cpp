Scene initDemoScene() {
    Scene scene;

    scene.backgroundSpritePath = BACKGROUND_DEMO_PATH;
    scene.defaultPlayerDir = PLAYER_SPRITE_DOWN;
    scene.defaultPlayerPos = sf::Vector2f(173.f, 244.f);
    
    scene.colliderHitboxes[0] = sf::IntRect(330, 125, 35, 62);
    scene.colliderHitboxes[1] = sf::IntRect(422, 128, 90, 80);
    scene.colliderHitboxes[2] = sf::IntRect(100, 110, 150, 110);
    scene.colliderHitboxes[3] = sf::IntRect(66, 0, 126, 153);
    scene.colliderHitboxes[4] = sf::IntRect(192, 68, 30, 32);
    scene.colliderHitboxes[5] = sf::IntRect(192, 0, 351, 70);
    
    
    return scene;
}