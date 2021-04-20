sf::Text goldText;
sf::Sprite coin;
sf::Texture coinTexture;


void affichage_coin() {

    //Afficher le nombre de coins disponible
    std::string gold_string = std::to_string(joueur->get_argent());

    goldText.setString(gold_string);
    goldText.setFont(font);


    goldText.setCharacterSize(40);
    goldText.setFillColor(sf::Color::Yellow);
    goldText.setPosition(110.f, 45.f);
    goldText.setStyle(sf::Text::Bold);

    //Afficher le coin et sa texture

    if (!coinTexture.loadFromFile("ressources/img/coin.png"))// un IF pour verifier si le sprite du coin est bien charger
    {
        std::cout << "Erreur de chargement des Coins" << std::endl;
    }

    coinTexture.setSmooth(true);
    coin.setTexture(coinTexture);
    coin.setPosition(20.f, 35.f);
    coin.setScale(0.3f, 0.3f);



    window.draw(coin);
    window.draw(goldText);

}