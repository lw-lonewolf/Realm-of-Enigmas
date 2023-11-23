/* Preload.cpp
 * This file preloads assets: all the fonts and sprites are loaded here before
 * the game starts.
 * */

void loadAssets() {

    UI_FONT_HEAD.loadFromFile(UI_FONT_HEAD_LOCATION);
    UI_FONT_BODY.loadFromFile(UI_FONT_BODY_LOCATION);

    if (!uiSpriteTexture.loadFromFile(UI_SPRITE_PATH))
        std::cout << "Failed to load from file: " << UI_SPRITE_PATH << std::endl;

    initGuideCharSprite();
    if (!guideCharTexture.loadFromFile(guideChar.path))
        std::cout << "Failed to load from file: " << guideChar.path << std::endl;

}