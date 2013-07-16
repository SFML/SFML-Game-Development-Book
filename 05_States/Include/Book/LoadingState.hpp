#ifndef BOOK_LOADINGSTATE_HPP
#define BOOK_LOADINGSTATE_HPP

#include <Book/State.hpp>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include <Book/ParallelTask.hpp>


class LoadingState : public State
{
public:
	LoadingState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);

	void					setCompletion(float percent);

private:
	sf::Text				mLoadingText;
	sf::RectangleShape		mProgressBarBackground;
	sf::RectangleShape		mProgressBar;

	ParallelTask			mLoadingTask;
};

#endif // BOOK_LOADINGSTATE_HPP
