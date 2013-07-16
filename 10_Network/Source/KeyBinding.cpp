#include <Book/KeyBinding.hpp>
#include <Book/Foreach.hpp>

#include <string>
#include <algorithm>


KeyBinding::KeyBinding(int controlPreconfiguration)
: mKeyMap()
{
	// Set initial key bindings for player 1
	if (controlPreconfiguration == 1)
	{
		mKeyMap[sf::Keyboard::Left]	 = PlayerAction::MoveLeft;
		mKeyMap[sf::Keyboard::Right] = PlayerAction::MoveRight;
		mKeyMap[sf::Keyboard::Up]    = PlayerAction::MoveUp;
		mKeyMap[sf::Keyboard::Down]  = PlayerAction::MoveDown;
		mKeyMap[sf::Keyboard::Space] = PlayerAction::Fire;
		mKeyMap[sf::Keyboard::M]     = PlayerAction::LaunchMissile;
	}
	else if (controlPreconfiguration == 2)
	{
		// Player 2
		mKeyMap[sf::Keyboard::A] = PlayerAction::MoveLeft;
		mKeyMap[sf::Keyboard::D] = PlayerAction::MoveRight;
		mKeyMap[sf::Keyboard::W] = PlayerAction::MoveUp;
		mKeyMap[sf::Keyboard::S] = PlayerAction::MoveDown;
		mKeyMap[sf::Keyboard::F] = PlayerAction::Fire;
		mKeyMap[sf::Keyboard::R] = PlayerAction::LaunchMissile;
	}
}

void KeyBinding::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyMap.begin(); itr != mKeyMap.end(); )
	{
		if (itr->second == action)
			mKeyMap.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyMap[key] = action;
}

sf::Keyboard::Key KeyBinding::getAssignedKey(Action action) const
{
	FOREACH(auto pair, mKeyMap)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

bool KeyBinding::checkAction(sf::Keyboard::Key key, Action& out) const
{
	auto found = mKeyMap.find(key);
	if (found == mKeyMap.end())
	{
		return false;
	}
	else
	{
		out = found->second;
		return true;
	}
}

std::vector<KeyBinding::Action> KeyBinding::getRealtimeActions() const
{
	// Return all realtime actions that are currently active.
	std::vector<Action> actions;

	FOREACH(auto pair, mKeyMap)
	{
		// If key is pressed and an action is a realtime action, store it
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			actions.push_back(pair.second);
	}

	return actions;
}

bool isRealtimeAction(PlayerAction::Type action)
{
	switch (action)
	{
		case PlayerAction::MoveLeft:
		case PlayerAction::MoveRight:
		case PlayerAction::MoveDown:
		case PlayerAction::MoveUp:
		case PlayerAction::Fire:
			return true;

		default:
			return false;
	}
}