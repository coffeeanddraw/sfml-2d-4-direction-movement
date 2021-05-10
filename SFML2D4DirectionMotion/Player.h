#pragma once
#include <SFML/Graphics.hpp>

class Player {

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;


	float m_speed = 500.0f;

	bool m_movingRight = false;
	bool m_movingLeft = false;
	bool m_movingUp = false;
	bool m_movingDown = false;
};
