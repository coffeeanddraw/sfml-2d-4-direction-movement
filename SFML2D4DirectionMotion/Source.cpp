#include <SFML/Graphics.hpp>

sf::Vector2f windowSize(800, 800);
sf::VideoMode vm(windowSize.x, windowSize.y);
sf::RenderWindow window(vm, "2D 4 Direction Movement");

int main() {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	return 0;
}