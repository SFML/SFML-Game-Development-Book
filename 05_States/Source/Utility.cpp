#include <Book/Utility.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


void centerOrigin(sf::Sprite& sprite)
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void centerOrigin(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}
