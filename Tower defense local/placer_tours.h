#pragma region variables
int place = 1;
int selection = 1;
sf::Texture Archer_t;
sf::Texture Canon_t;
sf::Texture Canon_glace_t;
sf::Texture Mortier_t;

std::vector<sf::Sprite> sprites_canons;
std::vector<sf::Sprite> sprites_canons_glace;
std::vector<sf::Sprite> sprites_mortiers;
std::vector<sf::Sprite> sprites_archers;

std::vector<Canon*> canons;
std::vector<Canon_Glace*> canons_glace;
std::vector<Mortier*> mortiers;
std::vector<Archers*> archers;
#pragma endregion variables


void creation_tour() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) {
        selection = 0;
        place = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
        selection = 1;
        place = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
        selection = 2;
        place = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
        selection = 3;
        place = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && place == 0) {
        sf::Vector2i position_souris = sf::Mouse::getPosition(window);
        if (selection == 0) {
            std::cout << "Canon" << std::endl;
            if (!Canon_t.loadFromFile("ressources/img/canon1.png")) {
                std::cout << "Erreur du chargement de canon1.png" << std::endl;
            }
            Canon_t.setSmooth(true);
            sf::Sprite sprite_Canon;
            sprite_Canon.setTexture(Canon_t);
            sprite_Canon.setPosition(position_souris.x, position_souris.y);
            sprites_canons.push_back(sprite_Canon);

            Canon* monCanon = new Canon(position_souris.x, position_souris.y);
            canons.push_back(monCanon);
            place = 1;
        }
        else if (selection == 1) {
            std::cout << "Glace" << std::endl;
            if (!Canon_glace_t.loadFromFile("ressources/img/glace1.png")) {
                std::cout << "Erreur du chargement de glace1.png" << std::endl;
            }
            Canon_glace_t.setSmooth(true);
            sf::Sprite sprite_Canon_glace;
            sprite_Canon_glace.setTexture(Canon_glace_t);
            sprite_Canon_glace.setPosition(position_souris.x, position_souris.y);
            sprites_canons_glace.push_back(sprite_Canon_glace);

            Canon_Glace* monCanon_glace = new Canon_Glace(position_souris.x, position_souris.y);
            canons_glace.push_back(monCanon_glace);
            place = 1;
        }
        else if (selection == 2) {
            std::cout << "Mortier" << std::endl;
            if (!Mortier_t.loadFromFile("ressources/img/mortier1.png")) {
                std::cout << "Erreur du chargement de mortier1.png" << std::endl;
            }
            Mortier_t.setSmooth(true);
            sf::Sprite sprite_Mortier;
            sprite_Mortier.setTexture(Mortier_t);
            sprite_Mortier.setPosition(position_souris.x, position_souris.y);
            sprites_mortiers.push_back(sprite_Mortier);

            Mortier* monMortier = new Mortier(position_souris.x, position_souris.y);
            mortiers.push_back(monMortier);
            place = 1;
        }
        else if (selection == 3) {
            std::cout << "Archer" << std::endl;
            if (!Archer_t.loadFromFile("ressources/img/archer1.png")) {
                std::cout << "Erreur du chargement de archer1.png" << std::endl;
            }
            Archer_t.setSmooth(true);
            sf::Sprite sprite_Archer;
            sprite_Archer.setTexture(Archer_t);
            sprite_Archer.setPosition(position_souris.x, position_souris.y);
            sprites_archers.push_back(sprite_Archer);

            Archers* monArcher = new Archers(position_souris.x, position_souris.y);
            archers.push_back(monArcher);
            place = 1;
        }
    }

}


void affichage_tours(){
    int taille = canons.size();
    for (int i = 0; i < taille; i++) {
        window.draw(sprites_canons[i]);
    }
    taille = canons_glace.size();
    for (int i = 0; i < taille; i++) {
        window.draw(sprites_canons_glace[i]);
    }
    taille = mortiers.size();
    for (int i = 0; i < taille; i++) {
        window.draw(sprites_mortiers[i]);
    }
    taille = archers.size();
    for (int i = 0; i < taille; i++){
        window.draw(sprites_archers[i]);
    }
}