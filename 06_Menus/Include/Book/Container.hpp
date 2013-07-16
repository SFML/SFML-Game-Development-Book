#ifndef BOOK_CONTAINER_HPP
#define BOOK_CONTAINER_HPP

#include <Book/Component.hpp>

#include <vector>
#include <memory>


namespace GUI
{

class Container : public Component
{
    public:
        typedef std::shared_ptr<Container> Ptr;
            

	public:
							Container();

        void				pack(Component::Ptr component);

        virtual bool		isSelectable() const;
        virtual void		handleEvent(const sf::Event& event);


    private:
        virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

        bool				hasSelection() const;
        void				select(std::size_t index);
        void				selectNext();
        void				selectPrevious();


    private:
        std::vector<Component::Ptr>		mChildren;
        int								mSelectedChild;
};

}

#endif // BOOK_CONTAINER_HPP
