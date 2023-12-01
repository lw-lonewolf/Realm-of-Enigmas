/* Global.h *
 * Function prototypes for the methods in other files like Render.cpp, Physics
 * .cpp etc.
 *
 * */

void onOverrideEvent(sf::Event event);
void onOverrideRender(sf::RenderWindow& window);

void loadScene(Scene scene);
void clearScene();
bool PhysicsValidatePosition(sf::Vector2f testPosition);
void renderInteraction(sf::RenderWindow& window, InteractionPoint interaction);
void setView();

sf::View uiView;
sf::Clock gameClock;
int framecount = 0;
bool isGamePaused = false;
std::string uiStatus = "";
sf::Texture uiSpriteTexture;

bool isDialogOpen = false;
bool isPopupOpen = false;
Dialog currentDialog;
std::string currentDialogText = "";
std::string currentPopupTitle = "";
std::string currentPopupBodyText = "";
Scene sceneToLoad;
int loadingScene = 0;
int currentDialogIndex = 0;
NPC currentDialogNPC;
void pauseGame();
void resumeGame();

Scene initMenuScene();

sf::Vector2f centerByDimensions(sf::Vector2f orgVector, sf::Vector2i dimensions, bool invertAlignment = false);
sf::Text dropShadow(sf::Text tx);

sf::Sprite newButton(sf::Vector2f position, bool dontCenterByDimensions);
sf::Sprite newButtonSquare(sf::Vector2f position, bool dontCenterByDimensions);
void createPopup(std::string titleText, std::string bodyText);

float menuBgPosition = 0;
MenuItem menuCurrentSelection = MENU_PLAY;
const int menuItemsLength = 3;
std::string menuItemNames[menuItemsLength] = {
    "Play",
    "Credits",
    "Quit",
};

const int gameMenuItemsLength = 2;
GameMenuItem gameMenuCurrentSelection = GAME_MENU_PLAY;
std::string gameMenuItemNames[gameMenuItemsLength] = {
    "Resume",
    "Main Menu",
};