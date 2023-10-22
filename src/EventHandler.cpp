#include <SFML/Graphics.hpp>

void onMovement(sf::Vector2f dir) {
    player.movementVector = dir;
    player.moving = true;
}

void EventHandler(sf::Event event) {
    switch (event.type) {
    case sf::Event::KeyPressed:
        // std::cout << "key: " << event.key.code << std::endl;

        if (event.key.code == KEY_UP)
            onMovement(sf::Vector2f(player.movementVector.x, -1.f * PLAYER_MOVE_MULTIPLIER));
            
        else if (event.key.code == KEY_DOWN)
            onMovement(sf::Vector2f(player.movementVector.x, 1.f * PLAYER_MOVE_MULTIPLIER));
            
        else if (event.key.code == KEY_LEFT)
            onMovement(sf::Vector2f(-1.f * PLAYER_MOVE_MULTIPLIER, player.movementVector.y));
            
        else if (event.key.code == KEY_RIGHT)
            onMovement(sf::Vector2f(1.f * PLAYER_MOVE_MULTIPLIER, player.movementVector.y));
        
        break;

    case sf::Event::KeyReleased:
        
        if (event.key.code == KEY_UP || event.key.code == KEY_DOWN)
            onMovement(sf::Vector2f(player.movementVector.x, 0));
            
        else if (event.key.code == KEY_LEFT || event.key.code == KEY_RIGHT)
            onMovement(sf::Vector2f(0, player.movementVector.y));
            
        break;

    case sf::Event::MouseMoved:
        std::cout << "mouse: x:" << event.mouseMove.x << " y:" << event.mouseMove.y << std::endl;
    
    default:
        break;
    }
}