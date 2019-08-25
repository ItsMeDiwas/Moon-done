#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"


// include classes
#include "Sprite.h"
#include "Player.h"
#include "Collision.h"
#include "Block.h"

int main()
{
	// time to calculate how many times P has been pressed to pause or unpause game
	int pausecount = 0;
	//========================================================
	// WINDOW
	// same as window.create(sf::VideoMode(800, 600), "");
	sf::RenderWindow window(sf::VideoMode(640, 480), "Flying Man");

	// resets the title of the screen
	window.setSize(sf::Vector2u(640, 480));
	window.setPosition(sf::Vector2i(100, 100));


	// quit event listener and function check output
	std::cout << "Press Q to quit" << std::endl;

	//==========================================================
	//LOAD IMAGES
	//load images

	// resizing screen size -> u means unassigned
	sf::Vector2u size(640, 480);
	std::cout << size.x << " " << size.y << std::endl;

	// if key is pressed say "Press any key to continue
	std::cout << "Press any key to continue" << std::endl;


	std::string message = "Welcome to the Moon";
	std::string display = "";

	int index = 0;

	window.setKeyRepeatEnabled(false);// -> disable repeated keys inside event buffer


	//==================================================================
	//BACKGROUND
	// background
	sf::Texture bTexture;
	sf::Sprite bImage;
	if (!bTexture.loadFromFile("background1.png"))
		std::cout << "Error could not load background image" << std::endl;

	bImage.setTexture(bTexture);
	bImage.setScale(1.0f, (float)size.y / bTexture.getSize().y);
	// end background instructions


	//=======================================================================
	//GROUND LEVEL from which you can jump
	//Ground
	sf::Texture gTexture;
	sf::Sprite gImage;
	if (!gTexture.loadFromFile("ground.png")){
		std::cout << "Error. Ground not Detected. " << std::endl;
	}
	else
	{
		std::cout << "Ground loaded successfully!" << std::endl;
	}
	gImage.setTexture(gTexture);//I believe this is 100 pixels high and 960 across / long
	//set position so it is on the ground
	gImage.setPosition(0, 470);// ten pixels from 480 texture
	//getSize so you can find intersection of player and ground. That is your collision


	//=======================================================================
	//PLAYER
	//player
	sf::Texture playerTexture;

	// exception handling
	if (!playerTexture.loadFromFile("Buzz2.png")){
		std::cout << "Error could not load player image" << std::endl;
	}
	else
	{
		std::cout << "Sprite Loaded successfully!" << std::endl;
	}

	// Set up Sprite
	// the first two set up spacing between sprites also. Four was too much
	Player player(&playerTexture, sf::Vector2u(3.53, 3.53), 0.3f, 100.0f); //animation will be around a second

	//player collision geometry


	//COLLISION TEST
	//=============================================================================
	//BLOCKS TEST COLLISION
	Block block1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	Block block2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

	//==============================================================================



	//==============================================================
	// QUIT BUTTON
	// quit instructions load -> texture is 200 x 100
	sf::Texture qTexture;
	sf::Sprite quitButton;
	if (!qTexture.loadFromFile("button3.png"))
		std::cout << "Error could not load instructions" << std::endl;
	else{
		std::cout << "Button loaded successfully!" << std::endl;
	}
	quitButton.setTexture(qTexture);
	quitButton.setScale(0.75, 0.75);
	//quit button end

	//==================================================================
	// SET CLOCK for DELTA

	float deltaTime = 0.0f;
	sf::Clock clock; // get delta time via internal clock-> Posix -> Haskell

	while (window.isOpen())
	{
		//==================================================================
		//SOUND
		// while window is open, load sound - works but slows down programme,
		// is inconsistent
		/*
		sf::Music music;
		if (!music.openFromFile("windhowl.wav"))
		{
			std::cout << "Failed to load audio" << std::endl;
		}
		else
		{
			music.play();

			std::cout << "Sound file loaded successfully!" << std::endl;
		}
		*/


		//====================================================================

		// GAME LOOP
		//===========================================================================================
		// Game loop

		sf::Event Event;
		while (window.pollEvent(Event)) // FIFO
		{
			deltaTime = clock.restart().asSeconds(); //retrieve delta time

			switch (Event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseMoved: // where is the mouse for coordinates
					std::cout << "X:" << Event.mouseMove.x << " Y:" << std::endl;
					break;
			}
			//===============================================================================

			//PAUSE
			//PAUSE FUNCTION SET-UP
			// p to pause game
			// pausecount starts at 0 and increments every time P is pressed.
			// if the count goes up, pausecount checks whether it is divisible by 0;
			// based on odd or even, it either outputs paused(for odd) or not paused (for even)
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::P))
			{
				pausecount++;
				if (pausecount % 2 == 0)
				{
					sf::Event::GainedFocus;
					std::cout << "Unpaused" << std::endl;
				}
				else
				{
					sf::Event::LostFocus;
					std::cout << "Paused" << std::endl;
				}
			}

			//==============================================================================

			//QUIT
			// quit if key pressed is q
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Q))
			{
				//if (Event.key.code == sf::Keyboard::Q)
				std::cout << "You have chosen to quit" << std::endl;
				return 0;
			}
			//====================================================================
			//check for collision
			//AABB (vs Pixel collision detection)
			/*
			if Object 1 is Obj.x, Obj.y and Object 2 is Obj1.x, Obj1.y:
			is colliding for (Obj and Obj1) =
			!((Obj.x < Ob1.x) || (Obj1.x < Obj.y) || (Obj.y < Obj1.y) || (Obj1.y < Obj.y))
			*/



			// compare player bounds to gImage bounds
			/*
			if (quitButton.getGlobalBounds().intersects(gImage.getGlobalBounds()))
			{
				std::cout << "COLLISION" << std::endl;
			}
			else
			{
				std::cout << "No Collision detected" << std::endl;
			}
			*/

			//=========================================================================


			window.clear(); // always clear buffer before drawing so won't get smudgy effect
			// RENDER IMAGES
			window.draw(gImage);// draw ground first-> this is the base from which you can jump
			window.draw(bImage); // draw background first
			window.draw(quitButton); // draw quit button
			player.Update(deltaTime); //update Delta
			player.Draw(window); //draw player

			// check collision
			//block1.GetCollision().CheckCollision(player.GetCollision(), 0.3f);
			// block2.GetCollision().CheckCollision(player.GetCollision(), 1.0f);

			// draw test blocks
			block1.Draw(window);
			block2.Draw(window);
			// draw test blocks

			window.display(); // window turns to black by default -> displays contents of window
		}
	}

	return 0;
}

/*
daily notes / issues ->
1. Work on getting ground and player to collide with ground and that be base/ ground
2. Work on getting player to jump (play with jump/ gravity)
3. Work on atmosphere to emulate wind/atmosphere on moon (snow?)
4. Work on enemy
4. Work on enemy touch die
5. Work on audio (make sure it doesn't slow down entire functionality of programme) -> basic sound function is set up
6. Work on views so player can't go off-screen outside of screen bounds
*/

