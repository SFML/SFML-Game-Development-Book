#ifndef BOOK_TITLESTATE_HPP
#define BOOK_TITLESTATE_HPP

#include <Book/State.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class TitleState : public State
{
	public:
							TitleState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mText;

		bool				mShowText;
		sf::Time			mTextEffectTime;
};

#endif // BOOK_TITLESTATE_HPP
