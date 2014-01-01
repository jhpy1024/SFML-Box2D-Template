#include "../Include/Game.hpp"

Game::Game()
	: Width(1280)
	, Height(720)
	, Title("SFML Application")
	, TimePerFrame(sf::seconds(1.f / 60.f))
	, window_(sf::VideoMode(Width, Height), Title)
{

}

void Game::handleInput()
{
	sf::Event event;
	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}

	for (auto& entity : entities_)
		entity->handleInput();
}

void Game::update(sf::Time delta)
{
	for (auto& entity : entities_)
		entity->update(delta);
}

void Game::render()
{
	window_.clear(sf::Color::Red);

	for (auto& entity : entities_)
		entity->render(window_);

	window_.display();
}

void Game::run()
{
	sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window_.isOpen())
    {
		sf::Time delta = clock.restart();
        timeSinceLastUpdate += delta;

        while (timeSinceLastUpdate > TimePerFrame)
        {
			timeSinceLastUpdate -= TimePerFrame;
            handleInput();
            update(TimePerFrame);
        }

        render();
	}
}