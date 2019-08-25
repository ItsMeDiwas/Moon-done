#include <iostream>
#include <string>
#include "Player.h"
#include "Sprite.h"


using namespace std;

//derived from Sprite class
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
sprite(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	buzz.setSize(sf::Vector2f(80.0f, 80.0f));
	buzz.setPosition(-10.0f, 400.0f);// just above ground
	buzz.setTexture(texture);
}//default constructor


Player::~Player()
{


} // destructor

void Player::Update(float deltaTime)
{
	// left
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= 1.5 * speed * deltaTime; //1.5 is faster walking constant
	}
	// right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += 1.5 * speed * deltaTime; //1.5 is faster walking constant
	}
	// up
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= 1.5 * speed * deltaTime; //1.5 is faster walking constant
	}
	// down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += 1.5 * speed * deltaTime; //1.5 is faster walking constant
	}


	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (movement.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}
	sprite.Update(row, deltaTime, faceRight);
	buzz.setTextureRect(sprite.uvRect);
	buzz.move(movement);

}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(buzz);
}
