
/* Window & Graphics Options */

#define SCREEN_W 800
#define SCREEN_H 600
#define WINDOW_TITLE "Course Project"
#define REFRESH_RATE 60

/* Game values */

#define PI 3.141
#define PLAYER_MOVE_MULTIPLIER 2

/* Game controls */

const sf::Keyboard::Key KEY_UP = sf::Keyboard::W;
const sf::Keyboard::Key KEY_LEFT = sf::Keyboard::A;
const sf::Keyboard::Key KEY_DOWN = sf::Keyboard::S;
const sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::D;

/* Structures (& Struct constructors) */

struct BoxCollider {
    int left, top, width, height = 0;
};

BoxCollider newBoxCollider(int left = 0, int top = 0, int width = 0, int height = 0) {
    BoxCollider hitbox;
    hitbox.left = left;
    hitbox.top = top;
    hitbox.width = width;
    hitbox.height = height;

    return hitbox;
}

struct Scene {
    std::string name;
    std::string backgroundSpritePath;
    sf::Texture background;
    sf::Sprite backgroundSprite;
    sf::View view;
    
    int defaultPlayerDir;
    sf::Vector2f defaultPlayerPos;
    
    int totalColliders;
    sf::IntRect colliderHitboxes[];
};

struct {
    sf::Sprite sprite;
    sf::Vector2f movementVector;
    sf::Texture texture;
    sf::Vector2f prevPosition;
    bool moving;
    int direction;
    int currentAnimFrame;
} player;
