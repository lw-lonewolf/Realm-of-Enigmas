/* EventHandler.cpp
 * This file controls all the Event handling of the program. Any SFML Event
 * handling is fundamentally broken down in this file.
 * */


/* The menuEventHandler function is called from the Override.cpp (visit
 * Override.cpp for explanation) when the MenuScene wants to receive event
 * handling calls. The onMenuNavigation is situated in MenuScene.cpp.
 *
 * */
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

/* This small function is responsible for converting the keyboard direction
 * (from the EventHandler below) into a usable player movementVector.
 *
 * */
void onMovement(sf::Vector2f dir) {
    // Don't carry out movement when the game is paused
    if (isGamePaused) return;

    player.movementVector = dir;
    player.moving = true;
}


/* This function controls the global back function which occurs when the user
 * presses the Esc key.
 * */
void onEscape() {
    isGamePaused = !isGamePaused;
    isDialogOpen = false;
}

/* Finally, the EventHandler is the heart of all the event handling in the
 * entire game. All events are passed to this, and this function forks down the
 * call to the relevant handler (movement handler, interaction handler, menu
 * handler, etc.)
 *
 * */
void EventHandler(sf::Event event) {
    switch (event.type) {
    case sf::Event::KeyPressed:
        // std::cout << "key: " << event.key.code << std::endl;

        switch (event.key.code) {
            case KEY_UP:
                onMovement(sf::Vector2f(player.movementVector.x, -1.f * PLAYER_MOVE_MULTIPLIER));
                break;

            case KEY_DOWN:
                onMovement(sf::Vector2f(player.movementVector.x, 1.f * PLAYER_MOVE_MULTIPLIER));
                break;

            case KEY_LEFT:
                onMovement(sf::Vector2f(-1.f * PLAYER_MOVE_MULTIPLIER, player.movementVector.y));
                break;

            case KEY_RIGHT:
                onMovement(sf::Vector2f(1.f * PLAYER_MOVE_MULTIPLIER, player.movementVector.y));
                break;

            case KEY_ACTION:
                handleInteraction(player.interactionInRange);
                break;

            case KEY_NEXT:
                nextDialog();
                break;

            case KEY_NAV_BACK:
                onEscape();
                break;

        }

        break;

    case sf::Event::KeyReleased:
        
        if (event.key.code == KEY_UP || event.key.code == KEY_DOWN)
            onMovement(sf::Vector2f(player.movementVector.x, 0));
            
        else if (event.key.code == KEY_LEFT || event.key.code == KEY_RIGHT)
            onMovement(sf::Vector2f(0, player.movementVector.y));
            
        break;

//    case sf::Event::MouseMoved:
//        std::cout << "mouse: x:" << event.mouseMove.x << " y:" << event.mouseMove.y << std::endl;

    default:
        break;
    }

    /* This is overriding call which extends the EventHandler to any of the
     * scenes that may also require it.
     * */
    onOverrideEvent(event);
}