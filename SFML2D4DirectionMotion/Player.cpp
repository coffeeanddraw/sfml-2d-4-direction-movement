#include "Player.h"

Player::Player(std::string texture, sf::Vector2f position) {
	m_position = position;
	m_texture.loadFromFile(texture);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setPosition(m_position);
}

Player::~Player() {}