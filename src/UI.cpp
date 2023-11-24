/* UI.cpp *
 * Manages the generation of UI widgets.
 *
 * */
#include <SFML/Graphics.hpp>

sf::Sprite newButtonSquare(sf::Vector2f position)
{
    sf::Sprite widget;

    widget.setTexture(uiSpriteTexture);
    widget.setTextureRect(UI_SPR_BTN_SQUARE);
    sf::Vector2i size(UI_SPR_BTN_SQUARE.width, UI_SPR_BTN_SQUARE.height);
    widget.setPosition(centerByDimensions(position, size, true));
    widget.setScale(1.5, 1.5);

    return widget;
}

sf::Sprite newButton(sf::Vector2f position)
{
    sf::Sprite widget;

    widget.setTexture(uiSpriteTexture);
    widget.setTextureRect(UI_SPR_BTN);
    sf::Vector2i size(UI_SPR_BTN.width, UI_SPR_BTN.height);
    widget.setPosition(centerByDimensions(position, size, true));
    widget.setScale(1.5, 1.5);

    return widget;
}
