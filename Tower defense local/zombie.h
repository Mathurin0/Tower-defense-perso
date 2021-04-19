#pragma region variables

sf::Texture Zombie_t;
sf::Sprite sprite_zombie;

enum Dir { Down, Left, Right, Up };
sf::Vector2i anim(1, Right);

std::vector<sf::Sprite> sprites_zombies;
std::vector<Zombie*> zombies;

int sizeZombie = 32;

int maxZombie = 10;
int zonzon = 0;

bool finit = false;
int temps_spawn = 0;

int vitesse_animation = 0;



#pragma endregion variables


void spawn_zombie() {


    // Texture Zombie
    if (!Zombie_t.loadFromFile("ressources/img/zombie.png"))
    {
        std::cout << "Erreur du chargement de zombie.png" << std::endl;
    }


    if (zonzon < maxZombie && finit == false) {

        temps_spawn++;
        if (temps_spawn == 20) 
        {
            temps_spawn = 0;

            Zombie_t.setSmooth(true);
            sf::Sprite sprite_zombie;
            sprite_zombie.setTexture(Zombie_t);
            sprite_zombie.setPosition(-10, 360);
            sprites_zombies.push_back(sprite_zombie);

            Zombie* monzombie = new Zombie(-10, 360);
            zombies.push_back(monzombie);

            std::cout << "Zombie n " << zonzon << " vient de spawn" << std::endl;

            zonzon++;


        }

    }

}

void affichage_zombies() {

    int taille = zombies.size();

    for (int i = 0; i < taille; i++) {

        // Gestion de l'animation
        vitesse_animation++;
        if (vitesse_animation == 15) 
        {
            vitesse_animation = 0;

            anim.x++;
            if (anim.x * sizeZombie >= Zombie_t.getSize().x)
            {
                anim.x = 0;
            }
        }

        sprites_zombies[i].setTextureRect(sf::IntRect(anim.x * sizeZombie, anim.y * sizeZombie, sizeZombie, sizeZombie));
        sprites_zombies[i].setScale(1.5, 1.5);

        // Affichage du zombie
        window.draw(sprites_zombies[i]);

        }

}


void deplacement_zombie() {

    int taille = zombies.size();

    for (int i = 0; i < taille; i++) {

        sprites_zombies[i].move(3, 0);
        

        if (sprites_zombies[i].getPosition().x >= 1480)
        {

            std::cout << "Le zombie " << i << " vient de toucher le chateau" << std::endl;
            sprites_zombies[i].setColor(sf::Color::Transparent);

        }


    }

}
