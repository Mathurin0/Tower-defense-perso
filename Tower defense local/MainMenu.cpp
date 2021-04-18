
#include <iostream>
#include "mainmenu.h"

mainMenu::mainMenu() {

    // Définition de la fenêtre (taille + titre)
    sf::RenderWindow window(sf::VideoMode(800, 600), "FC-Fiak | Menu Principal");


    // Gestion de la police 

    sf::Font font;
    if (!font.loadFromFile("ressources/Hiatus.ttf"))
    {
        EXIT_FAILURE;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("FC-Fiak");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);

    sf::Vector2f pos = text.getPosition();
    text.setPosition(pos.x + 340, pos.y + 5);







    // On limite les fps
    window.setFramerateLimit(30);

    //Cette boucle permet de dire que si la fenêtre est toujours ouvert le programme tourne
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            // Si on ferme la fenêtre ça stop le programme
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(text);

        window.display();
    }

}