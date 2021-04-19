#pragma region variables

sf::Texture Chateau_t;
sf::Sprite sprite_chateau;

#pragma endregion variables



void affichage_chateau() {

    // Texture Chateau
    if (!Chateau_t.loadFromFile("ressources/img/chateau.png"))
    {
        std::cout << "Erreur du chargement de chateau.png" << std::endl;
    }

    Chateau_t.setSmooth(true);
    sf::Sprite sprite_chateau;
    sprite_chateau.setTexture(Chateau_t);
    sprite_chateau.setPosition(1400, 235);

    window.draw(sprite_chateau);

}