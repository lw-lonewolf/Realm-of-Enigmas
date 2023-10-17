#define PI 3.141

#define SCREEN_W 800
#define SCREEN_H 600
#define WINDOW_TITLE "Window Title"
#define REFRESH_RATE 60

#define PLAYER_SPRITE_PATH "res/player-sprite.png"
#define PLAYER_SPRITE_SIZE 64

struct BoxCollider {
    sf::Sprite sprite;
};


enum PLAYER_SPRITE_DIR {
    PLAYER_SPRITE_UP,
    PLAYER_SPRITE_LEFT,
    PLAYER_SPRITE_DOWN,
    PLAYER_SPRITE_RIGHT
};

enum KEYBOARD_CONTROLS {
    KEY_UP = sf::Keyboard::W,
    KEY_LEFT = sf::Keyboard::A,
    KEY_DOWN = sf::Keyboard::S,
    KEY_RIGHT = sf::Keyboard::D
};