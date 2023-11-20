Scene initTestScene() {
    Scene scene;

    scene.name = "Test scene";
    scene.type = SCENE_GAME;
    scene.backgroundSpritePath = BACKGROUND_TEST_PATH;
    scene.defaultPlayerPos = sf::Vector2f(200, 200);
    scene.defaultPlayerDir = PLAYER_SPRITE_DOWN;

    scene.view = sf::View(scene.defaultPlayerPos, sf::Vector2f(400.f, 300.f));

    InteractionPoint changeSceneInteraction;
    changeSceneInteraction.name = INTERACTION_TRAVEL;
    changeSceneInteraction.label = "Back to Demo";
    changeSceneInteraction.travelTo = TRAVEL_DEMO_SCENE;
    changeSceneInteraction.position = sf::Vector2f(135, 115);

    scene.interactibles[0] = changeSceneInteraction;

    return scene;
}