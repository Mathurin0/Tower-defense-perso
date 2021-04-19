

void attaque() {
	for (int i = 0; i < canons.size(); i++)
	{
		if (canons[i]->get_cible() != NULL)
		{
			canons[i]->increment_compteur_attaque();
			if (canons[i]->get_compteur_attaque() >= (60 / canons[i]->get_coup_par_seconde())) {
				if (canons[i]->get_cible() != NULL) {
					canons[i]->get_cible()->prendre_degats(canons[i]->get_degats());
					canons[i]->reset_compteur_attaque();
				}
			}
			if (canons[i]->get_cible()->get_HP() <= 0) {
				joueur->gagner_argent(canons[i]->get_cible()->get_pieces());
				sprites_zombies[canons[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons[i]->set_cible(NULL);
			}
		}
	}

	for (int i = 0; i < canons_glace.size(); i++)
	{
		if (canons_glace[i]->get_cible() != NULL)
		{
			canons_glace[i]->increment_compteur_attaque();
			if (canons_glace[i]->get_compteur_attaque() >= (60 / canons_glace[i]->get_coup_par_seconde())) {
				canons_glace[i]->get_cible()->prendre_degats(canons_glace[i]->get_degats());
				canons_glace[i]->reset_compteur_attaque();
			}
			if (canons_glace[i]->get_cible()->get_HP() <= 0) {
				joueur->gagner_argent(canons_glace[i]->get_cible()->get_pieces());
				sprites_zombies[canons_glace[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				canons_glace[i]->set_cible(NULL);
			}
		}

	}

	for (int i = 0; i < mortiers.size(); i++)
	{
		if (mortiers[i]->get_cible() != NULL)
		{
			mortiers[i]->increment_compteur_attaque();
			if (mortiers[i]->get_compteur_attaque() >= (60 / mortiers[i]->get_coup_par_seconde())) {
				mortiers[i]->get_cible()->prendre_degats(mortiers[i]->get_degats());
				mortiers[i]->reset_compteur_attaque();
			}
			if (mortiers[i]->get_cible()->get_HP() <= 0) {
				joueur->gagner_argent(mortiers[i]->get_cible()->get_pieces());
				sprites_zombies[mortiers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				mortiers[i]->set_cible(NULL);
			}
		}

	}

	for (int i = 0; i < archers.size(); i++)
	{
		if (archers[i]->get_cible() != NULL)
		{
			archers[i]->increment_compteur_attaque();
			if (archers[i]->get_compteur_attaque() >= (60 / archers[i]->get_coup_par_seconde())) {
				archers[i]->get_cible()->prendre_degats(archers[i]->get_degats());
				archers[i]->reset_compteur_attaque();
			}
			if (archers[i]->get_cible()->get_HP() <= 0) {
				joueur->gagner_argent(archers[i]->get_cible()->get_pieces());
				sprites_zombies[archers[i]->get_position_ennemi()].setColor(sf::Color::Transparent);
				archers[i]->set_cible(NULL);
			}
		}
	}
}