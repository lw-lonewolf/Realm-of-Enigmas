/* Helper.cpp *
 * Contains simple functions to make certain calculations easier
 *
 * */

/* The centerByDimensions function converts a position to represent the center
 * of the object. By default, SFML's position always represents the top left edge
 * of the objects. This function takes in the dimensions and returns a properly
 * adjusted position vector that points to the center of the object instead of
 * the top left edge.
 *
 * */
sf::Vector2f centerByDimensions(sf::Vector2f orgVector, sf::Vector2i dimensions, bool invertAlignment = false)
{
    /* The invertAlignment inverts the target location to be opposite to the
     * object instead of pushing within it
     *
     */
    int invertFactor = invertAlignment ? -1 : 1;
    return sf::Vector2f(orgVector.x + (invertFactor * dimensions.x / 2), orgVector.y + (invertFactor * dimensions.y / 2));
}

sf::Text dropShadow(sf::Text tx) {
    sf::Text txShadow = tx;
    txShadow.setFillColor(sf::Color::Black);
    txShadow.setPosition(txShadow.getPosition().x + 2, txShadow.getPosition().y + 2);

    return txShadow;
}

void textWrapper(sf::Text &text, int width, int continueIndex = 0)
{
    std::string textStr = text.getString();
    for (int i = continueIndex; i < textStr.length(); i++)
    {
        sf::Vector2<float> characterPos = text.findCharacterPos(i);
        if (characterPos.x >= (text.getPosition().x + width))
        {

            char extraChar = textStr[textStr.length() - 1];
            for (int j = textStr.length(); j > i; j--)
            {
                textStr[j] = textStr[j - 1];
            }
            textStr[i] = '\n';

            text.setString(textStr + extraChar);
            textWrapper(text, width, i + 1);
            break;
        }
    }
}