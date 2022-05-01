#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Player
{
private:
	//Player Variables
	Sprite Sprite;
	Texture Texture;

	enum Dir { Down, Left, Right, Top};
	Vector2i hAnim;
	Clock hAnimClock;

	bool isMoving;
	int Level;
	int Health;
	int mHealth;
	int Mana;
	int mMana;
	int Gold;

	float WALK_SPEED;
	int SPRITE_SIZE = 32;

	void InitVar();
	void InitSprite();
	void InitTexture();

public:
	//Constructor & Destructor
	Player();
	virtual ~Player();

	//Accessor
	const int& GetHP() const;
	const int& GetMHP() const;
	const int& GetMP() const;
	const int& GetMMP() const;
	const int& GetLVL() const;
	const int& GetGOLD() const;
	void SetHP(const int HP);
	void LoseHP(const int HP);
	void SetMP(const int MP);
	void LoseMP(const int MP);

	//Functions
	void Move(const float X, const float Y);
	void UpdateMovement();
	void UpdateAnimation();
	void UpdateBoundCol(const RenderTarget* Target);
	void Update(const RenderTarget* Target);
	void Render(RenderTarget& Target);
};

