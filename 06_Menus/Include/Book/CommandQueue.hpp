#ifndef BOOK_COMMANDQUEUE_HPP
#define BOOK_COMMANDQUEUE_HPP

#include <Book/Command.hpp>

#include <queue>


class CommandQueue
{
	public:
		void						push(const Command& command);
		Command						pop();
		bool						isEmpty() const;

		
	private:
		std::queue<Command>			mQueue;
};

#endif // BOOK_COMMANDQUEUE_HPP
