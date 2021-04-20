#pragma region variables

sf::Texture Chateau_t;
sf::Sprite sprite_chateau;

Chateau* Base = new Chateau(10);

int ChateauHP = Base->Get_HP();

#pragma endregion variables






void affichage_chateau() {

    // Texture Chateau
    if (!Chateau_t.loadFromFile("ressources/img/chateau.png"))
    {
        std::cout << "Erreur du chargement de chateau.png" << std::endl;
    }



    if (Base->Get_HP() <= ChateauHP / 1.3)
    {
        if (!Chateau_t.loadFromFile("ressources/img/chateau_break_1.png"))
        {
            std::cout << "Erreur du chargement de chateau_break_1.png" << std::endl;
        }
    }
    
    if (Base->Get_HP() <= ChateauHP / 2)
    {
        if (!Chateau_t.loadFromFile("ressources/img/chateau_break_2.png"))
        {
            std::cout << "Erreur du chargement de chateau_break_2.png" << std::endl;
        }
    }

    if (Base->Get_HP() <= ChateauHP / 4)
    {
        if (!Chateau_t.loadFromFile("ressources/img/chateau_break_3.png"))
        {
            std::cout << "Erreur du chargement de chateau_break_3.png" << std::endl;
        }
    }



    Chateau_t.setSmooth(true);
    sf::Sprite sprite_chateau;
    sprite_chateau.setTexture(Chateau_t);
    sprite_chateau.setPosition(1390, 235);

    window.draw(sprite_chateau);
}

void affichage_vie_chateau() {

    

    // Conversion int -> string
    std::string hp_chateau_string = std::to_string(Base->Get_HP());

    sf::Text vie_chateau;
    vie_chateau.setString(hp_chateau_string);
    vie_chateau.setCharacterSize(30);

    sf::Font font;
    if (!font.loadFromFile("ressources/Hiatus.ttf"))
    {
        std::cout << "Erreur du chargement de la police" << std::endl;
    }
    vie_chateau.setFont(font);

    vie_chateau.setPosition(1485, 420);


    window.draw(vie_chateau);

}