/* Physics.cpp *
 * Self explanatory, this file will contain all physics related logic of the
 * game.
 *
 * */

Scene currentScene;

bool PhysicsValidatePosition(sf::Vector2f testPosition) {
    for (int i = 0; !(currentScene.colliderHitboxes[i].width - currentScene.colliderHitboxes[i].height == currentScene.colliderHitboxes[i].width); i++) {
        sf::IntRect hitbox = currentScene.colliderHitboxes[i];

        if ((hitbox.left + hitbox.top + hitbox.width + hitbox.height)) {
            sf::IntRect playerHitbox(testPosition.x + (PLAYER_SPRITE_WIDTH/4), testPosition.y + (PLAYER_SPRITE_HEIGHT/2), PLAYER_SPRITE_WIDTH/2, PLAYER_SPRITE_HEIGHT/2);
            if (hitbox.intersects(playerHitbox))
                return false;
        }
    }

    sf::Vector2u backgroundBounds = currentScene.background.getSize();

    if (((backgroundBounds.x - PLAYER_SPRITE_WIDTH) <= testPosition.x || (backgroundBounds.y - PLAYER_SPRITE_HEIGHT) <= testPosition.y) || (-PLAYER_SPRITE_WIDTH/3 >= testPosition.x || -PLAYER_SPRITE_HEIGHT/3 >= testPosition.y))
        return false;

    return true;
}


void PhysicsLoop() {
    sf::Vector2f playerPos = player.sprite.getPosition();

    if (!PhysicsValidatePosition(playerPos))
        player.sprite.setPosition(player.prevPosition.x, player.prevPosition.y);
}

