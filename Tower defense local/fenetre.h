void Window() {
    window.create(sf::VideoMode(LARGEUR, HAUTEUR), "FC-Fiak | Tower defense");


    // Gestion de l'icone
    sf::Image icon;
    if (!icon.loadFromFile("ressources/img/icone.png"))
    {
        std::cout << "Erreur du chargement de icone.png" << std::endl;
    }
    window.setIcon(93, 98, icon.getPixelsPtr());


    // Gestion de la map
    sf::Texture map;
    sf::Sprite sprite_map;
    if (!map.loadFromFile("ressources/img/map.png"))
    {
        std::cout << "Erreur de chargement de la map" << std::endl;
    }
    sprite_map.setTexture(map);
    
    map.setSmooth(true);


    window.setPosition(sf::Vector2i(300, 70));    //150
    window.setFramerateLimit(60);




    int speed_animation = 0;

  

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        pause();

        window.draw(sprite_map);

        
        detection();
        attaque();

        affichage_vie_chateau();
        affichage_chateau();

        creation_tour();
        affichage_tours();  

        // ENNEMIS
        spawn_zombie();
        affichage_zombies();
        deplacement_zombie();

        spawn_tank();
        affichage_tanks();
        deplacement_tank();

        spawn_runner();
        affichage_runners();
        deplacement_runner();

        spawn_mage();
        affichage_mages();
        deplacement_mage();

        affichage_coin();

        window.display();
        window.clear();
    }
}
