#include <Book/GameState.hpp>


GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mWorld(*context.window)
, mPlayer(*context.player)
{
}

void GameState::draw()
{
	mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
	mWorld.update(dt);

	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleRealtimeInput(commands);

	return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
	// Game input handling
	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleEvent(event, commands);

	// Escape pressed, trigger the pause screen
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(States::Pause);

	return true;
}