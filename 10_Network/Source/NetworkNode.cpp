#include <Book/NetworkNode.hpp>
#include <Book/NetworkProtocol.hpp>


NetworkNode::NetworkNode()
: SceneNode()
, mPendingActions()
{
}

unsigned int NetworkNode::getCategory() const
{
	return Category::Network;
}

void NetworkNode::notifyGameAction(GameActions::Type type, sf::Vector2f position)
{
	mPendingActions.push(GameActions::Action(type, position));
}

bool NetworkNode::pollGameAction(GameActions::Action& out)
{
	if (mPendingActions.empty())
	{
		return false;
	}
	else
	{
		out = mPendingActions.front();
		mPendingActions.pop();
		return true;
	}
}
