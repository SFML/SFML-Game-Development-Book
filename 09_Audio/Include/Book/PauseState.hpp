#ifndef BOOK_PAUSESTATE_HPP
#define BOOK_PAUSESTATE_HPP

#include <Book/State.hpp>
#include <Book/Container.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class PauseState : public State
{
	public:
							PauseState(StateStack& stack, Context context);
							~PauseState();

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mPausedText;
		GUI::Container 		mGUIContainer;
};

#endif // BOOK_PAUSESTATE_HPP