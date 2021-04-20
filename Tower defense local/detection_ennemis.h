
//fonction de detection des ennemis par les tours
void detection() {
	int taille_zombie = zombies.size();
	int taille_runner = runners.size();
	int taille_tank = tanks.size();
	int taille_mage = mages.size();
	int distance = 0;
	int y_tour = 0;
	int x_tour = 0;
	int y_mob = 0;
	int x_mob = 0;
	int distance_min = 0;

	//boucle for pour verifier tous les canons
	int taille_tour = canons.size();
	for (int i = 0; i < taille_tour; i++) {
		//on recherche une cible seulement si la tour n'en a pas
		if (canons[i]->get_cible_zombie() == NULL && canons[i]->get_cible_runner() == NULL && canons[i]->get_cible_tank() == NULL && canons[i]->get_cible_mage() == NULL)
		{
			distance_min = 1000;
			//boucle for pour verifier tous les zombies
			for (int j = 0; j < taille_zombie; j++) {
				//on vérifie que le zombie soit vivant pour le prendre pour cible
				if (zombies[j]->get_HP() > 0)
				{
					sf::Vector2i position_canon = canons[i]->get_position();
					sf::Vector2i position_mob = zombies[j]->get_position();
					y_tour = position_canon.y;
					x_tour = position_canon.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					//on vérifie que le zombie soit dans le rayon d'action de la tour
					if (distance <= canons[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						canons[i]->set_cible_zombie(zombies[j]);
						canons[i]->set_cible_runner(NULL);
						canons[i]->set_cible_tank(NULL);
						canons[i]->set_cible_mage(NULL);
						canons[i]->set_position_ennemi(j);
					}
				}

			}
			//comme pour les zombies
			for (int j = 0; j < taille_runner; j++) {
				if (runners[j]->get_HP() > 0)
				{
					sf::Vector2i position_canon = canons[i]->get_position();
					sf::Vector2i position_mob = runners[j]->get_position();
					y_tour = position_canon.y;
					x_tour = position_canon.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= canons[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						canons[i]->set_cible_runner(runners[j]);
						canons[i]->set_cible_zombie(NULL);
						canons[i]->set_cible_tank(NULL);
						canons[i]->set_cible_mage(NULL);
						canons[i]->set_position_ennemi(j);
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_tank; j++) {
				if (tanks[j]->get_HP() > 0)
				{
					sf::Vector2i position_canon = canons[i]->get_position();
					sf::Vector2i position_mob = tanks[j]->get_position();
					y_tour = position_canon.y;
					x_tour = position_canon.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= canons[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						canons[i]->set_cible_tank(tanks[j]);
						canons[i]->set_cible_zombie(NULL);
						canons[i]->set_cible_runner(NULL);
						canons[i]->set_cible_mage(NULL);
						canons[i]->set_position_ennemi(j);
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_mage; j++) {
				if (mages[j]->get_HP() > 0)
				{
					sf::Vector2i position_canon = canons[i]->get_position();
					sf::Vector2i position_mob = mages[j]->get_position();
					y_tour = position_canon.y;
					x_tour = position_canon.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= canons[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						canons[i]->set_cible_mage(mages[j]);
						canons[i]->set_cible_zombie(NULL);
						canons[i]->set_cible_runner(NULL);
						canons[i]->set_cible_tank(NULL);
						canons[i]->set_position_ennemi(j);
					}
				}
			}
			//si aucun ennemi n'a été détecté, on met NULL en cible
			if (distance_min == 1000) {
				canons[i]->set_cible_zombie(NULL);
				canons[i]->set_cible_runner(NULL);
				canons[i]->set_cible_tank(NULL);
				canons[i]->set_cible_mage(NULL);
			}
		}

	}

	//boucle for pour verifier tous les canons de glace
	taille_tour = canons_glace.size();
	for (int i = 0; i < taille_tour; i++) {
		//comme pour les canons
		if (canons_glace[i]->get_cible_zombie() == NULL && canons_glace[i]->get_cible_runner() == NULL && canons_glace[i]->get_cible_tank() == NULL && canons_glace[i]->get_cible_mage() == NULL)
		{
			distance_min = 1000;
			for (int j = 0; j < taille_zombie; j++) {
				if (zombies[j] != NULL)
				{
					if (zombies[j]->get_HP() > 0)
					{
						sf::Vector2i position_canon_glace = canons_glace[i]->get_position();
						sf::Vector2i position_mob = zombies[j]->get_position();
						y_tour = position_canon_glace.y;
						x_tour = position_canon_glace.x;
						y_mob = position_mob.y;
						x_mob = position_mob.x;
						distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
						if (distance <= canons_glace[i]->get_portee() && distance < distance_min) {
							distance_min = distance;
							canons_glace[i]->set_cible_zombie(zombies[j]);
							canons_glace[i]->set_cible_runner(NULL);
							canons_glace[i]->set_cible_tank(NULL);
							canons_glace[i]->set_cible_mage(NULL);
							canons_glace[i]->set_position_ennemi(j);
						}
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_runner; j++) {
				if (runners[j]->get_HP() > 0)
				{
					sf::Vector2i position_canon_glace = canons_glace[i]->get_position();
					sf::Vector2i position_mob = runners[j]->get_position();
					y_tour = position_canon_glace.y;
					x_tour = position_canon_glace.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= canons_glace[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						canons_glace[i]->set_cible_runner(runners[j]);
						canons_glace[i]->set_cible_zombie(NULL);
						canons_glace[i]->set_cible_tank(NULL);
						canons_glace[i]->set_cible_mage(NULL);
						canons_glace[i]->set_position_ennemi(j);
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_tank; j++) {
				if (tanks[j]->get_HP() > 0)
				{
					sf::Vector2i position_canon_glace = canons_glace[i]->get_position();
					sf::Vector2i position_mob = tanks[j]->get_position();
					y_tour = position_canon_glace.y;
					x_tour = position_canon_glace.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= canons_glace[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						canons_glace[i]->set_cible_tank(tanks[j]);
						canons_glace[i]->set_cible_zombie(NULL);
						canons_glace[i]->set_cible_runner(NULL);
						canons_glace[i]->set_cible_mage(NULL);
						canons_glace[i]->set_position_ennemi(j);
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_mage; j++) {
				if (mages[j]->get_HP() > 0)
				{
					sf::Vector2i position_canon_glace = canons_glace[i]->get_position();
					sf::Vector2i position_mob = mages[j]->get_position();
					y_tour = position_canon_glace.y;
					x_tour = position_canon_glace.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= canons_glace[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						canons_glace[i]->set_cible_mage(mages[j]);
						canons_glace[i]->set_cible_zombie(NULL);
						canons_glace[i]->set_cible_runner(NULL);
						canons_glace[i]->set_cible_tank(NULL);
						canons_glace[i]->set_position_ennemi(j);
					}
				}
			}
			//si aucun ennemi n'a été détecté, on met NULL en cible
			if (distance_min == 1000) {
				canons_glace[i]->set_cible_zombie(NULL);
				canons_glace[i]->set_cible_runner(NULL);
				canons_glace[i]->set_cible_tank(NULL);
				canons_glace[i]->set_cible_mage(NULL);
			}
		}
	}

	//boucle for pour verifier tous les mortiers
	taille_tour = mortiers.size();
	for (int i = 0; i < taille_tour; i++) {
		//comme pour les canons
		if (mortiers[i]->get_cible_zombie() == NULL && mortiers[i]->get_cible_runner() == NULL && mortiers[i]->get_cible_tank() == NULL && mortiers[i]->get_cible_mage() == NULL)
		{
			distance_min = 1000;
			for (int j = 0; j < taille_zombie; j++) {
				if (zombies[j] != NULL)
				{
					if (zombies[j]->get_HP() > 0)
					{
						sf::Vector2i position_mortier = mortiers[i]->get_position();
						sf::Vector2i position_mob = zombies[j]->get_position();
						y_tour = position_mortier.y;
						x_tour = position_mortier.x;
						y_mob = position_mob.y;
						x_mob = position_mob.x;
						distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
						if (distance <= mortiers[i]->get_portee() && distance < distance_min) {
							distance_min = distance;
							mortiers[i]->set_cible_zombie(zombies[j]);
							mortiers[i]->set_cible_runner(NULL);
							mortiers[i]->set_cible_tank(NULL);
							mortiers[i]->set_cible_mage(NULL);
							mortiers[i]->set_position_ennemi(j);
						}
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_runner; j++) {
				if (runners[j]->get_HP() > 0)
				{
					sf::Vector2i position_mortier = mortiers[i]->get_position();
					sf::Vector2i position_mob = runners[j]->get_position();
					y_tour = position_mortier.y;
					x_tour = position_mortier.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= mortiers[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						mortiers[i]->set_cible_runner(runners[j]);
						mortiers[i]->set_cible_zombie(NULL);
						mortiers[i]->set_cible_tank(NULL);
						mortiers[i]->set_cible_mage(NULL);
						mortiers[i]->set_position_ennemi(j);
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_tank; j++) {
				if (tanks[j]->get_HP() > 0)
				{
					sf::Vector2i position_mortier = mortiers[i]->get_position();
					sf::Vector2i position_mob = tanks[j]->get_position();
					y_tour = position_mortier.y;
					x_tour = position_mortier.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= mortiers[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						mortiers[i]->set_cible_tank(tanks[j]);
						mortiers[i]->set_cible_zombie(NULL);
						mortiers[i]->set_cible_runner(NULL);
						mortiers[i]->set_cible_mage(NULL);
						mortiers[i]->set_position_ennemi(j);
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_mage; j++) {
				if (mages[j]->get_HP() > 0)
				{
					sf::Vector2i position_mortier = mortiers[i]->get_position();
					sf::Vector2i position_mob = mages[j]->get_position();
					y_tour = position_mortier.y;
					x_tour = position_mortier.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= mortiers[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						mortiers[i]->set_cible_mage(mages[j]);
						mortiers[i]->set_cible_zombie(NULL);
						mortiers[i]->set_cible_runner(NULL);
						mortiers[i]->set_cible_tank(NULL);
						mortiers[i]->set_position_ennemi(j);
					}
				}
			}
			//si aucun ennemi n'a été détecté, on met NULL en cible
			if (distance_min == 1000) {
				mortiers[i]->set_cible_zombie(NULL);
				mortiers[i]->set_cible_runner(NULL);
				mortiers[i]->set_cible_tank(NULL);
				mortiers[i]->set_cible_mage(NULL);
			}
		}
	}

	//boucle for pour verifier toutes les tours d'archers
	taille_tour = archers.size();
	for (int i = 0; i < taille_tour; i++) {
		//comme pour les canons
		if (archers[i]->get_cible_zombie() == NULL && archers[i]->get_cible_runner() == NULL && archers[i]->get_cible_tank() == NULL && archers[i]->get_cible_mage() == NULL)
		{
			distance_min = 1000;
			for (int j = 0; j < taille_zombie; j++) {
				if (zombies[j] != NULL)
				{
					if (zombies[j]->get_HP() > 0)
					{
						sf::Vector2i position_archers = archers[i]->get_position();
						sf::Vector2i position_mob = zombies[j]->get_position();
						y_tour = position_archers.y;
						x_tour = position_archers.x;
						y_mob = position_mob.y;
						x_mob = position_mob.x;
						distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
						if (distance <= archers[i]->get_portee() && distance < distance_min) {
							distance_min = distance;
							archers[i]->set_cible_zombie(zombies[j]);
							archers[i]->set_cible_runner(NULL);
							archers[i]->set_cible_tank(NULL);
							archers[i]->set_cible_mage(NULL);
							archers[i]->set_position_ennemi(j);
						}
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_runner; j++) {
				if (runners[j]->get_HP() > 0)
				{
					sf::Vector2i position_archers = archers[i]->get_position();
					sf::Vector2i position_mob = runners[j]->get_position();
					y_tour = position_archers.y;
					x_tour = position_archers.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= archers[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						archers[i]->set_cible_runner(runners[j]);
						archers[i]->set_cible_zombie(NULL);
						archers[i]->set_cible_tank(NULL);
						archers[i]->set_cible_mage(NULL);
						archers[i]->set_position_ennemi(j);
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_tank; j++) {
				if (tanks[j]->get_HP() > 0)
				{
					sf::Vector2i position_archers = archers[i]->get_position();
					sf::Vector2i position_mob = tanks[j]->get_position();
					y_tour = position_archers.y;
					x_tour = position_archers.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= archers[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						archers[i]->set_cible_tank(tanks[j]);
						archers[i]->set_cible_zombie(NULL);
						archers[i]->set_cible_runner(NULL);
						archers[i]->set_cible_mage(NULL);
						archers[i]->set_position_ennemi(j);
					}
				}
			}
			//comme pour les zombies
			for (int j = 0; j < taille_mage; j++) {
				if (mages[j]->get_HP() > 0)
				{
					sf::Vector2i position_archers = archers[i]->get_position();
					sf::Vector2i position_mob = mages[j]->get_position();
					y_tour = position_archers.y;
					x_tour = position_archers.x;
					y_mob = position_mob.y;
					x_mob = position_mob.x;
					distance = sqrt(pow((y_tour - y_mob), 2) + pow((x_tour - x_mob), 2));
					if (distance <= archers[i]->get_portee() && distance < distance_min) {
						distance_min = distance;
						archers[i]->set_cible_mage(mages[j]);
						archers[i]->set_cible_zombie(NULL);
						archers[i]->set_cible_runner(NULL);
						archers[i]->set_cible_tank(NULL);
						archers[i]->set_position_ennemi(j);
					}
				}
			}
			//si aucun ennemi n'a été détecté, on met NULL en cible
			if (distance_min == 1000) {
				archers[i]->set_cible_zombie(NULL);
				archers[i]->set_cible_runner(NULL);
				archers[i]->set_cible_tank(NULL);
				archers[i]->set_cible_mage(NULL);
			}
		}
	}
}