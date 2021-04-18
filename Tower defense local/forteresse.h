#include "class_ennemis.h"


class Forteresse {
private:
    int vie;
public:
    Forteresse();
};

Forteresse::Forteresse() {
    this->vie = 10;
    if (Zombie = position x, position y) {
        vie -= 2;
    }
    else if (Tank = position x, position y) {
        vie -= 4;
    }
    else if (Runner = position x, position y) {
        vie -= 1;
    }
    else if (Mage) {
        vie -= 5;
    }
}