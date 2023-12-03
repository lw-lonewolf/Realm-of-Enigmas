/* ../../Assets.h *
 * Sprites, fonts, sounds and all about the ../../assets and resources. All the asset
 * related constant values stuff of the entire project are in this file.
 *
 * */

/* Player constants */

#define PLAYER_SPRITE_PATH "assets/sprites/player-sprite.png"
#define PLAYER_SPRITE_WIDTH 64
#define PLAYER_SPRITE_HEIGHT 64

#define PLAYER_ANIM_FRAMES 8

#define PLAYER_ANIM_SPEED 100

enum PLAYER_SPRITE_DIR
{
    PLAYER_SPRITE_UP,
    PLAYER_SPRITE_LEFT,
    PLAYER_SPRITE_DOWN,
    PLAYER_SPRITE_RIGHT
};

/* Guide character constants */

sf::Texture guideCharTexture;
NPC guideChar;
void initGuideCharSprite()
{
    guideChar.path = "assets/sprites/character_guide.png";
    guideChar.name = "Guide";
    guideChar.width = 32;
    guideChar.height = 32;

    guideChar.animFrames = 4;
    guideChar.animSpeed = 500;

    if (!guideChar.texture.loadFromFile(guideChar.path))
        std::cout << "Failed to load from file: " << guideChar.path << std::endl;
}


/* Rock game character constants */

NPC rockChar;
void initRockCharSprite()
{
    rockChar.path = "assets/sprites/character_rock.png";
    rockChar.name = "Rock Guy";
    rockChar.width = 30;
    rockChar.height = 39;

    rockChar.animFrames = 6;
    rockChar.animSpeed = 83; // 12 FPS

    if (!rockChar.texture.loadFromFile(rockChar.path))
        std::cout << "Failed to load from file: " << rockChar.path << std::endl;
}



/* Background constants */

#define BACKGROUND_MENU_PATH "assets/imgs/ParallexBG.png"
#define BACKGROUND_DEMO_PATH "assets/imgs/demo-bg-sprite.jpg"
#define BACKGROUND_OPTIMUS_PRIME_PATH "assets/imgs/main-bg.png"
#define BACKGROUND_TEST_PATH "assets/imgs/BackgroundV4.png"
#define BACKGROUND_ROCK_PATH "assets/imgs/BackgroundV4.png"

sf::Texture menuBgTexture;


/* Keys */

#define KEYS_SPRITE_PATH "assets/sprites/Keys.png"
const sf::IntRect KEY_SPRITE_ROCK(sf::Vector2i(0, 0), sf::Vector2i(32, 32));
const sf::IntRect KEY_SPRITE_SNAKE(sf::Vector2i(96, 0), sf::Vector2i(32, 32));
const sf::IntRect KEY_SPRITE_CIPHER(sf::Vector2i(32, 0), sf::Vector2i(32, 32));


/* Fonts */

#define UI_FONT_HEAD_LOCATION "assets/fonts/8-bit Arcade In.ttf"
#define UI_FONT_BODY_LOCATION "assets/fonts/Retro Gaming.ttf"

/* UI Sprite */
#define UI_SPRITE_PATH "assets/sprites/GUI.png"

// SPECIFIC PORTIONS OF THE TEXTURE TO RENDER
const sf::IntRect UI_SPR_BTN_SQUARE(sf::Vector2i(1, 81), sf::Vector2i(14, 14));
const sf::IntRect UI_SPR_BTN_SQUARE_PRESSED(sf::Vector2i(17, 81), sf::Vector2i(14, 14));

const sf::IntRect UI_SPR_BTN(sf::Vector2i(113, 81), sf::Vector2i(30, 14));
const sf::IntRect UI_SPR_BTN_PRESSED(sf::Vector2i(113, 97), sf::Vector2i(30, 14));

const sf::IntRect UI_SPR_DIALOG_BG(sf::Vector2i(0, 96), sf::Vector2i(47, 32));
