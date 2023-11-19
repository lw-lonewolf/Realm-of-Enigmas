/* EventHandler.cpp
 * This file controls all the Event handling of the program. Any SFML Event
 * handling is fundamentally broken down in this file.
 * */

void onOverrideEvent(sf::Event event);

void menuEventHandler(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == KEY_NAV_UP)
                onMenuNavigation(INPUT_NAVIGATE, -1);

            else if (event.key.code == KEY_NAV_DOWN)
                onMenuNavigation(INPUT_NAVIGATE, 1);

            else if (event.key.code == KEY_NAV_SELECT)
                onMenuNavigation(INPUT_SELECT, -1);

            else if (event.key.code == KEY_NAV_BACK)
                onMenuNavigation(INPUT_BACK, -1);

            break;
    }
}

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
//
//    case sf::Event::MouseMoved:
//        std::cout << "mouse: x:" << event.mouseMove.x << " y:" << event.mouseMove.y << std::endl;
//
    default:
        break;
    }

    onOverrideEvent(event);
}