#ifndef BOOK_SOUNDPLAYER_HPP
#define BOOK_SOUNDPLAYER_HPP

#include <Book/ResourceHolder.hpp>
#include <Book/ResourceIdentifiers.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include <list>


class SoundPlayer : private sf::NonCopyable
{
	public:
									SoundPlayer();

		void						play(SoundEffect::ID effect);
		void						play(SoundEffect::ID effect, sf::Vector2f position);

		void						removeStoppedSounds();
		void						setListenerPosition(sf::Vector2f position);
		sf::Vector2f				getListenerPosition() const;


	private:
		SoundBufferHolder			mSoundBuffers;
		std::list<sf::Sound>		mSounds;
};

#endif // BOOK_SOUNDPLAYER_HPP
