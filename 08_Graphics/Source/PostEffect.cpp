#include <Book/PostEffect.hpp>

#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>


PostEffect::~PostEffect()
{
}

void PostEffect::applyShader(const sf::Shader& shader, sf::RenderTarget& output)
{
	sf::Vector2f outputSize = static_cast<sf::Vector2f>(output.getSize());

	sf::VertexArray vertices(sf::TrianglesStrip, 4);
	vertices[0] = sf::Vertex(sf::Vector2f(0, 0),            sf::Vector2f(0, 1));
	vertices[1] = sf::Vertex(sf::Vector2f(outputSize.x, 0), sf::Vector2f(1, 1));
	vertices[2] = sf::Vertex(sf::Vector2f(0, outputSize.y), sf::Vector2f(0, 0));
	vertices[3] = sf::Vertex(sf::Vector2f(outputSize),      sf::Vector2f(1, 0));

	sf::RenderStates states;
	states.shader 	 = &shader;
	states.blendMode = sf::BlendNone;

	output.draw(vertices, states);
}

bool PostEffect::isSupported()
{
	return sf::Shader::isAvailable();
}
