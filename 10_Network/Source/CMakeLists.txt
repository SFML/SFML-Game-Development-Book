
set (SRC
	Aircraft.cpp
	Animation.cpp
	Application.cpp
	Button.cpp
	BloomEffect.cpp
	Command.cpp
	CommandQueue.cpp
	Component.cpp
	Container.cpp
	DataTables.cpp
	EmitterNode.cpp
	Entity.cpp
	GameOverState.cpp
	GameServer.cpp
	GameState.cpp
	KeyBinding.cpp
	Label.cpp
	MenuState.cpp
	MultiplayerGameState.cpp
	MusicPlayer.cpp
	NetworkNode.cpp
	PauseState.cpp
	ParticleNode.cpp
	Pickup.cpp
	Player.cpp
	PostEffect.cpp
	Projectile.cpp
	SceneNode.cpp
	SettingsState.cpp
	SpriteNode.cpp
	TextNode.cpp
	SoundNode.cpp
	SoundPlayer.cpp
	State.cpp
	StateStack.cpp
	TitleState.cpp
	Utility.cpp
	World.cpp)

build_chapter(10_Network SOURCES ${SRC})