#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>


#pragma region variables
sf::RenderWindow window;
sf::Vector2i position_souris;
#pragma endregion variables



#include "class_ennemis.h"
#include "class_tours.h"
#include "placer_tours.h"
#include "detection_ennemis.h"


int main()
{
    window.create(sf::VideoMode(1600, 900), "Tower defense");
    window.setPosition(sf::Vector2i(300, 70));    //150
    window.setFramerateLimit(60);

    int speed_animation = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        creation_tour();
        
        
        affichage_tours();
        window.display();
        window.clear();
    }

    return 0;
}