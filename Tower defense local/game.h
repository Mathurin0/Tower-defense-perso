#pragma once

#define mainloop


class game {
	static game* instance;

	sf::RenderWindow window;
	sf::Event evnt;
	sf::Font font;
	sf::Image icon;


public:

	game(int WIDTH, int HEIGHT);

	~game();

	void run();

	static game* getInstance();
};