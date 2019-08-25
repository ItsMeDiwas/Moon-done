#include <SFML\Graphics.hpp>


#ifndef SPRITE_
#define SPRITE_

class Sprite{

public:
	Sprite(sf::Texture* texture, sf::Vector2u imageCount, float switchTime); // needs to take a pointer
	~Sprite();

	// update based on delta time -> internal clock
	void Update(int row, float deltaTime, bool faceRight);


	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime; // time before one time before switched

};
#endif