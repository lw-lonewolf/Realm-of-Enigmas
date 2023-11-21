/* UI.cpp *
 * Manages the generation of UI widgets.
 *
 * */

sf::Sprite newButtonSquare(sf::Vector2f position) {
    sf::Sprite widget;

    widget.setTexture(uiSpriteTexture);
    widget.setTextureRect(UI_SPR_BTN_SQUARE);
    widget.setPosition(centerByDimensions(position, UI_SPR_BTN_SQUARE.getSize(), true));
    widget.setScale(1.5, 1.5);

    return widget;
}