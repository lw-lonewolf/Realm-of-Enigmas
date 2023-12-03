static sf::Sound sound;

void load_music(const std::string &PATH)
{
    sf::SoundBuffer buffer;

    if (!buffer.loadFromFile(PATH))
    {
        std::cout << "ERROR: Could not load music file from " << PATH << std::endl;
        return;
    }

    sound.setBuffer(buffer);
    sound.setLoop(true); 
}

void stop_music()
{
    sound.stop();
}