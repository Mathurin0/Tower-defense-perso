#include <SFML/Graphics.hpp>


class Canon {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout[3];
    sf::Vector2i position;
    Zombie* cible;
public:
    Canon(int x, int y);
    void level_up();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_portee() {
        return this->portee;
    }
    void set_cible(Zombie* cible);
};
Canon::Canon(int x, int y) {
    this->degat_par_coup = 20;
    this->portee = 100;               //TODO
    this->coup_par_seconde = 5;       //TODO
    this->level = 1;
    this->cout[0] = 100;
    this->cout[1] = 120;
    this->cout[2] = 150;
    this->position.x = x;
    this->position.y = y;
}
void Canon::level_up() {
    if (this->level == 1) {
        this->level = 2;
        this->degat_par_coup = 40;
        this->portee = 120;               //TODO
        this->coup_par_seconde = 6;       //TODO
    }
    if (this->level == 2) {
        this->level = 3;
        this->degat_par_coup = 50;
        this->portee = 150;               //TODO
        this->coup_par_seconde = 8;       //TODO
    }
}
void Canon::set_cible(Zombie* cible) {
    this->cible = cible;
}



class Canon_Glace {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout[3];
    sf::Vector2i position;
    Zombie* cible;
public:
    Canon_Glace(int x, int y);
    void level_up();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_portee() {
        return this->portee;
    }
    void set_cible(Zombie* cible);
};
Canon_Glace::Canon_Glace(int x, int y) {
    this->degat_par_coup = 10;
    this->portee = 150;               //TODO
    this->coup_par_seconde = 2;       //TODO
    this->level = 1;
    this->cout[0] = 120;
    this->cout[1] = 150;
    this->cout[2] = 200;
    this->position.x = x;
    this->position.y = y;
}
void Canon_Glace::level_up() {
    if (this->level == 1) {
        this->level = 2;
        this->degat_par_coup = 20;
        this->portee = 170;               //TODO
        this->coup_par_seconde = 3;       //TODO
    }
    if (this->level == 2) {
        this->level = 3;
        this->degat_par_coup = 30;
        this->portee = 200;               //TODO
        this->coup_par_seconde = 4;       //TODO
    }
}
void Canon_Glace::set_cible(Zombie* cible) {
    this->cible = cible;
}



class Mortier {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout[3];
    sf::Vector2i position;
    Zombie* cible;
public:
    Mortier(int x, int y);
    void level_up();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_portee() {
        return this->portee;
    }
    void set_cible(Zombie* cible);
};
Mortier::Mortier(int x, int y) {
    this->degat_par_coup = 30;
    this->portee = 150;               //TODO
    this->coup_par_seconde = 2;       //TODO
    this->level = 1;
    this->cout[0] = 150;
    this->cout[1] = 200;
    this->cout[2] = 250;
    this->position.x = x;
    this->position.y = y;
}
void Mortier::level_up() {
    if (this->level == 1) {
        this->level = 2;
        this->degat_par_coup = 60;
        this->portee = 170;               //TODO
        this->coup_par_seconde = 3;       //TODO
    }
    if (this->level == 2) {
        this->level = 3;
        this->degat_par_coup = 90;
        this->portee = 200;               //TODO
        this->coup_par_seconde = 4;       //TODO
    }
}
void Mortier::set_cible(Zombie* cible) {
    this->cible = cible;
}



class Archers {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout[3];
    sf::Vector2i position;
    Zombie* cible;
public:
    Archers(int x, int y);
    void level_up();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_portee() {
        return this->portee;
    }
    void set_cible(Zombie* cible);
};
Archers::Archers(int x, int y) {
    this->degat_par_coup = 15;
    this->portee = 120;               //TODO
    this->coup_par_seconde = 7;       //TODO
    this->level = 1;
    this->cout[0] = 70;
    this->cout[1] = 100;
    this->cout[2] = 120;
    this->position.x = x;
    this->position.y = y;
}
void Archers::level_up() {
    if (this->level == 1) {
        this->level = 2;
        this->degat_par_coup = 30;
        this->portee = 150;               //TODO
        this->coup_par_seconde = 10;       //TODO
    }
    if (this->level == 2) {
        this->level = 3;
        this->degat_par_coup = 45;
        this->portee = 170;               //TODO
        this->coup_par_seconde = 15;       //TODO
    }
}
void Archers::set_cible(Zombie* cible) {
    this->cible = cible;
}