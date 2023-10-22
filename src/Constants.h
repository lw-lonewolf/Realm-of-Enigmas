
/* Window & Graphics Options */

#define SCREEN_W 800
#define SCREEN_H 600
#define WINDOW_TITLE "Window Title"
#define REFRESH_RATE 60

/* Game values */

#define PI 3.141
#define PLAYER_MOVE_MULTIPLIER 1

/* Game controls */

const sf::Keyboard::Key KEY_UP = sf::Keyboard::W;
const sf::Keyboard::Key KEY_LEFT = sf::Keyboard::A;
const sf::Keyboard::Key KEY_DOWN = sf::Keyboard::S;
const sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::D;

/* Structures */

// struct BoxCollider {
//     const int objectId = rand();
//     sf::Sprite sprite;
// };

struct Scene {
    std::string backgroundSpritePath;
    sf::Texture background;
    sf::Sprite backgroundSprite;
    
    int defaultPlayerDir;
    sf::Vector2f defaultPlayerPos;
    
    int totalColliders;
    sf::IntRect colliderHitboxes[32];
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
