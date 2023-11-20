/* Global.h *
 * Function prototypes for the methods in other files like Render.cpp, Physics
 * .cpp etc.
 *
 * */

void onOverrideEvent(sf::Event event);
void onOverrideRender(sf::RenderWindow& window);

void loadScene(Scene scene);
bool PhysicsValidatePosition(sf::Vector2f testPosition);
void renderInteraction(sf::RenderWindow& window, InteractionPoint interaction);
void setView();

sf::View uiView;
int framecount = 0;
std::string uiStatus = "";