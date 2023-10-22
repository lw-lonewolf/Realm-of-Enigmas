void PhysicsLoop() {
    sf::Vector2f playerPos = player.sprite.getPosition();

    for (int i = 0; i < sizeof(currentScene.colliderHitboxes); i++) {
        sf::IntRect hitbox = currentScene.colliderHitboxes[i];

        if ((hitbox.left + hitbox.top + hitbox.width + hitbox.height)) {
            // std::cout << hitbox.left << " " << hitbox.top << std::endl;

            

            sf::IntRect playerHitbox(playerPos.x + (PLAYER_SPRITE_SIZE/4), playerPos.y + (PLAYER_SPRITE_SIZE/2), PLAYER_SPRITE_SIZE/2, PLAYER_SPRITE_SIZE/2);

            if (hitbox.intersects(playerHitbox))
                    player.sprite.setPosition(player.prevPosition.x, player.prevPosition.y);
                // player.sprite.setPosition(hitbox.left - 1, playerPos.y);


        }
    }
}

