#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>


// Resource ID for sf::Texture
namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
	};
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Resources");
	window.setFramerateLimit(20);

	// Try to load resources
	ResourceHolder<sf::Texture, Textures::ID> textures;
	try
	{
		textures.load(Textures::Landscape, "Media/Textures/Desert.png");
		textures.load(Textures::Airplane, "Media/Textures/Eagle.png");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return 1;
	}

	// Access resources
	sf::Sprite landscape(textures.get(Textures::Landscape));
	sf::Sprite airplane(textures.get(Textures::Airplane));
	airplane.setPosition(200.f, 200.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::Closed)
				return 0;
		}

		window.clear();
		window.draw(landscape);
		window.draw(airplane);
		window.display();
	}
}
