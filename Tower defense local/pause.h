


void pause() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.setTitle("FC-Fiak | PAUSE");

        sf::Text pauseText;
        pauseText.setString("Pause");
        pauseText.setCharacterSize(30);

        sf::Font font;
        if (!font.loadFromFile("ressources/Hiatus.ttf"))
        {
            std::cout << "Erreur du chargement de la police" << std::endl;
        }
        pauseText.setFont(font);

        pauseText.setPosition({window.getSize().x / 2 - pauseText.getLocalBounds().width / 2, window.getSize().y / 2 - pauseText.getLocalBounds().height});
      
    }
}