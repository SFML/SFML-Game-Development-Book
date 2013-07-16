#ifndef BOOK_SOUNDNODE_HPP
#define BOOK_SOUNDNODE_HPP

#include <Book/SceneNode.hpp>
#include <Book/ResourceIdentifiers.hpp>


class SoundPlayer;

class SoundNode : public SceneNode
{
	public:
		explicit				SoundNode(SoundPlayer& player);
		void					playSound(SoundEffect::ID sound, sf::Vector2f position);

		virtual unsigned int	getCategory() const;


	private:
		SoundPlayer&			mSounds;
};

#endif // BOOK_SOUNDNODE_HPP
