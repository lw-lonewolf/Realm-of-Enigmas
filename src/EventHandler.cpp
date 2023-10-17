void EventHandler(sf::Event event) {
    switch (event.type) {
    case sf::Event::KeyPressed:
        std::cout << "key: " << event.key.code << std::endl;
        break;
    
    default:
        break;
    }
}