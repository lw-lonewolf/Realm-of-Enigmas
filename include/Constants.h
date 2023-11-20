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
#define DEBUG_MODE 0

/* Game values */

#define PI 3.141
#define PLAYER_MOVE_MULTIPLIER 2
#define INTERACTIBLE_THRESHOLD 40

enum MenuItem {
    MENU_PLAY,
    MENU_SETTINGS,
    MENU_QUIT
};

/* Game controls */

const sf::Keyboard::Key KEY_UP = sf::Keyboard::W;
const sf::Keyboard::Key KEY_LEFT = sf::Keyboard::A;
const sf::Keyboard::Key KEY_DOWN = sf::Keyboard::S;
const sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::D;

const sf::Keyboard::Key KEY_ACTION = sf::Keyboard::E;

const sf::Keyboard::Key KEY_NAV_UP = sf::Keyboard::Up;
const sf::Keyboard::Key KEY_NAV_LEFT = sf::Keyboard::Left;
const sf::Keyboard::Key KEY_NAV_DOWN = sf::Keyboard::Down;
const sf::Keyboard::Key KEY_NAV_RIGHT = sf::Keyboard::Right;

const sf::Keyboard::Key KEY_NAV_SELECT = sf::Keyboard::Enter;
const sf::Keyboard::Key KEY_NAV_BACK = sf::Keyboard::Escape;

/* Fonts & Sizes */
sf::Font UI_FONT_HEAD, UI_FONT_BODY;
const int UI_HEAD_1_SIZE = 65;
const int UI_HEAD_2_SIZE = 54;
const int UI_HEAD_3_SIZE = 45;
const int UI_BODY_1_SIZE = 30;
const int UI_BODY_2_SIZE = 22;
const int UI_BODY_3_SIZE = 14;

/* Structures & related enums */

/* SceneType defines the type of a Scene struct (in Scene::type).
 * SCENE_MENU is the MenuScene.cpp,
 * SCENE_GAME will be any scene using the engine's player, view, and physics
 * management.
 * SCENE_CUSTOM will be used for any custom handling.
 * */

enum SceneType {
    SCENE_MENU,
    SCENE_GAME,
    SCENE_CUSTOM
};

/* InputAction for the keyboard navigation. Used by the menu handling.
 * */

enum InputAction {
    INPUT_NAVIGATE,
    INPUT_SELECT,
    INPUT_BACK
};


/* The Interaction enum will list all the interactions of the game. When these
 * interactions are to be made, the code in handleInteraction() will use a
 * switch statement to compare and run the desired function for the
 * intractable.
 */

enum Interaction {
    INTERACTION_NULL,
    INTERACTION_TRAVEL,
    INTERACTION_TALK
};


/* TravelLocation will basically contain identifiers for all the locations the
 * player can travel to. (A little messy because this is a workaround to the
 * no-OOP restriction we have). Open to improvements.
 *
 * */

enum TravelLocation {
    TRAVEL_TEST_SCENE,
    TRAVEL_DEMO_SCENE
};


/* Finally the InteractionPoint struct itself. This struct defines any point of
 * interaction in a scene.
 * */

struct InteractionPoint {
    Interaction name = INTERACTION_NULL;
    std::string label = "Interact";
    TravelLocation travelTo;
    sf::Vector2f position;
};

/* The Scene struct: This struct defines every property of a Scene, from its
 * background to the camera settings, from the player properties to the hitboxes
 * and interactibles. Everything of any Scene is stored in a Scene object.
 * */

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
    InteractionPoint interactibles[32];
};

/* This struct is just for the player. Contains all related stuff about the
 * player.
 * */

struct {
    sf::Sprite sprite;
    sf::Vector2f movementVector;
    sf::Texture texture;
    sf::Vector2f prevPosition;
    InteractionPoint interactionInRange;

    bool moving;
    int direction;
    int currentAnimFrame;
} player;

