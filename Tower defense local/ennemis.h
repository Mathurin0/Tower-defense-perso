#pragma region variables
//textures et sprites
sf::Texture Zombie_t;
sf::Sprite sprite_zombie;

sf::Texture Tank_t;
sf::Sprite sprite_tank;

sf::Texture Runner_t;
sf::Sprite sprite_runner;

sf::Texture Mage_t;
sf::Sprite sprite_mage;

//tableaux des ennemis et de leurs sprites pour les déplacer par la suite
std::vector<sf::Sprite> sprites_zombies;
std::vector<Zombie*> zombies;

std::vector<sf::Sprite> sprites_tanks;
std::vector<Tank*> tanks;

std::vector<sf::Sprite> sprites_runners;
std::vector<Runner*> runners;

std::vector<sf::Sprite> sprites_mages;
std::vector<Mage*> mages;

//pour gerer le mouvement des ennemis
enum Dir { Down, Left, Right, Up };
sf::Vector2i anim(1, Right);

// VALEURS D'ORIGINE
int origineZombie = 7;
int origineTank = 5;
int origineRunner = 3;
int origineMage = 10;


int sizeEnnemis = 32;

int maxZombie = origineZombie;
int zonzon = 0;

int maxTank = origineTank;
int tantan = 0;

int maxRunner = origineRunner;
int runrun = 0;

int maxMage = origineMage;
int magmag = 0;

bool finit = false;
int temps_spawnZ = 0;
int temps_spawnR = 0;
int temps_spawnT = 0;
int temps_spawnM = 0;


int zombiesEnVie = maxZombie;
int tanksEnVie = maxTank;
int runnersEnVie = maxRunner;
int magesEnVie = maxMage;

int zombiesKills = zombiesEnVie - maxZombie;
int tanksKills = tanksEnVie - maxTank;
int runnerKills = runnersEnVie - maxRunner;
int magesKills = magesEnVie - maxMage;

int vitesse_animation = 0;

int numero_vague = 1;

#pragma endregion variables





// ----------------------- ZOMBIES ----------------------- //


void spawn_zombie() {

    // Texture Zombie
    if (!Zombie_t.loadFromFile("ressources/img/zombie.png"))
    {
        std::cout << "Erreur du chargement de zombie.png" << std::endl;
    }

    if (zonzon < maxZombie && finit == false) {

        temps_spawnZ++;
        if (temps_spawnZ == 20) 
        {
            temps_spawnZ = 0;
            
            // On créé les zombies
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
            if (anim.x * sizeEnnemis >= Zombie_t.getSize().x)
            {
                anim.x = 0;
            }
        }
        //Ce bout de code permet de recarder les sprites des zombies
        sprites_zombies[i].setTextureRect(sf::IntRect(anim.x * sizeEnnemis, anim.y * sizeEnnemis, sizeEnnemis, sizeEnnemis));
        sprites_zombies[i].setScale(1.5, 1.5);

        // Affichage des zombies
        window.draw(sprites_zombies[i]);

        }

}


void deplacement_zombie() {

    int taille = zombies.size();

    for (int i = 0; i < taille; i++) {

        sprites_zombies[i].move(zombies[i]->get_vitesse(), 0);
        sf::Vector2i pos_zombie = zombies[i]->get_position();
        zombies[i]->emplacement(pos_zombie.x + 3, pos_zombie.y);

        // Quand le zombie arrive aux coordonnés du chateau il meurt
        if (sprites_zombies[i].getPosition().x >= 1480)
        {
            if (zombies[i]->get_HP() > 0)
            {
                std::cout << "Le zombie " << i << " vient de toucher le chateau" << std::endl;

                free(zombies[i]);
                sprites_zombies[i].setColor(sf::Color::Transparent);  

                Base->Degats(Base);

                zombiesEnVie -= 1;
                zombiesKills += 1;
            }
        }
    }

}



// ----------------------- TANK ----------------------- //

void spawn_tank() {

    // Texture Tank
    if (!Tank_t.loadFromFile("ressources/img/tank.png"))
    {
        std::cout << "Erreur du chargement de tank.png" << std::endl;
    }

    if (tantan < maxTank && finit == false) {

        temps_spawnT++;
        if (temps_spawnT == 50)
        {
            temps_spawnT = 0;

            Tank_t.setSmooth(true);
            sf::Sprite sprite_tank;
            sprite_tank.setTexture(Tank_t);
            sprite_tank.setPosition(-10, 360);
            sprites_tanks.push_back(sprite_tank);

            Tank* montank = new Tank(-10, 360);
            tanks.push_back(montank);

            std::cout << "Tank n " << tantan << " vient de spawn" << std::endl;

            tantan++;

        }
    }

}

void affichage_tanks() {

    int taille = tanks.size();

    for (int i = 0; i < taille; i++) {

        // Gestion de l'animation
        vitesse_animation++;
        if (vitesse_animation == 15)
        {
            vitesse_animation = 0;

            anim.x++;
            if (anim.x * sizeEnnemis >= Tank_t.getSize().x)
            {
                anim.x = 0;
            }
        }

        sprites_tanks[i].setTextureRect(sf::IntRect(anim.x * sizeEnnemis, anim.y * sizeEnnemis, sizeEnnemis, sizeEnnemis));
        sprites_tanks[i].setScale(1.5, 1.5);

        // Affichage des tanks
        window.draw(sprites_tanks[i]);

    }

}

void deplacement_tank() {

    int taille = tanks.size();

    for (int i = 0; i < taille; i++) {

        sprites_tanks[i].move(tanks[i]->get_vitesse(), 0);
        sf::Vector2i pos_tank = tanks[i]->get_position();
        tanks[i]->emplacement(pos_tank.x + 3, pos_tank.y);


        if (sprites_tanks[i].getPosition().x >= 1480)
        {
            if (tanks[i]->get_HP() > 0)
            {
                std::cout << "Le tank " << i << " vient de toucher le chateau" << std::endl;

                free(tanks[i]);
                sprites_tanks[i].setColor(sf::Color::Transparent);

                Base->Degats(Base);

                tanksEnVie -= 1;
                tanksKills += 1;
            }
        }
    }

}


// ----------------------- Runner ----------------------- //


void spawn_runner() {

    // Texture runner
    if (!Runner_t.loadFromFile("ressources/img/runner.png"))
    {
        std::cout << "Erreur du chargement de runner.png" << std::endl;
    }

    if (runrun < maxRunner && finit == false) {

        temps_spawnR++;
        if (temps_spawnR == 10)
        {
            temps_spawnR = 0;

            Runner_t.setSmooth(true);
            sf::Sprite sprite_runner;
            sprite_runner.setTexture(Runner_t);
            sprite_runner.setPosition(-10, 360);
            sprites_runners.push_back(sprite_runner);

            Runner* monrunner = new Runner(-10, 360);
            runners.push_back(monrunner);

            std::cout << "Runner n " << runrun << " vient de spawn" << std::endl;

            runrun++;

        }
    }

}

void affichage_runners() {

    int taille = runners.size();

    for (int i = 0; i < taille; i++) {

        // Gestion de l'animation
        vitesse_animation++;
        if (vitesse_animation == 15)
        {
            vitesse_animation = 0;

            anim.x++;
            if (anim.x * sizeEnnemis >= Runner_t.getSize().x)
            {
                anim.x = 0;
            }
        }

        sprites_runners[i].setTextureRect(sf::IntRect(anim.x * sizeEnnemis, anim.y * sizeEnnemis, sizeEnnemis, sizeEnnemis));
        sprites_runners[i].setScale(1.5, 1.5);

        // Affichage des runners
        window.draw(sprites_runners[i]);

    }

}

void deplacement_runner() {

    int taille = runners.size();

    for (int i = 0; i < taille; i++) {

        sprites_runners[i].move(runners[i]->get_vitesse(), 0);
        sf::Vector2i pos_runner = runners[i]->get_position();
        runners[i]->emplacement(pos_runner.x + 3, pos_runner.y);


        if (sprites_runners[i].getPosition().x >= 1480)
        {
            if (runners[i]->get_HP() > 0)
            {
                std::cout << "Le runner " << i << " vient de toucher le chateau" << std::endl;

                free(runners[i]);
                sprites_runners[i].setColor(sf::Color::Transparent);

                Base->Degats(Base);

                runnersEnVie -= 1;
                runnerKills += 1;
            }
        }
    }

}

// ----------------------- Mages ----------------------- //


void spawn_mage() {


    // Texture mage
    if (clock() / CLOCKS_PER_SEC != 2)
    {
        if (!Mage_t.loadFromFile("ressources/img/mage.png"))
        {
            std::cout << "Erreur du chargement de mage.png" << std::endl;
        }
    }

    // Toutes les 2 secondes la texture change ( on se base sur le temps de la regénération des points de vie du mage )
    // On calcul tous les multiples de 2
    int n = 2;
    int m = n;
    for (n = 1; n <= 100; ++n)
    {
        if (n % m == 0)
          
        if (clock() / CLOCKS_PER_SEC == n)
        {
            // Texture mage
            if (!Mage_t.loadFromFile("ressources/img/mage_regen.png"))
            {
                std::cout << "Erreur du chargement de mage_regen.png" << std::endl;
            }
        }
    }

    if (magmag < maxMage && finit == false) {

        temps_spawnM++;
        if (temps_spawnM == 60)
        {
            temps_spawnM = 0;

            Mage_t.setSmooth(true);
            sf::Sprite sprite_mage;
            sprite_mage.setTexture(Mage_t);
            sprite_mage.setPosition(-10, 360);
            sprites_mages.push_back(sprite_mage);

            Mage* monmage = new Mage(-10, 360);
            mages.push_back(monmage);
            monmage->regen();

            std::cout << "Mage n " << magmag << " vient de spawn" << std::endl;

            magmag++;

        }
    }

}

void affichage_mages() {

    int taille = mages.size();

    for (int i = 0; i < taille; i++) {

        // Gestion de l'animation
        vitesse_animation++;
        if (vitesse_animation == 15)
        {
            vitesse_animation = 0;

            anim.x++;
            if (anim.x * sizeEnnemis >= Mage_t.getSize().x)
            {
                anim.x = 0;
            }
        }

        sprites_mages[i].setTextureRect(sf::IntRect(anim.x * sizeEnnemis, anim.y * sizeEnnemis, sizeEnnemis, sizeEnnemis));
        sprites_mages[i].setScale(1.5, 1.5);

        // Affichage des mages
        window.draw(sprites_mages[i]);

    }

}

void deplacement_mage() {

    int taille = mages.size();

    for (int i = 0; i < taille; i++) {

        sprites_mages[i].move(mages[i]->get_vitesse(), 0);
        sf::Vector2i pos_mage = mages[i]->get_position();
        mages[i]->emplacement(pos_mage.x + 3, pos_mage.y);


        if (sprites_mages[i].getPosition().x >= 1480)
        {
            if (mages[i]->get_HP() > 0)
            {
                std::cout << "Le mage " << i << " vient de toucher le chateau" << std::endl;

                free(mages[i]);
                sprites_mages[i].setColor(sf::Color::Transparent);

                Base->Degats(Base);

                magesEnVie -= 1;
                magesKills += 1;
            }
        }
    }

}


// -------------------------- SYSTEME DE COMPTEUR D'ENNEMIS -------------------------- //



int Static_Ennemis_En_Vie = zombiesEnVie + tanksEnVie + runnersEnVie + magesEnVie;


void affichage_compteur_ennemis() {

    sf::Text NB_Ennemis;
    int total_ennemis_EnVie = zombiesEnVie + tanksEnVie + runnersEnVie + magesEnVie;
    std::string ennemisEnVie_string = std::to_string(total_ennemis_EnVie);

    NB_Ennemis.setString("Ennemis en vie " + ennemisEnVie_string);
    NB_Ennemis.setCharacterSize(70);

    NB_Ennemis.setFont(font);
    NB_Ennemis.setPosition(620, 20);

    if (total_ennemis_EnVie == Static_Ennemis_En_Vie)
    {
        NB_Ennemis.setFillColor(sf::Color::Black);
    }

    if (total_ennemis_EnVie < Static_Ennemis_En_Vie)
    {
        NB_Ennemis.setFillColor(sf::Color::Green);
    }

    if (total_ennemis_EnVie <= Static_Ennemis_En_Vie / 2)
    {
        NB_Ennemis.setFillColor(sf::Color::Yellow);
    }

    if (total_ennemis_EnVie <= Static_Ennemis_En_Vie / 4)
    {
        NB_Ennemis.setFillColor(sf::Color::Red);
    }

    if (total_ennemis_EnVie <= Static_Ennemis_En_Vie / 8)
    {
        NB_Ennemis.setFillColor(sf::Color::Magenta);
    }

    if (total_ennemis_EnVie <= -1)
    {
        NB_Ennemis.setFillColor(sf::Color::White);
        NB_Ennemis.setString("J'crois il y a un probleme chef ( " + ennemisEnVie_string + " ) ");
        NB_Ennemis.setPosition(400, 20);
    }


    window.draw(NB_Ennemis);

}








// -------------------------- SYSTEME DE VAGUES -------------------------- //


void affichage_vagues() {
     
    sf::Text affichage_vague;

    std::string affichage_vague_string = std::to_string(numero_vague);

    affichage_vague.setString("Vague " + affichage_vague_string);
    affichage_vague.setCharacterSize(70);

    affichage_vague.setFont(font);
    affichage_vague.setPosition(700, 340);

    window.draw(affichage_vague);

}
/*
void nouvelle_vague() {

    maxZombie = origineZombie * numero_vague;
    maxRunner = origineRunner * numero_vague;
    maxTank = origineTank * numero_vague;
    maxMage = origineMage * numero_vague;

    zombiesEnVie = origineZombie * numero_vague - origineZombie;
    runnersEnVie = origineRunner * numero_vague - origineRunner;
    tanksEnVie = origineTank * numero_vague - origineTank;
    magesEnVie = origineMage * numero_vague - origineMage;

    std::cout << "\nMax zombie " << maxZombie << std::endl;
    std::cout << "\nMax Runner " << maxRunner << std::endl;
    std::cout << "\nMax Tank " << maxTank << std::endl;
    std::cout << "\nMax Mage " << maxMage << std::endl;
    
}
*/
void vague3() {

    std::cout << "Début vague 3" << std::endl;

    maxZombie = 45;
    maxRunner = 20;
    maxTank = 15;
    maxMage = 20;

    zombiesEnVie = maxZombie;
    runnersEnVie = maxRunner;
    tanksEnVie = maxTank;
    magesEnVie = maxMage;

    std::cout << "\nMax zombie " << maxZombie << std::endl;
    std::cout << "\nMax Runner " << maxRunner << std::endl;
    std::cout << "\nMax Tank " << maxTank << std::endl;
    std::cout << "\nMax Mage " << maxMage << std::endl;

}

void vague2() {

    std::cout << "Début vague 2" << std::endl;

    maxZombie = 25;
    maxRunner = 10;
    maxTank = 7;
    maxMage = 12;

    zombiesEnVie = maxZombie;
    runnersEnVie = maxRunner;
    tanksEnVie = maxTank;
    magesEnVie = maxMage;

    std::cout << "\nMax zombie " << maxZombie << std::endl;
    std::cout << "\nMax Runner " << maxRunner << std::endl;
    std::cout << "\nMax Tank " << maxTank << std::endl;
    std::cout << "\nMax Mage " << maxMage << std::endl;

}

void changement_vagues() {
    int total_ennemis = zombiesEnVie + tanksEnVie + runnersEnVie + magesEnVie;

    if (total_ennemis <= 0)
    {
        std::cout << "Changement de vague !" << std::endl;
        numero_vague += 1;

        vague2();
       


    }

}

