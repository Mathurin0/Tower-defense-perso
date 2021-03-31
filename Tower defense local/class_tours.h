class Canon {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout_init;
    int cout_2;
    int cout_3;
public:
    Canon();
    void level_up();
};

Canon::Canon() {
    this->degat_par_coup = 20;
    this->portee = 100;               //TODO
    this->coup_par_seconde = 5;       //TODO
    this->level = 1;
    this->cout_init = 100;
    this->cout_2 = 120;
    this->cout_3 = 150;
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


class Canon_Glace {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout_init;
    int cout_2;
    int cout_3;
public:
    Canon_Glace();
    void level_up();
};

Canon_Glace::Canon_Glace() {
    this->degat_par_coup = 10;
    this->portee = 150;               //TODO
    this->coup_par_seconde = 2;       //TODO
    this->level = 1;
    this->cout_init = 120;
    this->cout_2 = 150;
    this->cout_3 = 200;
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


class Mortier {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout_init;
    int cout_2;
    int cout_3;
public:
    Mortier();
    void level_up();
};

Mortier::Mortier() {
    this->degat_par_coup = 30;
    this->portee = 150;               //TODO
    this->coup_par_seconde = 2;       //TODO
    this->level = 1;
    this->cout_init = 150;
    this->cout_2 = 200;
    this->cout_3 = 250;
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



class Archers {
private:
    int degat_par_coup;
    int portee;
    int coup_par_seconde;
    int level;
    int cout_init;
    int cout_2;
    int cout_3;
public:
    Archers();
    void level_up();
};

Archers::Archers() {
    this->degat_par_coup = 15;
    this->portee = 120;               //TODO
    this->coup_par_seconde = 7;       //TODO
    this->level = 1;
    this->cout_init = 70;
    this->cout_2 = 100;
    this->cout_3 = 120;
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