#include <SFML/Graphics.hpp>


class Canon {
private:
    //variables de la classe en privé pour ne pouvoir y accéder que pas des fonctions
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout[3];
    sf::Vector2i position;
    Zombie* cible_zombie;
    Runner* cible_runner;
    Tank* cible_tank;
    Mage* cible_mage;
    int compteur_attaque;
    int position_ennemi;
public:
    //constructeurs, getteur, setteurs
    Canon(int x, int y);
    void level_up();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_portee() {
        return this->portee;
    }
    void set_cible_zombie(Zombie* zonzon) {
        this->cible_zombie = zonzon;
    }
    Zombie* get_cible_zombie() {
        return this->cible_zombie;
    }
    void set_cible_runner(Runner* forrest) {
        this->cible_runner = forrest;
    }
    Runner* get_cible_runner() {
        return this->cible_runner;
    }
    void set_cible_tank(Tank* tanky) {
        this->cible_tank = tanky;
    }
    Tank* get_cible_tank() {
        return this->cible_tank;
    }
    void set_cible_mage(Mage* sorcier) {
        this->cible_mage = sorcier;
    }
    Mage* get_cible_mage() {
        return this->cible_mage;
    }
    int get_degats() {
        return this->degat_par_coup;
    }
    int get_coup_par_seconde() {
        return this->coup_par_seconde;
    }
    int get_compteur_attaque() {
        return this->compteur_attaque;
    }
    void reset_compteur_attaque() {
        this->compteur_attaque = 0;
    }
    void increment_compteur_attaque() {
        this->compteur_attaque++;
    }
    void set_position_ennemi(int indice) {
        this->position_ennemi = indice;
    }
    int get_position_ennemi() {
        return this->position_ennemi;
    }
};
Canon::Canon(int x, int y) {
    this->degat_par_coup = 30;
    this->portee = 100;
    this->coup_par_seconde = 5;
    this->level = 1;
    this->cout[0] = 100;
    this->cout[1] = 120;
    this->cout[2] = 150;
    this->position.x = x;
    this->position.y = y;
    this->cible_zombie = NULL;
    this->cible_runner = NULL;
    this->cible_tank = NULL;
    this->cible_mage = NULL;
    this->compteur_attaque = 0;
    this->position_ennemi = 0;
}
void Canon::level_up() {
    if (this->level == 1) {
        this->level = 2;
        this->degat_par_coup = 40;
        this->portee = 120;
        this->coup_par_seconde = 6;
    }
    if (this->level == 2) {
        this->level = 3;
        this->degat_par_coup = 50;
        this->portee = 150;
        this->coup_par_seconde = 8;
    }
}



class Canon_Glace {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout[3];
    sf::Vector2i position;
    Zombie* cible_zombie;
    Runner* cible_runner;
    Tank* cible_tank;
    Mage* cible_mage;
    int compteur_attaque;
    int position_ennemi;
public:
    Canon_Glace(int x, int y);
    void level_up();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_portee() {
        return this->portee;
    }
    void set_cible_zombie(Zombie* zonzon) {
        this->cible_zombie = zonzon;
    }
    Zombie* get_cible_zombie() {
        return this->cible_zombie;
    }
    void set_cible_runner(Runner* forrest) {
        this->cible_runner = forrest;
    }
    Runner* get_cible_runner() {
        return this->cible_runner;
    }
    void set_cible_tank(Tank* tanky) {
        this->cible_tank = tanky;
    }
    Tank* get_cible_tank() {
        return this->cible_tank;
    }
    void set_cible_mage(Mage* sorcier) {
        this->cible_mage = sorcier;
    }
    Mage* get_cible_mage() {
        return this->cible_mage;
    }
    int get_degats() {
        return this->degat_par_coup;
    }
    int get_coup_par_seconde() {
        return this->coup_par_seconde;
    }
    int get_compteur_attaque() {
        return this->compteur_attaque;
    }
    void reset_compteur_attaque() {
        this->compteur_attaque = 0;
    }
    void increment_compteur_attaque() {
        this->compteur_attaque++;
    }
    void set_position_ennemi(int indice) {
        this->position_ennemi = indice;
    }
    int get_position_ennemi() {
        return this->position_ennemi;
    }
};
Canon_Glace::Canon_Glace(int x, int y) {
    this->degat_par_coup = 20;
    this->portee = 150;
    this->coup_par_seconde = 2;
    this->level = 1;
    this->cout[0] = 120;
    this->cout[1] = 150;
    this->cout[2] = 200;
    this->position.x = x;
    this->position.y = y;
    this->cible_zombie = NULL;
    this->cible_runner = NULL;
    this->cible_tank = NULL;
    this->cible_mage = NULL;
    this->compteur_attaque = 0;
    this->position_ennemi = 0;
}
void Canon_Glace::level_up() {
    if (this->level == 1) {
        this->level = 2;
        this->degat_par_coup = 20;
        this->portee = 170;
        this->coup_par_seconde = 3;
    }
    if (this->level == 2) {
        this->level = 3;
        this->degat_par_coup = 30;
        this->portee = 200;
        this->coup_par_seconde = 4;
    }
}



class Mortier {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout[3];
    sf::Vector2i position;
    Zombie* cible_zombie;
    Runner* cible_runner;
    Tank* cible_tank;
    Mage* cible_mage;
    int compteur_attaque;
    int position_ennemi;
public:
    Mortier(int x, int y);
    void level_up();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_portee() {
        return this->portee;
    }
    void set_cible_zombie(Zombie* zonzon) {
        this->cible_zombie = zonzon;
    }
    Zombie* get_cible_zombie() {
        return this->cible_zombie;
    }
    void set_cible_runner(Runner* forrest) {
        this->cible_runner = forrest;
    }
    Runner* get_cible_runner() {
        return this->cible_runner;
    }
    void set_cible_tank(Tank* tanky) {
        this->cible_tank = tanky;
    }
    Tank* get_cible_tank() {
        return this->cible_tank;
    }
    void set_cible_mage(Mage* sorcier) {
        this->cible_mage = sorcier;
    }
    Mage* get_cible_mage() {
        return this->cible_mage;
    }
    int get_degats() {
        return this->degat_par_coup;
    }
    int get_coup_par_seconde() {
        return this->coup_par_seconde;
    }
    int get_compteur_attaque() {
        return this->compteur_attaque;
    }
    void reset_compteur_attaque() {
        this->compteur_attaque = 0;
    }
    void increment_compteur_attaque() {
        this->compteur_attaque++;
    }
    void set_position_ennemi(int indice) {
        this->position_ennemi = indice;
    }
    int get_position_ennemi() {
        return this->position_ennemi;
    }
};
Mortier::Mortier(int x, int y) {
    this->degat_par_coup = 40;
    this->portee = 150;
    this->coup_par_seconde = 2;
    this->level = 1;
    this->cout[0] = 150;
    this->cout[1] = 200;
    this->cout[2] = 250;
    this->position.x = x;
    this->position.y = y;
    this->cible_zombie = NULL;
    this->cible_runner = NULL;
    this->cible_tank = NULL;
    this->cible_mage = NULL;
    this->compteur_attaque = 0;
    this->position_ennemi = 0;
}
void Mortier::level_up() {
    if (this->level == 1) {
        this->level = 2;
        this->degat_par_coup = 60;
        this->portee = 170;
        this->coup_par_seconde = 3;
    }
    if (this->level == 2) {
        this->level = 3;
        this->degat_par_coup = 90;
        this->portee = 200;
        this->coup_par_seconde = 4;
    }
}



class Archers {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout[3];
    sf::Vector2i position;
    Zombie* cible_zombie;
    Runner* cible_runner;
    Tank* cible_tank;
    Mage* cible_mage;
    int compteur_attaque;
    int position_ennemi;
public:
    Archers(int x, int y);
    void level_up();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_portee() {
        return this->portee;
    }
    void set_cible_zombie(Zombie* zonzon) {
        this->cible_zombie = zonzon;
    }
    Zombie* get_cible_zombie() {
        return this->cible_zombie;
    }
    void set_cible_runner(Runner* forrest) {
        this->cible_runner = forrest;
    }
    Runner* get_cible_runner() {
        return this->cible_runner;
    }
    void set_cible_tank(Tank* tanky) {
        this->cible_tank = tanky;
    }
    Tank* get_cible_tank() {
        return this->cible_tank;
    }
    void set_cible_mage(Mage* sorcier) {
        this->cible_mage = sorcier;
    }
    Mage* get_cible_mage() {
        return this->cible_mage;
    }
    int get_degats() {
        return this->degat_par_coup;
    }
    int get_coup_par_seconde() {
        return this->coup_par_seconde;
    }
    int get_compteur_attaque() {
        return this->compteur_attaque;
    }
    void reset_compteur_attaque() {
        this->compteur_attaque = 0;
    }
    void increment_compteur_attaque() {
        this->compteur_attaque++;
    }
    void set_position_ennemi(int indice) {
        this->position_ennemi = indice;
    }
    int get_position_ennemi() {
        return this->position_ennemi;
    }
};
Archers::Archers(int x, int y) {
    this->degat_par_coup = 25;
    this->portee = 120;
    this->coup_par_seconde = 7;
    this->level = 1;
    this->cout[0] = 70;
    this->cout[1] = 100;
    this->cout[2] = 120;
    this->position.x = x;
    this->position.y = y;
    this->cible_zombie = NULL;
    this->cible_runner = NULL;
    this->cible_tank = NULL;
    this->cible_mage = NULL;
    this->compteur_attaque = 0;
    this->position_ennemi = 0;
}
void Archers::level_up() {
    if (this->level == 1) {
        this->level = 2;
        this->degat_par_coup = 30;
        this->portee = 150;
        this->coup_par_seconde = 10;
    }
    if (this->level == 2) {
        this->level = 3;
        this->degat_par_coup = 45;
        this->portee = 170;
        this->coup_par_seconde = 15;
    }
}