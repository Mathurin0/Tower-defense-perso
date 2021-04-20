


void ecran_loose()
{

	while (window.isOpen())
	{
	

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.setTitle("FC-Fiak | You loose");

		sf::Text text_loose;

		if (!font.loadFromFile("ressources/Hiatus.ttf"))
		{
			std::cout << "Erreur du chargement de la police" << std::endl;
		}



		if (loose_screen == 1)
		{

			sf::Texture loose_1;
			sf::Sprite sprite_loose_1;
			if (!loose_1.loadFromFile("ressources/img/loose_1.png"))
			{
				std::cout << "Erreur de chargement de l'image loose 1" << std::endl;
			}
			sprite_loose_1.setTexture(loose_1);
			loose_1.setSmooth(true);
			sprite_loose_1.setPosition(600, 69);
			window.draw(sprite_loose_1);

		}

		if (loose_screen == 2)
		{

			sf::Texture loose_2;
			sf::Sprite sprite_loose_2;
			if (!loose_2.loadFromFile("ressources/img/loose_2.png"))
			{
				std::cout << "Erreur de chargement de l'image loose 2" << std::endl;
			}
			sprite_loose_2.setTexture(loose_2);
			loose_2.setSmooth(true);
			sprite_loose_2.setPosition(666, 69);
			window.draw(sprite_loose_2);

		}

		if (loose_screen == 3)
		{

			sf::Texture loose_3;
			sf::Sprite sprite_loose_3;
			if (!loose_3.loadFromFile("ressources/img/loose_3.png"))
			{
				std::cout << "Erreur de chargement de l'image loose 3" << std::endl;
			}
			sprite_loose_3.setTexture(loose_3);
			loose_3.setSmooth(true);
			sprite_loose_3.setPosition(600, 69);
			window.draw(sprite_loose_3);

		}

		if (loose_screen == 4)
		{

			sf::Texture loose_4;
			sf::Sprite sprite_loose_4;
			if (!loose_4.loadFromFile("ressources/img/loose_4.png"))
			{
				std::cout << "Erreur de chargement de l'image loose 4" << std::endl;
			}
			sprite_loose_4.setTexture(loose_4);
			loose_4.setSmooth(true);
			sprite_loose_4.setPosition(550, 69);
			window.draw(sprite_loose_4);

		}
		if (loose_screen == 5)
		{

			sf::Texture loose_5;
			sf::Sprite sprite_loose_5;
			if (!loose_5.loadFromFile("ressources/img/loose_5.png"))
			{
				std::cout << "Erreur de chargement de l'image loose 5" << std::endl;
			}
			sprite_loose_5.setTexture(loose_5);
			loose_5.setSmooth(true);
			sprite_loose_5.setPosition(666, 69);
			window.draw(sprite_loose_5);

		}
		if (loose_screen == 6)
		{

			sf::Texture loose_6;
			sf::Sprite sprite_loose_6;
			if (!loose_6.loadFromFile("ressources/img/loose_6.png"))
			{
				std::cout << "Erreur de chargement de l'image loose 6" << std::endl;
			}
			sprite_loose_6.setTexture(loose_6);
			loose_6.setSmooth(true);
			sprite_loose_6.setPosition(666, 69);
			window.draw(sprite_loose_6);

		}
		if (loose_screen == 7)
		{

			sf::Texture loose_7;
			sf::Sprite sprite_loose_7;
			if (!loose_7.loadFromFile("ressources/img/loose_7.png"))
			{
				std::cout << "Erreur de chargement de l'image loose 7" << std::endl;
			}
			sprite_loose_7.setTexture(loose_7);
			loose_7.setSmooth(true);
			sprite_loose_7.setPosition(500, 79);
			window.draw(sprite_loose_7);

		}


		text_loose.setString("Vous avez perdu !");
		text_loose.setFont(font);
		text_loose.setCharacterSize(50);
		text_loose.setPosition(666, 666);
		window.draw(text_loose);


		window.display();
		window.clear();

	}
}