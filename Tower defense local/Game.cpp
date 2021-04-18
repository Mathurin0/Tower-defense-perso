#include "Header.h"
#include "game.h"
#include "mainmenu.h"




game* game::instance = nullptr;


game::game(int WIDTH, int HEIGHT)
    :window(sf::VideoMode(WIDTH, HEIGHT), "FC-Fiak | Tower Defense")
{

    if (instance == nullptr) {
        instance = this;
    }


    // Gestion de l'icone
    sf::Image icon;

    if (!icon.loadFromFile("ressources/img/icone.png"))
    {
        EXIT_FAILURE;
    }

    window.setIcon(93, 98, icon.getPixelsPtr());


}

game::~game() {
    instance = nullptr;
}


void game::run() {

}