#ifndef BOOK_STATEIDENTIFIERS_HPP
#define BOOK_STATEIDENTIFIERS_HPP


namespace States
{
	enum ID
	{
		None,
		Title,
		Menu,
		Game,
		Loading,
		Pause,
		NetworkPause,
		Settings,
		GameOver,
		MissionSuccess,
		HostGame,
		JoinGame,
	};
}

#endif // BOOK_STATEIDENTIFIERS_HPP
