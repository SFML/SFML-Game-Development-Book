#include <Book/SettingsState.hpp>
#include <Book/Utility.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


SettingsState::SettingsState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
	
	// Build key binding buttons and labels
	for (std::size_t x = 0; x < 2; ++x)
	{
		addButtonLabel(PlayerAction::MoveLeft,		x, 0, "Move Left", context);
		addButtonLabel(PlayerAction::MoveRight,		x, 1, "Move Right", context);
		addButtonLabel(PlayerAction::MoveUp,		x, 2, "Move Up", context);
		addButtonLabel(PlayerAction::MoveDown,		x, 3, "Move Down", context);
		addButtonLabel(PlayerAction::Fire,			x, 4, "Fire", context);
		addButtonLabel(PlayerAction::LaunchMissile,	x, 5, "Missile", context);
	}

	updateLabels();

	auto backButton = std::make_shared<GUI::Button>(context);
	backButton->setPosition(80.f, 620.f);
	backButton->setText("Back");
	backButton->setCallback(std::bind(&SettingsState::requestStackPop, this));

	mGUIContainer.pack(backButton);
}

void SettingsState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool SettingsState::update(sf::Time)
{
	return true;
}

bool SettingsState::handleEvent(const sf::Event& event)
{
	bool isKeyBinding = false;

	// Iterate through all key binding buttons to see if they are being pressed, waiting for the user to enter a key
	for (std::size_t i = 0; i < 2*PlayerAction::Count; ++i)
	{
		if (mBindingButtons[i]->isActive())
		{
			isKeyBinding = true;
			if (event.type == sf::Event::KeyReleased)
			{
				// Player 1
				if (i < PlayerAction::Count)
					getContext().keys1->assignKey(static_cast<PlayerAction::Type>(i), event.key.code);
				
				// Player 2
				else
					getContext().keys2->assignKey(static_cast<PlayerAction::Type>(i - PlayerAction::Count), event.key.code);

				mBindingButtons[i]->deactivate();
			}
			break;
		}
	}

	// If pressed button changed key bindings, update labels; otherwise consider other buttons in container
	if (isKeyBinding)
		updateLabels();
	else
		mGUIContainer.handleEvent(event);

	return false;
}

void SettingsState::updateLabels()
{
	for (std::size_t i = 0; i < PlayerAction::Count; ++i)
	{
		auto action = static_cast<PlayerAction::Type>(i);

		// Get keys of both players
		sf::Keyboard::Key key1 = getContext().keys1->getAssignedKey(action);
		sf::Keyboard::Key key2 = getContext().keys2->getAssignedKey(action);

		// Assign both key strings to labels
		mBindingLabels[i]->setText(toString(key1));
		mBindingLabels[i + PlayerAction::Count]->setText(toString(key2));
	}
}

void SettingsState::addButtonLabel(std::size_t index, std::size_t x, std::size_t y, const std::string& text, Context context)
{
	// For x==0, start at index 0, otherwise start at half of array
	index += PlayerAction::Count * x;

	mBindingButtons[index] = std::make_shared<GUI::Button>(context);
	mBindingButtons[index]->setPosition(400.f*x + 80.f, 50.f*y + 300.f);
	mBindingButtons[index]->setText(text);
	mBindingButtons[index]->setToggle(true);

	mBindingLabels[index] = std::make_shared<GUI::Label>("", *context.fonts);
	mBindingLabels[index]->setPosition(400.f*x + 300.f, 50.f*y + 315.f);

	mGUIContainer.pack(mBindingButtons[index]);
	mGUIContainer.pack(mBindingLabels[index]);
}
