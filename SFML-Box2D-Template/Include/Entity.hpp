#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Game;
class Entity
{
public:
	Entity(const sf::Vector2f& position, Game* game);

	virtual void handleInput() = 0;
	virtual void update(sf::Time delta) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	sf::Sprite& getSprite() { return sprite_; }
	float getX() const { return getPosition().x; }
	float getY() const { return getPosition().y; }
	const sf::Sprite& getSprite() const { return sprite_; }
	float getWidth() const { return sprite_.getGlobalBounds().width; }
	float getHeight() const { return sprite_.getGlobalBounds().height; }
	sf::Vector2f getPosition() const { return sprite_.getPosition(); }
	sf::FloatRect getLocalBounds() const { return sprite_.getLocalBounds(); }
	sf::FloatRect getGlobalBounds() const { return sprite_.getGlobalBounds(); }

protected:
	Game* game_;
	sf::Sprite sprite_;
};

#endif