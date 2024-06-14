#pragma once

#include <SFML/Graphics.hpp>

class System
{
	sf::RenderWindow m_window;
	sf::CircleShape m_circle;
	bool m_running = true;

	void init();
	void sUserInput();
	void sRender();

	void spawnPlayer();

public:
	System();
	void run();
};