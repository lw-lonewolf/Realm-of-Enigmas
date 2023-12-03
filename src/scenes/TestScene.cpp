Scene initTestScene()
{
    Scene scene;

    scene.name = "Test scene";
    scene.type = SCENE_GAME;
    scene.location = SCENE_TEST_SCENE;
    scene.backgroundSpritePath = BACKGROUND_TEST_PATH;
    scene.defaultPlayerPos = sf::Vector2f(200, 200);
    scene.defaultPlayerDir = PLAYER_SPRITE_DOWN;

    scene.view = sf::View(scene.defaultPlayerPos, sf::Vector2f(400.f, 300.f));

    scene.animatedSprites[0] = guideChar;
    scene.animatedSprites[0].position = sf::Vector2f(236, 189);

    scene.colliderHitboxes[0] = sf::IntRect(0, 0, 300, 100);
    scene.colliderHitboxes[1] = sf::IntRect(0, 0, 100, 200);
    scene.colliderHitboxes[2] = sf::IntRect(0, 200, 45, 200);
    scene.colliderHitboxes[3] = sf::IntRect(sf::Vector2i(scene.animatedSprites[0].position), sf::Vector2i(32, 32));

    InteractionPoint changeSceneInteraction;
    changeSceneInteraction.name = INTERACTION_TRAVEL;
    changeSceneInteraction.label = "Enter the mysterious cave";
    changeSceneInteraction.travelTo = SCENE_OPTIMUS;
    changeSceneInteraction.position = sf::Vector2f(130, 110);

    scene.interactibles[0] = changeSceneInteraction;

    InteractionPoint talkToGuideInteraction;
    talkToGuideInteraction.name = INTERACTION_TALK;
    talkToGuideInteraction.label = "Talk to ???";
    talkToGuideInteraction.position = scene.animatedSprites[0].position;
    talkToGuideInteraction.dialog = testDialog();
    talkToGuideInteraction.associatedNPC = scene.animatedSprites[0];

    scene.interactibles[1] = talkToGuideInteraction;

    return scene;
}
