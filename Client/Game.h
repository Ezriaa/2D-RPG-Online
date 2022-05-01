#pragma once
#include "Player.h"
#include "Map.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

//Game Engine KEKW

class Game
{
private:
	//Window Variables
	RenderWindow* Window;
	Event Event;
	VideoMode VideoMode;

	//Player Variables
	Player* player;

	//GUI Variables
	Font GUIFont;
	Text GUIText;
	RectangleShape pHBar;
	RectangleShape pHBarBack;
	RectangleShape pMBar;
	RectangleShape pMBarBack;

	//Map Variable
	TileMap World;

	//Game Object

	//Initalisation
	void InitVar();
	void InitWindow();
	void InitPlayer();
	void InitGUI();
	void InitWorld();

public:
	//Constructor & Destructor
	Game();
	virtual ~Game();

	const bool Running() const;

	//Functions
	void PollEvent();
	void Update();
	void UpdateGUI();
	void RenderWorld(RenderTarget* Target);
	void RenderGUI(RenderTarget* Target);
	void Render();
};