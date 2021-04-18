#pragma region variables

sf::Texture zombie;
sf::Sprite sprite_zombie;

enum Dir { Down, Left, Right, Up };
sf::Vector2i anim(1, Down);

std::vector<sf::Sprite> sprites_zombies;
std::vector<Zombie*> zombies;

int sizeZombie = 32;

int maxZombie = 10;

#pragma endregion variables

void afficher_zombie() {

    // (Rapidité de l'animation)
    window.setFramerateLimit(10);


    // Texture Zombie
    if (!zombie.loadFromFile("ressources/img/zombie.png"))
    {
        std::cout << "Erreur du chargement de zombie.png" << std::endl;
    }


    // Pour rendre la texture de meilleur qualité
    zombie.setSmooth(true);


    sprite_zombie.setTexture(zombie);

    anim.x++;
    if (anim.x * sizeZombie >= zombie.getSize().x)
        anim.x = 0;




    sprite_zombie.setTextureRect(sf::IntRect(anim.x * sizeZombie, anim.y * sizeZombie, sizeZombie, sizeZombie));


    window.draw(sprite_zombie);



}

void spawn_zombie() {

    for (int i = 0; i < 5; i++) {

        sf::Vector2i position_souris = sf::Mouse::getPosition(window);

        sf::Sprite sprite_zombie;
        sprite_zombie.setTexture(zombie);
        sprite_zombie.setPosition(position_souris.x, position_souris.y);
        sprites_zombies.push_back(sprite_zombie);

        Zombie* monzombie = new Zombie(position_souris.x, position_souris.y);
        zombies.push_back(monzombie);



        window.draw(sprite_zombie);

    }


}
