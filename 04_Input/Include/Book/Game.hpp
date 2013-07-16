#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <Book/World.hpp>
#include <Book/Player.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Game : private sf::NonCopyable
{
	public:
								Game();
		void					run();
		

	private:
		void					processInput();
		void					update(sf::Time elapsedTime);
		void					render();
		void					updateStatistics(sf::Time elapsedTime);


	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		World					mWorld;
		Player					mPlayer;

	  	sf::Font				mFont;
		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t			mStatisticsNumFrames;
};

#endif // BOOK_GAME_HPP
