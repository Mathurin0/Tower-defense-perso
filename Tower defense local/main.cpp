#include "Header.h"
#include "joueur.h"

#pragma region variables
sf::RenderWindow window;
sf::Vector2i position_souris;
sf::Font font;
Score* joueur = new Score();

int loose_screen = 0;
#pragma endregion variables

#include "shop.h"
#include "loose.h"
#include "mage_regen.h"
#include "class_ennemis.h"
#include "regen_mage.h"
#include "class_tours.h"
#include "class_chateau.h"
#include "placer_tours.h"
#include "chateau.h"
#include "ennemis.h"
#include "detection_ennemis.h"
#include "attaquer_ennemis.h"

#include "fenetre.h"



int main()
{
	if (!font.loadFromFile("ressources/Hiatus.ttf"))
	{
		std::cout << "Erreur du chargement de la police" << std::endl;
	}

	// Gestion de l'écran de fin random
	srand(time(NULL));
	loose_screen = rand() % 7 + 1;
	

    Window();


	

    return 0;
}