class Zombie {
private:
    int HP;
    int Degat;
    int vitesse;
    int pieces;
    sf::Vector2i position;
public:
    Zombie(int x, int y);
    void prendre_degats(int nb_degats);
    sf::Vector2i get_position() {
        return this->position;
    }
    void emplacement(int x, int y);
    int get_HP() {
        return this->HP;
    }
    int get_pieces() {
        return this->pieces;
    }
    void remove();
};

Zombie::Zombie(int x, int y) {
    this->HP = 50;
    this->Degat = 2;
    this->vitesse = 5;
    this->pieces = 10;
    this->position.x = x;
    this->position.y = y;
}

void Zombie::prendre_degats(int nb_degats) {
    this->HP -= nb_degats;
}
void Zombie::emplacement(int x, int y) {

    this->position.x = x;
    this->position.y = y;
}

void Zombie::remove() {
    
}


class Tank {
private:
    int HP;
    int Degat;
    int vitesse;
    int pieces;
    sf::Vector2i position;
public:
    Tank();
    void prendre_degats(int nb_degats);
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_HP() {
        return this->HP;
    }
};

Tank::Tank() {
    this->HP = 100;
    this->Degat = 4;
    this->vitesse = 2;
    this->pieces = 40;
}

void Tank::prendre_degats(int nb_degats) {
    this->HP -= nb_degats;
}


class Runner {
private:
    int HP;
    int Degat;
    int vitesse;
    int pieces;
    sf::Vector2i position;
public:
    Runner();
    void prendre_degats(int nb_degats);
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_HP() {
        return this->HP;
    }
};

Runner::Runner() {
    this->HP = 30;
    this->Degat = 1;
    this->vitesse = 10;
    this->pieces = 15;
}

void Runner::prendre_degats(int nb_degats) {
    this->HP -= nb_degats;
}


class Mage {
private:
    int HP;
    int Degat;
    int vitesse;
    int pieces;
    sf::Vector2i position;
public:
    Mage();
    void prendre_degats(int nb_degats);
    void regen();
    sf::Vector2i get_position() {
        return this->position;
    }
    int get_HP() {
        return this->HP;
    }
};

Mage::Mage() {
    this->HP = 60;
    this->Degat = 5;
    this->vitesse = 5;
    this->pieces = 60;
}

void Mage::prendre_degats(int nb_degats) {
    this->HP -= nb_degats;
}