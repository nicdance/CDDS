#pragma once
#include "Renderer2D.h"
#include "Input.h"
#include "Texture.h"
#include <String>
#include <SFML/Audio.hpp>

/*
*	class for the circle game buttons.
*/
class CircleButton
{
public:
	CircleButton();
	CircleButton(int number, std::string soundFile , float x, float y, float r, aie::Texture *newTexture);
	~CircleButton();


	// Used to Draw the Button
	void Draw(aie::Renderer2D* renderer, float xPos, float yPos);
	
	// Check if Button was presed
	bool Update();
	void HoverOn();
	void HoverOff();

	int getNumber();

	void CircleButton::PlaySound();

	void setColour(float r, float g, float b, float a);

protected:
	bool hover;
	bool press;

	//Button's position, width, and height.
	float posX;
	float posY;
	float radius;

	float red, blue, green, alpha;

	int btnNmber;

	aie::Texture*		btnImage;
	sf::SoundBuffer		buffer;
	sf::Sound			sound;
};

