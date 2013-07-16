#ifndef BOOK_COMPONENT_HPP
#define BOOK_COMPONENT_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>


namespace sf
{
	class Event;
}

namespace GUI
{

class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
    public:
        typedef std::shared_ptr<Component> Ptr;


	public:
							Component();
        virtual				~Component();

        virtual bool		isSelectable() const = 0;
		bool				isSelected() const;
        virtual void		select();
        virtual void		deselect();

        virtual bool		isActive() const;
        virtual void		activate();
        virtual void		deactivate();

        virtual void		handleEvent(const sf::Event& event) = 0;


    private:
        bool				mIsSelected;
        bool				mIsActive;
};

}

#endif // BOOK_COMPONENT_HPP
