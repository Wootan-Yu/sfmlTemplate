#include "System.h"

System::System()
{
	init();
}

void System::init()
{
	m_window.create(sf::VideoMode(800, 800), "test");
	m_window.setFramerateLimit(60);

	spawnPlayer();
}

void System::run()
{
	while (m_running)
	{
		sUserInput();
		sRender();
	}
}



void System::sUserInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}
	}
}



void System::spawnPlayer()
{
	m_circle.setFillColor(sf::Color(204, 77, 5));
	m_circle.setPosition(200, 200);
	m_circle.setRadius(200.f);
	m_circle.setPointCount(100);
}

void System::sRender()
{
	m_window.clear(sf::Color(18, 33, 43));

	m_window.draw(m_circle);

	m_window.display();
}
