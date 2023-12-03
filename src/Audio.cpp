
sf::Music music;
void initMusic(std::string PATH)
{
    if (!music.openFromFile(PATH))
    {
        std::cout << "FILE NOT LOADED";
    }
}