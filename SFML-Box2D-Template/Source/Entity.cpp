#include "../Include/Entity.hpp"
#include "../Include/Game.hpp"

Entity::Entity(const sf::Vector2f& position, Game* game)
	: game_(game)
{
	sprite_.setPosition(position);
}