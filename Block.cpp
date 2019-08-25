#include <iostream>
#include <string>
#include "Block.h"


using namespace std;

Block::Block(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	buzz.setSize(size);
	buzz.setOrigin(size / 2.0f); // set the origin to half the size of the body
	buzz.setTexture(texture);
	buzz.setPosition(position);
}
Block::~Block()
{

}

void Block::Draw(sf::RenderWindow& window)
{

}

