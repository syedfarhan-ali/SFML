#include <SFML/graphics.hpp>
#include<iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Cyan);
	player.setOrigin(50.0f,50.0f);

	while (window.isOpen()) {
		sf::Event evnt;

		while (window.pollEvent(evnt)) {

			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//std::cout << "New window width: " << evnt.size.width << std::endl << "New window height: " << evnt.size.height << std::endl;
				printf("New window width : %i\nNew window height: %i\n", evnt.size.width, evnt.size.height);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					printf("%c", evnt.text.unicode);
				}
				break;
			}


		}

		// Keyboard movement code 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.move(-0.1f,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0f, 0.1f);
		}

		//Mouse movement code
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mousePos =	sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, (float)mousePos.y);//static_cast<float>(mousePos.y) is safe - while c style cast -> (float)mousePos.x is not safe
		}

		window.clear();//used to clear draw buffer before drawing again
		window.draw(player);// used to draw somehting to draw buffer
		window.display();//used to draw the draw buffer to display buffer


	}
	return 0;
}
