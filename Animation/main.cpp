#include <SFML/graphics.hpp>
#include<iostream>
#include "Animation.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux_from_linux.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2u(3, 9), 0.3f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {

		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;

		while (window.pollEvent(evnt)) {

			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear(sf::Color(150,150,150));//used to clear draw buffer before drawing again
		window.draw(player);// used to draw somehting to draw buffer
		window.display();//used to draw the draw buffer to display buffer


	}
	return 0;
}