#include <cstdlib>

const float ROCK_FALL_SPEED = 100.0f; // Adjust this value as needed

const int rockGameGroundheight = 516;
const int charheight = 16;

// Initialize the rocks, character, and ground
int MaxRocks;

// Initialize the game loop variables
float timeElapsed;

struct Ground {
    sf::Sprite sprite;
    sf::Texture texture;

    Ground() {
        if (!texture.loadFromFile("assets/imgs/grass.png")) {
            std::cout << "Failed to load Ground." << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(0, rockGameGroundheight);
    }
};

sf::Sprite sceneRocks[8];
Ground ground;

void initRocks(sf::Sprite sceneRocks[], int MaxRocks) {
    sf::Vector2u textureSize = rockTexture.getSize();

    for (int i = 0; i < 8; ++i) {
        float x = (float)(rand() % (int)(SCREEN_W - textureSize.x));
        float y = (float)(rand() % (int)(SCREEN_H - textureSize.y)) - SCREEN_H;
        float yOffset = (float)(rand() % 100);  // Adjust the range as needed
        sceneRocks[i].setTexture(rockTexture);
        sceneRocks[i].setPosition(x, y + yOffset);
    }
}

bool isIntersecting(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}

void adjustRocks(sf::Sprite sceneRocks[], int MaxRocks) {
    sf::Vector2u textureSize = rockTexture.getSize();

    // Collision check and adjustment
    for (int i = 0; i < MaxRocks; ++i) {
        for (int j = i + 1; j < MaxRocks; ++j) {
            if (isIntersecting(sceneRocks[i], sceneRocks[j])) {
                float x = static_cast<float>(rand() % static_cast<int>(800 - textureSize.x));
                sceneRocks[j].setPosition(x, -50);
            }
            if (isIntersecting(sceneRocks[i], ground.sprite)) {
                float x = static_cast<float>(rand() % static_cast<int>(800 - textureSize.x));
                sceneRocks[i].setPosition(x, -50);
            }
            if (isIntersecting(sceneRocks[i], player.sprite)) {
                float x = static_cast<float>(rand() % static_cast<int>(800 - textureSize.x));
                sceneRocks[i].setPosition(x, -50);
                miniGameDefeat(MINIGAME_ROCK_FALLING);
            }
        }
    }
}


void updateRocks(sf::Sprite sceneRocks[], float dt, int MaxRocks) {
    sf::Vector2u textureSize = rockTexture.getSize();

    // Move rocks
    for (int i = 0; i < MaxRocks; ++i) {
        sf::Vector2f position = sceneRocks[i].getPosition();

        if (position.y < rockGameGroundheight + charheight) {
            // Move the rock down with a speed based on delta time
            sceneRocks[i].setPosition(position.x, position.y + ROCK_FALL_SPEED * dt);
        } else {
            float x = static_cast<float>(rand() % static_cast<int>(SCREEN_W - textureSize.x));
            float y = static_cast<float>(rand() % static_cast<int>(SCREEN_H - textureSize.y)) - SCREEN_H;
            float yOffset = static_cast<float>(rand() % 100);  // Adjust the range as needed
            sceneRocks[i].setPosition(x, y + yOffset);
        }
    }

    // Adjust rocks after moving
    adjustRocks(sceneRocks, MaxRocks);
}
//
//
//void handleInput(Player& player) {
//    // Example: Move the character left and right with arrow keys
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        player.sprite.move(-0.05f, 0.0f);
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        player.sprite.move(0.05f, 0.0f);
//    }
//}

void spawnRate() {
    if (timeElapsed <= 2) {
        MaxRocks = 4;
    } else if (timeElapsed <= 6) {
        MaxRocks = 8;
    } else {
        miniGameVictory(MINIGAME_ROCK_FALLING, keysStore.rock);
    }
}

void RockSceneRender(sf::RenderWindow& window) {
    // Handle player input
//    handleInput(player);
    // Update the game
//    float dt = gameClock.restart().asSeconds();
    float dt = (float)(framecount == REFRESH_RATE - 1);
    timeElapsed += dt;
    std::cout << timeElapsed << std::endl;
    spawnRate();
    updateRocks(sceneRocks, (20 + timeElapsed) / 1000, MaxRocks);

    // Draw the game
    window.draw(ground.sprite);  // Draw ground first
    for (int i = 0; i < MaxRocks; ++i) {
        window.draw(sceneRocks[i]);
    }

}

void onRockSceneShown() {
    MaxRocks = 8;
    timeElapsed = 0.f;
    initRocks(sceneRocks, MaxRocks);
}

Scene initRockScene() {
    music.stop();
    Scene scene;

    scene.name = "Rock Scene";
    scene.type = SCENE_CUSTOM;
    scene.location = SCENE_ROCK_GAME;
    scene.backgroundSpritePath = BACKGROUND_ROCK_PATH;
    scene.horizontalMovementOnly = true;
    scene.defaultPlayerPos = sf::Vector2f(400, 436);
    scene.defaultPlayerDir = PLAYER_SPRITE_RIGHT;
    scene.view = sf::View(sf::FloatRect(0, 0, 500, SCREEN_H));

    return scene;
    music.getLoop(true);
    music.setVolume(50);
    initMusic(ROCK_GAME_MUSIC);
    
 }

