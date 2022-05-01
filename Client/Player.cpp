#include "Player.h"
#include <iostream>

//Initialize Player Variables
void Player::InitVar()
{
	this->isMoving = false;
	this->Level = 1;
	this->mHealth = 20;
	this->Health = this->mHealth;
	this->mMana = 25;
	this->Mana = this->mMana;
	this->Gold = 950;
}

//Initialize Texture
void Player::InitTexture()
{
	if (!this->Texture.loadFromFile("res/hero.png"))
		std::cout << "Error while loading hero texture." << std::endl;
}

//Initialize Sprite
void Player::InitSprite()
{
	this->Sprite.setTexture(this->Texture);
	this->Sprite.setTextureRect(IntRect(32, 0, SPRITE_SIZE, SPRITE_SIZE));
	this->Sprite.setScale(1.5f, 1.5f);
}

//Initialize Player
Player::Player()
{
	this->WALK_SPEED = 2.0f;
	this->Sprite.setPosition(0, 200);
	this->InitVar();
	this->InitTexture();
	this->InitSprite();
}

Player::~Player()
{

}

//Accessor
//Return the current HP of player
const int& Player::GetHP() const
{
	return this->Health;
}

//Return the max HP of player
const int& Player::GetMHP() const
{
	return this->mHealth;
}

//Return the current MP of player
const int& Player::GetMP() const
{
	return this->Mana;
}

//Return the max MP of player
const int& Player::GetMMP() const
{
	return this->mMana;
}

//Return the level of player
const int& Player::GetLVL() const
{
	return this->Level;
}

//Return the gold of player
const int& Player::GetGOLD() const
{
	return this->Gold;
}

//Set player hp equal to the params (For GUI test purpose)
void Player::SetHP(const int HP)
{
	this->Health = HP;
}

//Player lose hp equal to the params (For GUI test purpose)
void Player::LoseHP(const int HP)
{
	this->Health -= HP;
}

//Set player mp equal to the params (For GUI test purpose)
void Player::SetMP(const int MP)
{
	this->Mana = MP;
}

//Player lose mp equal to the params (For GUI test purpose)
void Player::LoseMP(const int MP)
{
	this->Mana -= MP;
}

//Functions
void Player::Move(const float X, const float Y)
{
	this->Sprite.move(this->WALK_SPEED * X, this->WALK_SPEED * Y);
}

//Handle player movement
void Player::UpdateMovement()
{
	this->isMoving = false;

	if (Keyboard::isKeyPressed(Keyboard::Key::Q))
	{
		hAnim.y = Left;
		this->Sprite.move(-1.f, 0.f);
		this->isMoving = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		hAnim.y = Right;
		this->Sprite.move(1.f, 0.f);
		this->isMoving = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Z))
	{
		hAnim.y = Top;
		this->Sprite.move(0.f, -1.f);
		this->isMoving = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{
		hAnim.y = Down;
		this->Sprite.move(0.f, 1.f);
		this->isMoving = true;
	}
}

//Manage the player sprite animation
void Player::UpdateAnimation()
{
	this->Sprite.setTextureRect(IntRect(hAnim.x * SPRITE_SIZE, hAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

	if (hAnimClock.getElapsedTime().asSeconds() > 0.2f)
	{
		if (hAnim.x * SPRITE_SIZE >= this->Texture.getSize().x - SPRITE_SIZE)
			hAnim.x = 0;

		else
			if(isMoving)
				hAnim.x++;

		hAnimClock.restart();
	}
}

//Manage the collision, don't let the player go outside the window
void Player::UpdateBoundCol(const RenderTarget * Target)
{
	//Left Collision
	if (this->Sprite.getGlobalBounds().left <= 0.f)
		this->Sprite.setPosition(0.f, this->Sprite.getGlobalBounds().top);

	//Right Collision
	if (this->Sprite.getGlobalBounds().left + this->Sprite.getGlobalBounds().width >= Target->getSize().x)
		this->Sprite.setPosition(Target->getSize().x - this->Sprite.getGlobalBounds().width, this->Sprite.getGlobalBounds().top);

	//Top Collision
	if (this->Sprite.getGlobalBounds().top <= 0.f)
		this->Sprite.setPosition(this->Sprite.getGlobalBounds().left, 0.f);

	//Down Collision
	if (this->Sprite.getGlobalBounds().top + this->Sprite.getGlobalBounds().height >= Target->getSize().y)
		this->Sprite.setPosition(this->Sprite.getGlobalBounds().left, Target->getSize().y - this->Sprite.getGlobalBounds().height);
}

void Player::Update(const RenderTarget* Target)
{
	this->UpdateMovement();
	this->UpdateAnimation();
	this->UpdateBoundCol(Target);
}

//Render the player on the window
void Player::Render(RenderTarget& Target)
{
	Target.draw(this->Sprite);
}