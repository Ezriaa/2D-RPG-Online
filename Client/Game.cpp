#include "Game.h"

//Initialize
void Game::InitVar()
{
	this->Window = nullptr;
}

//Initialize Window
void Game::InitWindow()
{
	this->VideoMode.width = 800;
	this->VideoMode.height = 576;

	this->Window = new RenderWindow(this->VideoMode, "2D RPG - Client", Style::Titlebar | Style::Close);

	//FPS Max
	this->Window->setFramerateLimit(60);

	//Pas de vertical Sync
	this->Window->setVerticalSyncEnabled(false);
}

//Create a new player instance
void Game::InitPlayer()
{
	this->player = new Player();
}

//Initialize GUI
void Game::InitGUI()
{
	//Initialize GUI Font
	if (!this->GUIFont.loadFromFile("res/font.ttf"))
		std::cout << "Error while loading the font." << std::endl;

	//Initialize GUI Text
	this->GUIText.setFont(this->GUIFont);
	this->GUIText.setPosition(10, -5);
	this->GUIText.setFillColor(Color::White);
	this->GUIText.setCharacterSize(24);

	//Player HP Bar
	this->pHBar.setSize(Vector2f(100.f, 15.f));
	this->pHBar.setFillColor(Color::Red);
	this->pHBar.setPosition(10, 25);
	this->pHBarBack = this->pHBar;
	this->pHBarBack.setFillColor(Color(25, 25, 25, 200));

	//Player Mana Bar
	this->pMBar.setSize(Vector2f(100.f, 15.f));
	this->pMBar.setFillColor(Color::Blue);
	this->pMBar.setPosition(10, 45);
	this->pMBarBack = this->pMBar;
	this->pMBarBack.setFillColor(Color(25, 25, 25, 200));
}

//Initialize the world (map)
void Game::InitWorld()
{
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 33, 33, 33,
		0, 0, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 33, 1, 1,
		0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		2, 0, 0, 0, 33, 33, 33, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
		33, 33, 33, 33, 33, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 1, 3, 3, 3, 1, 1, 1,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 33, 33, 33,
		0, 0, 1, 0, 3, 2, 2, 33, 33, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 33, 33, 1, 1,
		2, 0, 1, 0, 3, 0, 2, 33, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 33, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};

	if (!World.load("res/grass.png", sf::Vector2u(32, 32), level, 25, 18))
		std::cout << "Error while loading the map." << std::endl;
}

//Constructeur & Destructeur
Game::Game()
{
	this->InitVar();
	this->InitWindow();
	this->InitPlayer();
	this->InitGUI();
	this->InitWorld();
}

//Destructor - Avoid memory leak
Game::~Game()
{
	delete this->Window;
	delete this->player;
}

//Check if the window(game) is open
const bool Game::Running() const
{
	return this->Window->isOpen();
}

//Fonctions Public
void Game::PollEvent()
{
	while (this->Window->pollEvent(this->Event))
	{
		switch (this->Event.type)
		{
		case Event::Closed:
			this->Window->close();
			break;
		}
	}	

	this->player->Update(this->Window);
}

void Game::Update()
{
	this->PollEvent();
	this->UpdateGUI();
}

//Refresh the GUI
void Game::UpdateGUI()
{
	std::stringstream ss;

	//Show Level
	ss << "Level: " << this->player->GetLVL();

	//Update HP Bar
	float HpPercent = static_cast<float>(this->player->GetHP()) / static_cast<float>(this->player->GetMHP());
	this->pHBar.setSize(Vector2f(100.f * HpPercent, this->pHBar.getSize().y));

	//Update Mana Bar
	float ManaPercent = static_cast<float>(this->player->GetMP()) / static_cast<float>(this->player->GetMMP());
	this->pMBar.setSize(Vector2f(100.f * ManaPercent, this->pMBar.getSize().y));

	//Show more info about the player while pressing C
	if (Keyboard::isKeyPressed(Keyboard::C))
	{
		
	}
	this->GUIText.setString(ss.str());
}

//Render the world (map)
void Game::RenderWorld(RenderTarget* Target)
{
	Target->draw(this->World);
}

//Render the GUI
void Game::RenderGUI(RenderTarget* Target)
{
	Target->draw(this->pHBarBack);
	Target->draw(this->pHBar);
	Target->draw(this->pMBarBack);
	Target->draw(this->pMBar);
	Target->draw(this->GUIText);
}

//Render everything in order
void Game::Render()
{
	this->Window->clear(Color::Black);

	//Game Object
	this->RenderWorld(this->Window);
	this->player->Render(*this->Window);
	this->RenderGUI(this->Window);

	this->Window->display();
}