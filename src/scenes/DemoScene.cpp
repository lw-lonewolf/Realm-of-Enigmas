Scene initDemoScene() {
    Scene scene;

    scene.backgroundSpritePath = BACKGROUND_DEMO_PATH;
    scene.defaultPlayerDir = PLAYER_SPRITE_DOWN;
    scene.defaultPlayerPos = sf::Vector2f(100.f, 100.f);
    scene.colliderHitboxes[0] = sf::IntRect(200, 200, 200, 200);
    scene.colliderHitboxes[1] = sf::IntRect(500, 500, 200, 200);
    return scene;
}