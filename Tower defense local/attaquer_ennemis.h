
//fonction d'attaque des ennemis par les tours
void attaque() {

	//on parcours le tableau canons
	for (int i = 0; i < canons.size(); i++)
	{
		//on verifie que la tour ait une cible
		if (canons[i]->get_cible() != NULL)
		{
			//le compteur_attaque permet de controler le temps entre deux attaques
			canons[i]->increment_compteur_attaque();
			if (canons[i]->get_compteur_attaque() >= (60 / canons[i]->get_coup_par_seconde())) {
				canons[i]->get_cible()->prendre_degats(canons[i]->get_degats());
				canons[i]->reset_compteur_attaque();
			}
			//si l'ennemi est mort, on recupère la money et on tue le zombie
			if (canons[i]->get_cible()->get_HP() <= 0)
			{
				joueur->gagner_argent(canons[i]->get_cible()->get_pieces());
				sprites_zombies[canons[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons[i]->set_cible(NULL);
			}
			//on verifie si l'ennemi est a portee
			if (canons[i]->get_cible() != NULL) {
				sf::Vector2i position_canon = canons[i]->get_position();
				sf::Vector2i position_mob = canons[i]->get_cible()->get_position();
				int y_tour = position_canon.y;
				int x_tour = position_canon.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons[i]->get_portee()) {
					canons[i]->set_cible(NULL);
				}
			}
		}
	}

	//comme pour le canon
	for (int i = 0; i < canons_glace.size(); i++)
	{
		if (canons_glace[i]->get_cible() != NULL)
		{
			canons_glace[i]->increment_compteur_attaque();
			if (canons_glace[i]->get_compteur_attaque() >= (60 / canons_glace[i]->get_coup_par_seconde())) {
				canons_glace[i]->get_cible()->prendre_degats(canons_glace[i]->get_degats());
				canons_glace[i]->reset_compteur_attaque();
			} 
			if (canons_glace[i]->get_cible()->get_HP() <= 0)
			{
				joueur->gagner_argent(canons_glace[i]->get_cible()->get_pieces());
				sprites_zombies[canons_glace[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons_glace[i]->set_cible(NULL);
			}
			if (canons_glace[i]->get_cible() != NULL) {
				sf::Vector2i position_canons_glace = canons_glace[i]->get_position();
				sf::Vector2i position_mob = canons_glace[i]->get_cible()->get_position();
				int y_tour = position_canons_glace.y;
				int x_tour = position_canons_glace.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > canons_glace[i]->get_portee()) {
					canons_glace[i]->set_cible(NULL);
				} 
			}
		}

	}

	//comme pour le canon
	for (int i = 0; i < mortiers.size(); i++)
	{
		if (mortiers[i]->get_cible() != NULL)
		{
			mortiers[i]->increment_compteur_attaque();
			if (mortiers[i]->get_compteur_attaque() >= (60 / mortiers[i]->get_coup_par_seconde())) {
				mortiers[i]->get_cible()->prendre_degats(mortiers[i]->get_degats());
				mortiers[i]->reset_compteur_attaque();
			} 
			if (mortiers[i]->get_cible()->get_HP() <= 0)
			{
				joueur->gagner_argent(mortiers[i]->get_cible()->get_pieces());
				sprites_zombies[mortiers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				mortiers[i]->set_cible(NULL);
			}
			if (mortiers[i]->get_cible() != NULL) {
				sf::Vector2i position_mortier = mortiers[i]->get_position();
				sf::Vector2i position_mob = mortiers[i]->get_cible()->get_position();
				int y_tour = position_mortier.y;
				int x_tour = position_mortier.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > mortiers[i]->get_portee()) {
					mortiers[i]->set_cible(NULL);
				} 
			}
		}

	}

	//comme pour le canon
	for (int i = 0; i < archers.size(); i++)
	{
		if (archers[i]->get_cible() != NULL)
		{
			archers[i]->increment_compteur_attaque();
			if (archers[i]->get_compteur_attaque() >= (60 / archers[i]->get_coup_par_seconde())) {
				archers[i]->get_cible()->prendre_degats(archers[i]->get_degats());
				archers[i]->reset_compteur_attaque();
			}
			if (archers[i]->get_cible()->get_HP() <= 0)
			{
				joueur->gagner_argent(archers[i]->get_cible()->get_pieces());
				sprites_zombies[archers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				archers[i]->set_cible(NULL);
			}
			if (archers[i]->get_cible() != NULL) {
				sf::Vector2i position_archers = archers[i]->get_position();
				sf::Vector2i position_mob = archers[i]->get_cible()->get_position();
				int y_tour = position_archers.y;
				int x_tour = position_archers.x;
				int y_mob = position_mob.y;
				int x_mob = position_mob.x;
				int distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
				if (distance > archers[i]->get_portee()) {
					archers[i]->set_cible(NULL);
				}
			}
		}
	}
}