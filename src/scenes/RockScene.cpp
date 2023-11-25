#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "../../include/Constants.h"

struct Rock {
    sf::Sprite sprite;
    sf::Texture texture;

    if(!texture.loadFromFile("../../assets/sprites/DawayneJohnsun.png")) {
        std::cout << "Failed to load Rock." << std::endl;
    }

};

const int MAX_ROCKS = 8;
const float ROCK_FALL_SPEED = 100.0f;  // Adjust this value as needed

void initRocks(Rock sceneRocks[MAX_ROCKS]) {
    sf::Vector2u textureSize = sceneRocks[0].texture.getSize();

    for (int i = 0; i < MAX_ROCKS; ++i) {
        float x = static_cast<float>(rand() % (scene.screenWidth - textureSize.x));
        float y = static_cast<float>(rand() % (scene.screenHeight - textureSize.y));
        sceneRocks[i].sprite.setTexture(sceneRocks[i].texture);
        sceneRocks[i].sprite.setPosition(x, y);
    }
}

void updateRocks(Rock sceneRocks[MAX_ROCKS], float dt, int groundheight, int charheight) {
    for (int i = 0; i < MAX_ROCKS; ++i) {
        sf::Vector2f position = sceneRocks[i].sprite.getPosition();

        if (position.y > groundheight + charheight) {
            if (player.y >= position.y + textureSize.y) {
                // If player is below the rock, remove the rock
                sceneRocks[i].sprite.setPosition(-1000.f, -1000.f);  // Move the rock out of the visible area
            } else {
                // Move the rock down with a speed based on delta time
                sceneRocks[i].sprite.setPosition(position.x, position.y + ROCK_FALL_SPEED * dt);
            }
        }
    }
}

void spawnRate(float timeElapsed, int& MaxRocks) {
    if (timeElapsed <= 30) {
        MaxRocks = 4;
    } else if (timeElapsed <= 120) {
        MaxRocks = 8;
    }
}



Scene initRockScene() {
    Scene scene;

    scene.name = "Rock Scene";
    scene.type = SCENE_CUSTOM;
    scene.location = SCENE_ROCK_SCENE;
    scene.backgroundSpritePath = BACKGROUND_ROCK_PATH;
    scene.defaultPlayerDir = PLAYER_SPRITE_DOWN;
    scene.defaultPlayerPos = sf::Vector2f(173.f, 250.f);

    scene.view = sf::View(scene.defaultPlayerPos, sf::Vector2f(400.f, 300.f));

    scene.colliderHitboxes[0] = sf::IntRect(330, 125, 16, 16);

    return scene;
}

