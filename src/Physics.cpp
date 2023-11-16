void PhysicsLoop() {
    sf::Vector2f playerPos = player.sprite.getPosition();

    for (int i = 0; i < 6; i++) {
        sf::IntRect hitbox = currentScene.colliderHitboxes[i];

        if ((hitbox.left + hitbox.top + hitbox.width + hitbox.height)) {
            sf::IntRect playerHitbox(playerPos.x + (PLAYER_SPRITE_WIDTH/4), playerPos.y + (PLAYER_SPRITE_HEIGHT/2), PLAYER_SPRITE_WIDTH/2, PLAYER_SPRITE_HEIGHT/2);
            if (hitbox.intersects(playerHitbox))
                    player.sprite.setPosition(player.prevPosition.x, player.prevPosition.y);
        }
    }

    sf::Vector2u backgroundBounds = currentScene.background.getSize();
    
    if (((backgroundBounds.x - PLAYER_SPRITE_WIDTH) <= playerPos.x || (backgroundBounds.y - PLAYER_SPRITE_HEIGHT) <= playerPos.y) || (-PLAYER_SPRITE_WIDTH/3 >= playerPos.x || -PLAYER_SPRITE_HEIGHT/3 >= playerPos.y))
        player.sprite.setPosition(player.prevPosition.x, player.prevPosition.y);

}

