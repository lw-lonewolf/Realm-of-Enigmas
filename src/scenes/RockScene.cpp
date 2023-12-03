#include <cstdlib>

const float ROCK_FALL_SPEED = 100.0f; // Adjust this value as needed

const int rockGameGroundheight = 516;
const int charheight = 16;

// Initialize the rocks, character, and ground
int MaxRocks = 8;

// Initialize the game loop variables
float timeElapsed = 0.f;

struct Rock {
    sf::Sprite sprite;
    sf::Texture texture;
};


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

Rock sceneRocks[4];
Ground ground;

void initRocks(Rock sceneRocks[], int MaxRocks) {
    sf::Vector2u textureSize = sceneRocks[0].texture.getSize();

    for (int i = 0; i < MaxRocks; ++i) {
        float x = (float)(rand() % (int)(SCREEN_W - textureSize.x));
        float y = (float)(rand() % (int)(SCREEN_H - textureSize.y)) - SCREEN_H;
        float yOffset = (float)(rand() % 100);  // Adjust the range as needed
        sceneRocks[i].sprite.setTexture(rockTexture);
        sceneRocks[i].sprite.setPosition(x, y + yOffset);
    }
}

bool isIntersecting(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}

void adjustRocks(Rock sceneRocks[], const Ground& ground, int MaxRocks) {
    sf::Vector2u textureSize = sceneRocks[0].texture.getSize();

    // Collision check and adjustment
    for (int i = 0; i < MaxRocks; ++i) {
        for (int j = i + 1; j < MaxRocks; ++j) {
            if (isIntersecting(sceneRocks[i].sprite, sceneRocks[j].sprite)) {
                float x = static_cast<float>(rand() % static_cast<int>(800 - textureSize.x));
                sceneRocks[j].sprite.setPosition(x, -50);
            }
            if (isIntersecting(sceneRocks[i].sprite, ground.sprite)) {
                float x = static_cast<float>(rand() % static_cast<int>(800 - textureSize.x));
                sceneRocks[i].sprite.setPosition(x, -50);
            }
            if (isIntersecting(sceneRocks[i].sprite, player.sprite)) {
                float x = static_cast<float>(rand() % static_cast<int>(800 - textureSize.x));
                sceneRocks[i].sprite.setPosition(x, -50);
            }
        }
    }
}


void updateRocks(Rock sceneRocks[], float dt, int MaxRocks, const Ground& ground) {
    sf::Vector2u textureSize = sceneRocks[0].texture.getSize();

    // Move rocks
    for (int i = 0; i < MaxRocks; ++i) {
        sf::Vector2f position = sceneRocks[i].sprite.getPosition();

        if (position.y < rockGameGroundheight + charheight) {
            // Move the rock down with a speed based on delta time
            sceneRocks[i].sprite.setPosition(position.x, position.y + ROCK_FALL_SPEED * dt);
        } else {
            float x = static_cast<float>(rand() % static_cast<int>(SCREEN_W - textureSize.x));
            float y = static_cast<float>(rand() % static_cast<int>(SCREEN_H - textureSize.y)) - SCREEN_H;
            float yOffset = static_cast<float>(rand() % 100);  // Adjust the range as needed
            sceneRocks[i].sprite.setPosition(x, y + yOffset);
        }
    }

    // Adjust rocks after moving
    adjustRocks(sceneRocks, ground, MaxRocks);
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

void spawnRate(float timeElapsed, int& MaxRocks) {
    if (timeElapsed <= 30) {
        MaxRocks = 4;
    } else if (timeElapsed <= 120) {
        MaxRocks = 8;
    }
}

void RockSceneRender(sf::RenderWindow& window) {
    return;
    // Handle player input
//    handleInput(player);
    std::cout << "Rock scene render!" << std::endl;

    // Update the game
    float dt = gameClock.restart().asSeconds();
    timeElapsed += dt;
    spawnRate(timeElapsed, MaxRocks);
    updateRocks(sceneRocks, dt, MaxRocks, ground);

    // Draw the game
    window.draw(ground.sprite);  // Draw ground first
    for (int i = 0; i < MaxRocks; ++i) {
        window.draw(sceneRocks[i].sprite);
    }
}

void onRockSceneShown() {
    initRocks(sceneRocks, MaxRocks);
}

Scene initRockScene() {
    Scene scene;

    scene.name = "Rock Scene";
    scene.type = SCENE_CUSTOM;
    scene.location = SCENE_ROCK_GAME;
    scene.backgroundSpritePath = BACKGROUND_ROCK_PATH;
    scene.horizontalMovementOnly = true;
    scene.defaultPlayerPos = sf::Vector2f(400, 500);
    scene.defaultPlayerDir = PLAYER_SPRITE_RIGHT;

    return scene;
 }

