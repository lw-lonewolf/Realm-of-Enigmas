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
sf::Vector2f centerByDimensions(sf::Vector2f orgVector, sf::Vector2i dimensions, bool invertAlignment = false) {
    /* The invertAlignment inverts the target location to be opposite to the
     * object instead of pushing within it
     *
     */
    int invertFactor = invertAlignment ? -1 : 1;
    return sf::Vector2f(orgVector.x + (invertFactor * dimensions.x / 2), orgVector.y + (invertFactor * dimensions.y / 2));
}