#include "Player.h"

Player::Player(std::string texture, sf::Vector2f position) {
	m_position = position;
	m_texture.loadFromFile(texture);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setPosition(m_position);
}

Player::~Player() {}

sf::Sprite Player::getSprite() {
	return m_sprite;
}

void Player::goLeft() {
	m_movingLeft = true;
}

void Player::goRight() {
	m_movingRight = true;
}

void Player::stopLeft() {
	m_movingLeft = false;
}

void Player::stopRight() {
	m_movingRight = false;
}

void Player::goUp() {
	m_movingUp = true;
}

void Player::stopUp() {
	m_movingUp = false;
}

void Player::goDown() {
	m_movingDown = true;
}

void Player::stopDown() {
	m_movingDown = false;
}

void Player::update(sf::Time t, sf::Vector2f windowSize) {
	if (m_movingLeft) {
		if ((m_sprite.getPosition().x - (m_texture.getSize().x / 2) > 0)) {
			m_position.x -= m_speed * t.asSeconds();
		}
		else {
			m_movingLeft = false;
		}
	}
	else if (m_movingRight) {
		if (m_sprite.getPosition().x + (m_texture.getSize().x / 2) < windowSize.x) {
			m_position.x += m_speed * t.asSeconds();
		}
		else {
			m_movingRight = false;
		}
	}
	else if (m_movingUp) {
		if ((m_sprite.getPosition().y - (m_texture.getSize().y / 2) > 0)) {
			m_position.y -= m_speed * t.asSeconds();
		}
		else {
			m_movingDown = false;
		}
	}
	else if (m_movingDown) {
		if (m_sprite.getPosition().y + (m_texture.getSize().y / 2) < windowSize.y) {
			m_position.y += m_speed * t.asSeconds();
		}
		else {
			m_movingUp = false;
		}
	}
	m_sprite.setPosition(m_position);
}