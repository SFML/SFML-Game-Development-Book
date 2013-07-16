
#ifndef BOOK_BUTTON_HPP
#define BOOK_BUTTON_HPP

#include <Book/Component.hpp>
#include <Book/ResourceIdentifiers.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


namespace GUI
{

class Button : public Component
{
    public:
        typedef std::shared_ptr<Button>		Ptr;
        typedef std::function<void()>		Callback;


	public:
								Button(const FontHolder& fonts, const TextureHolder& textures);

        void					setCallback(Callback callback);
        void					setText(const std::string& text);
        void					setToggle(bool flag);

        virtual bool			isSelectable() const;
        virtual void			select();
        virtual void			deselect();

        virtual void			activate();
        virtual void			deactivate();

        virtual void			handleEvent(const sf::Event& event);


    private:
        virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;


    private:
        Callback				mCallback;
        const sf::Texture&		mNormalTexture;
        const sf::Texture&		mSelectedTexture;
        const sf::Texture&		mPressedTexture;
        sf::Sprite				mSprite;
        sf::Text				mText;
        bool					mIsToggle;
};

}

#endif // BOOK_BUTTON_HPP
