
//fonction d'attaque des ennemis par les tours
void attaque() {

	//on parcours le tableau canons
	for (int i = 0; i < canons.size(); i++)
	{
		//on verifie que la tour ait une cible
		if (canons[i]->get_cible_zombie() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons[i]->increment_compteur_attaque();
			if (canons[i]->get_compteur_attaque() >= (60 / canons[i]->get_coup_par_seconde())) {
				canons[i]->get_cible_zombie()->prendre_degats(canons[i]->get_degats());
				canons[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons[i]->get_cible_zombie()->get_HP() <= 0)
			{
				joueur->gagner_argent(canons[i]->get_cible_zombie()->get_pieces());
				std::cout << "Vous venez de gagner " << canons[i]->get_cible_zombie()->get_pieces() << " coins" << std::endl;

				sprites_zombies[canons[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons[i]->set_cible_zombie(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons[i]->get_cible_zombie() != NULL) {
				sf::Vector2i position_canon = canons[i]->get_position();
				sf::Vector2i position_mob = canons[i]->get_cible_zombie()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons[i]->get_portee()) {
					canons[i]->set_cible_zombie(NULL);
				}
			}
		}
		if (canons[i]->get_cible_runner() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons[i]->increment_compteur_attaque();
			if (canons[i]->get_compteur_attaque() >= (60 / canons[i]->get_coup_par_seconde())) {
				canons[i]->get_cible_runner()->prendre_degats(canons[i]->get_degats());
				canons[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons[i]->get_cible_runner()->get_HP() <= 0)
			{
				joueur->gagner_argent(canons[i]->get_cible_runner()->get_pieces());
				std::cout << "Vous venez de gagner " << canons[i]->get_cible_runner()->get_pieces() << " coins" << std::endl;

				sprites_runners[canons[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons[i]->set_cible_runner(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons[i]->get_cible_runner() != NULL) {
				sf::Vector2i position_canon = canons[i]->get_position();
				sf::Vector2i position_mob = canons[i]->get_cible_runner()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons[i]->get_portee()) {
					canons[i]->set_cible_runner(NULL);
				}
			}
		}
		if (canons[i]->get_cible_tank() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons[i]->increment_compteur_attaque();
			if (canons[i]->get_compteur_attaque() >= (60 / canons[i]->get_coup_par_seconde())) {
				canons[i]->get_cible_tank()->prendre_degats(canons[i]->get_degats());
				canons[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons[i]->get_cible_tank()->get_HP() <= 0)
			{


				joueur->gagner_argent(canons[i]->get_cible_tank()->get_pieces());
				std::cout << "Vous venez de gagner " << canons[i]->get_cible_tank()->get_pieces() << " coins" << std::endl;

				sprites_tanks[canons[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons[i]->set_cible_tank(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons[i]->get_cible_tank() != NULL) {
				sf::Vector2i position_canon = canons[i]->get_position();
				sf::Vector2i position_mob = canons[i]->get_cible_tank()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons[i]->get_portee()) {
					canons[i]->set_cible_tank(NULL);
				}
			}
		}
		if (canons[i]->get_cible_mage() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons[i]->increment_compteur_attaque();
			if (canons[i]->get_compteur_attaque() >= (60 / canons[i]->get_coup_par_seconde())) {
				canons[i]->get_cible_mage()->prendre_degats(canons[i]->get_degats());
				canons[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons[i]->get_cible_mage()->get_HP() <= 0)
			{


				joueur->gagner_argent(canons[i]->get_cible_mage()->get_pieces());
				std::cout << "Vous venez de gagner " << canons[i]->get_cible_mage()->get_pieces() << " coins" << std::endl;

				sprites_mages[canons[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons[i]->set_cible_mage(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons[i]->get_cible_mage() != NULL) {
				sf::Vector2i position_canon = canons[i]->get_position();
				sf::Vector2i position_mob = canons[i]->get_cible_mage()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons[i]->get_portee()) {
					canons[i]->set_cible_mage(NULL);
				}
			}
		}
	}

	//comme pour le canon
	for (int i = 0; i < canons_glace.size(); i++)
	{
		//on verifie que la tour ait une cible
		if (canons_glace[i]->get_cible_zombie() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons_glace[i]->increment_compteur_attaque();
			if (canons_glace[i]->get_compteur_attaque() >= (60 / canons_glace[i]->get_coup_par_seconde())) {
				canons_glace[i]->get_cible_zombie()->prendre_degats(canons_glace[i]->get_degats());
				canons_glace[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons_glace[i]->get_cible_zombie()->get_HP() <= 0)
			{


				joueur->gagner_argent(canons_glace[i]->get_cible_zombie()->get_pieces());
				std::cout << "Vous venez de gagner " << canons_glace[i]->get_cible_zombie()->get_pieces() << " coins" << std::endl;

				sprites_zombies[canons_glace[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons_glace[i]->set_cible_zombie(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons_glace[i]->get_cible_zombie() != NULL) {
				sf::Vector2i position_canon = canons_glace[i]->get_position();
				sf::Vector2i position_mob = canons_glace[i]->get_cible_zombie()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons_glace[i]->get_portee()) {
					canons_glace[i]->set_cible_zombie(NULL);
				}
			}
		}
		if (canons_glace[i]->get_cible_runner() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons_glace[i]->increment_compteur_attaque();
			if (canons_glace[i]->get_compteur_attaque() >= (60 / canons_glace[i]->get_coup_par_seconde())) {
				canons_glace[i]->get_cible_runner()->prendre_degats(canons_glace[i]->get_degats());
				canons_glace[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons_glace[i]->get_cible_runner()->get_HP() <= 0)
			{


				joueur->gagner_argent(canons_glace[i]->get_cible_runner()->get_pieces());
				std::cout << "Vous venez de gagner " << canons_glace[i]->get_cible_runner()->get_pieces() << " coins" << std::endl;

				sprites_runners[canons_glace[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons_glace[i]->set_cible_runner(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons_glace[i]->get_cible_runner() != NULL) {
				sf::Vector2i position_canon = canons_glace[i]->get_position();
				sf::Vector2i position_mob = canons_glace[i]->get_cible_runner()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons_glace[i]->get_portee()) {
					canons_glace[i]->set_cible_runner(NULL);
				}
			}
		}
		if (canons_glace[i]->get_cible_tank() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons_glace[i]->increment_compteur_attaque();
			if (canons_glace[i]->get_compteur_attaque() >= (60 / canons_glace[i]->get_coup_par_seconde())) {
				canons_glace[i]->get_cible_tank()->prendre_degats(canons_glace[i]->get_degats());
				canons_glace[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons_glace[i]->get_cible_tank()->get_HP() <= 0)
			{


				joueur->gagner_argent(canons_glace[i]->get_cible_tank()->get_pieces());
				std::cout << "Vous venez de gagner " << canons_glace[i]->get_cible_tank()->get_pieces() << " coins" << std::endl;

				sprites_tanks[canons_glace[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons_glace[i]->set_cible_tank(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons_glace[i]->get_cible_tank() != NULL) {
				sf::Vector2i position_canon = canons_glace[i]->get_position();
				sf::Vector2i position_mob = canons_glace[i]->get_cible_tank()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons_glace[i]->get_portee()) {
					canons_glace[i]->set_cible_tank(NULL);
				}
			}
		}
		if (canons_glace[i]->get_cible_mage() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons_glace[i]->increment_compteur_attaque();
			if (canons_glace[i]->get_compteur_attaque() >= (60 / canons_glace[i]->get_coup_par_seconde())) {
				canons_glace[i]->get_cible_mage()->prendre_degats(canons_glace[i]->get_degats());
				canons_glace[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons_glace[i]->get_cible_mage()->get_HP() <= 0)
			{


				joueur->gagner_argent(canons_glace[i]->get_cible_mage()->get_pieces());
				std::cout << "Vous venez de gagner " << canons_glace[i]->get_cible_mage()->get_pieces() << " coins" << std::endl;

				sprites_mages[canons_glace[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons_glace[i]->set_cible_mage(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons_glace[i]->get_cible_mage() != NULL) {
				sf::Vector2i position_canon = canons_glace[i]->get_position();
				sf::Vector2i position_mob = canons_glace[i]->get_cible_mage()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons_glace[i]->get_portee()) {
					canons_glace[i]->set_cible_mage(NULL);
				}
			}
		}

	}

	//comme pour le canon
	for (int i = 0; i < mortiers.size(); i++)
	{
		//on verifie que la tour ait une cible
		if (mortiers[i]->get_cible_zombie() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			mortiers[i]->increment_compteur_attaque();
			if (mortiers[i]->get_compteur_attaque() >= (60 / mortiers[i]->get_coup_par_seconde())) {
				mortiers[i]->get_cible_zombie()->prendre_degats(mortiers[i]->get_degats());
				mortiers[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (mortiers[i]->get_cible_zombie()->get_HP() <= 0)
			{


				joueur->gagner_argent(mortiers[i]->get_cible_zombie()->get_pieces());
				std::cout << "Vous venez de gagner " << mortiers[i]->get_cible_zombie()->get_pieces() << " coins" << std::endl;

				sprites_zombies[mortiers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				mortiers[i]->set_cible_zombie(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (mortiers[i]->get_cible_zombie() != NULL) {
				sf::Vector2i position_canon = mortiers[i]->get_position();
				sf::Vector2i position_mob = mortiers[i]->get_cible_zombie()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > mortiers[i]->get_portee()) {
					mortiers[i]->set_cible_zombie(NULL);
				}
			}
		}
		if (mortiers[i]->get_cible_runner() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			mortiers[i]->increment_compteur_attaque();
			if (mortiers[i]->get_compteur_attaque() >= (60 / mortiers[i]->get_coup_par_seconde())) {
				mortiers[i]->get_cible_runner()->prendre_degats(mortiers[i]->get_degats());
				mortiers[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (mortiers[i]->get_cible_runner()->get_HP() <= 0)
			{


				joueur->gagner_argent(mortiers[i]->get_cible_runner()->get_pieces());
				std::cout << "Vous venez de gagner " << mortiers[i]->get_cible_runner()->get_pieces() << " coins" << std::endl;

				sprites_runners[mortiers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				mortiers[i]->set_cible_runner(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (mortiers[i]->get_cible_runner() != NULL) {
				sf::Vector2i position_canon = mortiers[i]->get_position();
				sf::Vector2i position_mob = mortiers[i]->get_cible_runner()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > mortiers[i]->get_portee()) {
					mortiers[i]->set_cible_runner(NULL);
				}
			}
		}
		if (mortiers[i]->get_cible_tank() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			mortiers[i]->increment_compteur_attaque();
			if (mortiers[i]->get_compteur_attaque() >= (60 / mortiers[i]->get_coup_par_seconde())) {
				mortiers[i]->get_cible_tank()->prendre_degats(mortiers[i]->get_degats());
				mortiers[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (mortiers[i]->get_cible_tank()->get_HP() <= 0)
			{


				joueur->gagner_argent(mortiers[i]->get_cible_tank()->get_pieces());
				std::cout << "Vous venez de gagner " << mortiers[i]->get_cible_tank()->get_pieces() << " coins" << std::endl;

				sprites_tanks[mortiers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				mortiers[i]->set_cible_tank(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (mortiers[i]->get_cible_tank() != NULL) {
				sf::Vector2i position_canon = mortiers[i]->get_position();
				sf::Vector2i position_mob = mortiers[i]->get_cible_tank()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > mortiers[i]->get_portee()) {
					mortiers[i]->set_cible_tank(NULL);
				}
			}
		}
		if (mortiers[i]->get_cible_mage() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			mortiers[i]->increment_compteur_attaque();
			if (mortiers[i]->get_compteur_attaque() >= (60 / mortiers[i]->get_coup_par_seconde())) {
				mortiers[i]->get_cible_mage()->prendre_degats(mortiers[i]->get_degats());
				mortiers[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (mortiers[i]->get_cible_mage()->get_HP() <= 0)
			{


				joueur->gagner_argent(mortiers[i]->get_cible_mage()->get_pieces());
				std::cout << "Vous venez de gagner " << mortiers[i]->get_cible_mage()->get_pieces() << " coins" << std::endl;

				sprites_mages[mortiers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				mortiers[i]->set_cible_mage(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (mortiers[i]->get_cible_mage() != NULL) {
				sf::Vector2i position_canon = mortiers[i]->get_position();
				sf::Vector2i position_mob = mortiers[i]->get_cible_mage()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > mortiers[i]->get_portee()) {
					mortiers[i]->set_cible_mage(NULL);
				}
			}
		}

	}

	//comme pour le canon
	for (int i = 0; i < archers.size(); i++)
	{
		//on verifie que la tour ait une cible
		if (archers[i]->get_cible_zombie() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			archers[i]->increment_compteur_attaque();
			if (archers[i]->get_compteur_attaque() >= (60 / archers[i]->get_coup_par_seconde())) {
				archers[i]->get_cible_zombie()->prendre_degats(archers[i]->get_degats());
				archers[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (archers[i]->get_cible_zombie()->get_HP() <= 0)
			{


				joueur->gagner_argent(archers[i]->get_cible_zombie()->get_pieces());
				std::cout << "Vous venez de gagner " << archers[i]->get_cible_zombie()->get_pieces() << " coins" << std::endl;

				sprites_zombies[archers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				archers[i]->set_cible_zombie(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (archers[i]->get_cible_zombie() != NULL) {
				sf::Vector2i position_canon = archers[i]->get_position();
				sf::Vector2i position_mob = archers[i]->get_cible_zombie()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > archers[i]->get_portee()) {
					archers[i]->set_cible_zombie(NULL);
				}
			}
		}
		if (archers[i]->get_cible_runner() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			archers[i]->increment_compteur_attaque();
			if (archers[i]->get_compteur_attaque() >= (60 / archers[i]->get_coup_par_seconde())) {
				archers[i]->get_cible_runner()->prendre_degats(archers[i]->get_degats());
				archers[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (archers[i]->get_cible_runner()->get_HP() <= 0)
			{


				joueur->gagner_argent(archers[i]->get_cible_runner()->get_pieces());
				std::cout << "Vous venez de gagner " << archers[i]->get_cible_runner()->get_pieces() << " coins" << std::endl;

				sprites_runners[archers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				archers[i]->set_cible_runner(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (archers[i]->get_cible_runner() != NULL) {
				sf::Vector2i position_canon = archers[i]->get_position();
				sf::Vector2i position_mob = archers[i]->get_cible_runner()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > archers[i]->get_portee()) {
					archers[i]->set_cible_runner(NULL);
				}
			}
		}
		if (archers[i]->get_cible_tank() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			archers[i]->increment_compteur_attaque();
			if (archers[i]->get_compteur_attaque() >= (60 / archers[i]->get_coup_par_seconde())) {
				archers[i]->get_cible_tank()->prendre_degats(archers[i]->get_degats());
				archers[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (archers[i]->get_cible_tank()->get_HP() <= 0)
			{


				joueur->gagner_argent(archers[i]->get_cible_tank()->get_pieces());
				std::cout << "Vous venez de gagner " << archers[i]->get_cible_tank()->get_pieces() << " coins" << std::endl;

				sprites_tanks[archers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				archers[i]->set_cible_tank(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (archers[i]->get_cible_tank() != NULL) {
				sf::Vector2i position_canon = archers[i]->get_position();
				sf::Vector2i position_mob = archers[i]->get_cible_tank()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > archers[i]->get_portee()) {
					archers[i]->set_cible_tank(NULL);
				}
			}
		}
		if (archers[i]->get_cible_mage() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			archers[i]->increment_compteur_attaque();
			if (archers[i]->get_compteur_attaque() >= (60 / archers[i]->get_coup_par_seconde())) {
				archers[i]->get_cible_mage()->prendre_degats(archers[i]->get_degats());
				archers[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (archers[i]->get_cible_mage()->get_HP() <= 0)
			{


				joueur->gagner_argent(archers[i]->get_cible_mage()->get_pieces());
				std::cout << "Vous venez de gagner " << archers[i]->get_cible_mage()->get_pieces() << " coins" << std::endl;

				sprites_mages[archers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				archers[i]->set_cible_mage(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (archers[i]->get_cible_mage() != NULL) {
				sf::Vector2i position_canon = archers[i]->get_position();
				sf::Vector2i position_mob = archers[i]->get_cible_mage()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > archers[i]->get_portee()) {
					archers[i]->set_cible_mage(NULL);
				}
			}
		}
	}
}