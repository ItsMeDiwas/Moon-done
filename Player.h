#include <SFML\Graphics.hpp>
#include "Sprite.h"
#include "Collision.h"

#ifndef PLAYER_
#define PLAYER_

class Player{



public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);//default constructor
	~Player(); // destructor

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);

	sf::Vector2f GetPosition() { return buzz.getPosition(); }
	Collision GetCollision(){ return Collision(buzz); }


private:
	sf::RectangleShape buzz; // figure
	Sprite sprite;
	unsigned int row;
	float speed;
	bool faceRight;
};
#endif
