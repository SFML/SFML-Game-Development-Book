#include <Book/ParallelTask.hpp>


ParallelTask::ParallelTask()
: mThread(&ParallelTask::runTask, this)
, mFinished(false)
{
}

void ParallelTask::execute()
{
	mFinished = false;
	mElapsedTime.restart();
	mThread.launch();
}

bool ParallelTask::isFinished()
{
	sf::Lock lock(mMutex);
	return mFinished;
}

float ParallelTask::getCompletion()
{
	sf::Lock lock(mMutex);

	// 100% at 10 seconds of elapsed time
	return mElapsedTime.getElapsedTime().asSeconds() / 10.f;
}

void ParallelTask::runTask()
{
	// Dummy task - stall 10 seconds
	bool ended = false;
	while (!ended)
	{
		sf::Lock lock(mMutex); // Protect the clock 
		if (mElapsedTime.getElapsedTime().asSeconds() >= 10.f)
			ended = true;
	}

	{ // mFinished may be accessed from multiple threads, protect it
		sf::Lock lock(mMutex);
		mFinished = true;
	}	
}