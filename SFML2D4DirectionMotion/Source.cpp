#include <SFML/Graphics.hpp>
#include "Player.h"

sf::Vector2f windowSize(800, 800);
sf::VideoMode vm(windowSize.x, windowSize.y);
sf::RenderWindow window(vm, "2D 4 Direction Movement");

int main() {
	Player player("graphics/AngryHeartx8.png", sf::Vector2f(windowSize.x / 2, windowSize.y / 2));

	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player.goLeft();
		}
		else {
			player.stopLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player.goRight();
		}
		else {
			player.stopRight();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			player.goUp();
		}
		else {
			player.stopUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			player.goDown();
		}
		else {
			player.stopDown();
		}

		sf::Time t = clock.restart();
		player.update(t, windowSize);

		window.clear();
		window.draw(player.getSprite());
		window.display();
	}
	return 0;
}