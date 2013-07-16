#include <Book/State.hpp>
#include <Book/StateStack.hpp>


State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player, MusicPlayer& music, SoundPlayer& sounds)
: window(&window)
, textures(&textures)
, fonts(&fonts)
, player(&player)
, music(&music)
, sounds(&sounds)
{
}

State::State(StateStack& stack, Context context)
: mStack(&stack)
, mContext(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}

State::Context State::getContext() const
{
	return mContext;
}
