/* Constants.h *
 * Includes all the constant values stuff of the entire project, excluding all
 * asset related constants, which are in Assets.h.
 *
 * */

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

const sf::Keyboard::Key KEY_NAV_UP = sf::Keyboard::Up;
const sf::Keyboard::Key KEY_NAV_LEFT = sf::Keyboard::Left;
const sf::Keyboard::Key KEY_NAV_DOWN = sf::Keyboard::Down;
const sf::Keyboard::Key KEY_NAV_RIGHT = sf::Keyboard::Right;

const sf::Keyboard::Key KEY_NAV_SELECT = sf::Keyboard::Enter;
const sf::Keyboard::Key KEY_NAV_BACK = sf::Keyboard::Escape;

/* Fonts */
sf::Font UI_FONT_HEAD, UI_FONT_BODY;
const int UI_HEAD_1_SIZE = 65;
const int UI_HEAD_2_SIZE = 54;
const int UI_HEAD_3_SIZE = 45;
const int UI_BODY_1_SIZE = 30;
const int UI_BODY_2_SIZE = 26;
const int UI_BODY_3_SIZE = 22;

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

enum SceneType {
    SCENE_MENU,
    SCENE_GAME,
    SCENE_CUSTOM
};

enum InputAction {
    INPUT_NAVIGATE,
    INPUT_SELECT,
    INPUT_BACK
};

struct Scene {
    SceneType type;
    std::string name;
    std::string backgroundSpritePath;
    sf::Texture background;
    sf::Sprite backgroundSprite;
    sf::View view;

    bool playerEnabled = true;
    int defaultPlayerDir;
    sf::Vector2f defaultPlayerPos;

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
