#include "System.h"
#include <iostream>

System::System()
{
	init();
}

void System::init()
{
	m_window.create(sf::VideoMode(800, 800), "test");
	m_window.setFramerateLimit(60);

	spawnPlayer();

	if (!m_font.loadFromFile("fonts/Tech.ttf"))
	{
		std::cout << "could not load font!\n";
		exit(-1);
	}

	m_text.setString("Test");
	m_text.setFont(m_font);
	m_text.setCharacterSize(25);
	m_text.setFillColor(sf::Color::White);
	m_text.setPosition(10.f, 20.f);
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

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Q:
				m_running = false;
				break;
			}
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

	m_window.draw(m_text);
	m_window.draw(m_circle);

	m_window.display();
}

