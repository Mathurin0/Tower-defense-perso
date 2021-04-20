#pragma region variables
int place = 1;
int selection = 0;

//textures des tours
sf::Texture Archer_t;
sf::Texture Canon_t;
sf::Texture Canon_glace_t;
sf::Texture Mortier_t;

//sprites des tours
std::vector<sf::Sprite> sprites_canons;
std::vector<sf::Sprite> sprites_canons_glace;
std::vector<sf::Sprite> sprites_mortiers;
std::vector<sf::Sprite> sprites_archers;

//tableaux pour stocker les tours
std::vector<Canon*> canons;
std::vector<Canon_Glace*> canons_glace;
std::vector<Mortier*> mortiers;
std::vector<Archers*> archers;
#pragma endregion variables


void creation_tour() {
    //Int permettent de prendre la taille des canons et de l'incrémenter dans une autre variable
    int Size_canons = canons.size();
    int Size_canons_glace = canons_glace.size();
    int Size_mortiers = mortiers.size();
    int Size_archers = archers.size();
    //ici on vérifie si un canons à déjà été posé et si non on renvoi vers un else permettent alors de poser le 1er cannon
    if (Size_canons > 0) {
        sf::Vector2i position_souris = sf::Mouse::getPosition(window);
        // une fois que le premier canon est posé alors il passe dans ce if qui vérifie si la tour n'est pas au dessus de la tour précédente
        if ((std::abs((position_souris.x) - (canons[Size_canons - 1]->get_position().x)) > 30) ||
            (std::abs((position_souris.y) - (canons[Size_canons - 1]->get_position().y)) > 70)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && joueur->get_argent() >= 100) {
                //permet de savoir quel tour à été choisi
                selection = 0;
                place = 0;
                joueur->paiement(100);
            }
        }
    }
    // else qui permet alors de poser la première tour
    else {
        //ici on vérifie si la touche Up donc flèche du haut est presser ET si le joueur possède assez d'argent dans son solde pour acheter la tour
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && joueur->get_argent() >= 100) {
            selection = 0;
            place = 0;
            //fonction qui permet le système de paiement lors de la pose d'une tour 
            joueur->paiement(100);
        }
    }
    if (Size_canons_glace > 0) {
        sf::Vector2i position_souris = sf::Mouse::getPosition(window);
        if ((std::abs((position_souris.x) - (canons_glace[Size_canons_glace - 1]->get_position().x)) > 30) ||
            (std::abs((position_souris.y) - (canons_glace[Size_canons_glace - 1]->get_position().y)) > 70)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && joueur->get_argent() >= 120) {
                selection = 1;
                place = 0;
                joueur->paiement(120);
            }
        }
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && joueur->get_argent() >= 120) {
            selection = 1;
            place = 0;
            joueur->paiement(120);
        }
    }
    if (Size_mortiers > 0) {
        sf::Vector2i position_souris = sf::Mouse::getPosition(window);
        if ((std::abs((position_souris.x) - (mortiers[Size_mortiers - 1]->get_position().x)) > 30) ||
            (std::abs((position_souris.y) - (mortiers[Size_mortiers - 1]->get_position().y)) > 70)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && joueur->get_argent() >= 150) {
                selection = 2;
                place = 0;
                joueur->paiement(150);
            }
        }
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && joueur->get_argent() >= 150) {
            selection = 2;
            place = 0;
            joueur->paiement(150);
        }
    }
    if (Size_archers > 0) {
        sf::Vector2i position_souris = sf::Mouse::getPosition(window);
        if ((std::abs((position_souris.x) - (archers[Size_archers - 1]->get_position().x)) > 30) ||
            (std::abs((position_souris.y) - (archers[Size_archers - 1]->get_position().y)) > 70)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && joueur->get_argent() >= 70) {
                selection = 3;
                place = 0;
                joueur->paiement(70);
            }
        }
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && joueur->get_argent() >= 70) {
            selection = 3;
            place = 0;
            joueur->paiement(70);
        }
    }
    //placement de la tour
    if (place == 0) {
        sf::Vector2i position_souris = sf::Mouse::getPosition(window);
        //pour verifier qu'on a bien demander de placer une tour avant
        if (selection == 0) {
            //pour les textures
            if (!Canon_t.loadFromFile("ressources/img/canon1.png")) {
                std::cout << "Erreur du chargement de canon1.png" << std::endl;
            }
            Canon_t.setSmooth(true);
            sf::Sprite sprite_Canon;
            sprite_Canon.setTexture(Canon_t);
            sprite_Canon.setScale(0.5, 0.5);
            sprite_Canon.setPosition(position_souris.x, position_souris.y);
            sprites_canons.push_back(sprite_Canon);

            //creation du canon et ajout dans le tableau
            Canon* monCanon = new Canon(position_souris.x, position_souris.y);
            canons.push_back(monCanon);
            place = 1;
        }
        else if (selection == 1) {
            //pour les textures
            if (!Canon_glace_t.loadFromFile("ressources/img/glace1.png")) {
                std::cout << "Erreur du chargement de glace1.png" << std::endl;
            }
            Canon_glace_t.setSmooth(true);
            sf::Sprite sprite_Canon_glace;
            sprite_Canon_glace.setTexture(Canon_glace_t);
            sprite_Canon_glace.setScale(0.35, 0.35);
            sprite_Canon_glace.setPosition(position_souris.x, position_souris.y);
            sprites_canons_glace.push_back(sprite_Canon_glace);

            //creation du canon de glace et ajout dans le tableau
            Canon_Glace* monCanon_glace = new Canon_Glace(position_souris.x, position_souris.y);
            canons_glace.push_back(monCanon_glace);
            place = 1;
        }
        else if (selection == 2) {
            //pour les textures
            if (!Mortier_t.loadFromFile("ressources/img/mortier1.png")) {
                std::cout << "Erreur du chargement de mortier1.png" << std::endl;
            }
            Mortier_t.setSmooth(true);
            sf::Sprite sprite_Mortier;
            sprite_Mortier.setTexture(Mortier_t);
            sprite_Mortier.setScale(0.35, 0.35);
            sprite_Mortier.setPosition(position_souris.x, position_souris.y);
            sprites_mortiers.push_back(sprite_Mortier);

            //creation du mortier et ajout dans le tableau
            Mortier* monMortier = new Mortier(position_souris.x, position_souris.y);
            mortiers.push_back(monMortier);
            place = 1;
        }
        else if (selection == 3) {
            //pour les textures
            if (!Archer_t.loadFromFile("ressources/img/archer1.png")) {
                std::cout << "Erreur du chargement de archer1.png" << std::endl;
            }
            Archer_t.setSmooth(true);
            sf::Sprite sprite_Archer;
            sprite_Archer.setTexture(Archer_t);
            sprite_Archer.setScale(0.75, 0.75);
            sprite_Archer.setPosition(position_souris.x, position_souris.y);
            sprites_archers.push_back(sprite_Archer);

            //creation de la tour d'archers et ajout dans le tableau
            Archers* monArcher = new Archers(position_souris.x, position_souris.y);
            archers.push_back(monArcher);
            place = 1;
        }
    }

}


void affichage_tours() {
    //affichage des canons
    int taille = canons.size();
    for (int i = 0; i < taille; i++) {
        window.draw(sprites_canons[i]);
    }
    //affichage des canons de glace
    taille = canons_glace.size();
    for (int i = 0; i < taille; i++) {
        window.draw(sprites_canons_glace[i]);
    }
    //affichage des mortiers
    taille = mortiers.size();
    for (int i = 0; i < taille; i++) {
        window.draw(sprites_mortiers[i]);
    }
    //affichage des archers
    taille = archers.size();
    for (int i = 0; i < taille; i++) {
        window.draw(sprites_archers[i]);
    }
}