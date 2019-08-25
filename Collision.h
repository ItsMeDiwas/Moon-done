#include <SFML\Graphics.hpp>


#ifndef COLLISION_
#define COLLISION_

class Collision{



public:
	Collision(sf::RectangleShape& buzz);//default constructor
	~Collision(); // destructor

	void Move(float dx, float dy){ buzz.move(dx, dy); }

	bool CheckCollision(Collision& other, float push);
	sf::Vector2f GetPosition(){ return buzz.getPosition(); }
	sf::Vector2f GetHalfSize() { return buzz.getSize() / 2.0f; }

private:
	sf::RectangleShape& buzz;
	
};
#endif