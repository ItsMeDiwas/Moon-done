#include <SFML\Graphics.hpp>
#include "Collision.h"

#ifndef BLOCK_
#define BLOCK_

class Block{

public:
	Block(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position );
	~Block();

	void Draw(sf::RenderWindow& window);
	Collision GetCollision(){ return Collision(buzz); }

private:
	sf::RectangleShape buzz;
	
};
#endif