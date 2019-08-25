#include <iostream>
#include <string>
#include "Sprite.h"


using namespace std;

Sprite::Sprite(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	//height of each 
	uvRect.width = texture->getSize().x / float(imageCount.x); // float -> unsigned int width
	uvRect.height = texture->getSize().y / float(imageCount.y); // float -> unsigned int height

}

//update function
void Sprite::Update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		// so if you run out of index of frames, return to 0; -> return to initial vector for animation -> circular map
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;

	if (faceRight)
	{
		uvRect.top = currentImage.y * uvRect.height;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	

}

Sprite::~Sprite(){


}