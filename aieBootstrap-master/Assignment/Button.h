#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "Input.h"
#include "Texture.h"
class Button
{
public:
	Button();
	Button(const char* newButtonText, float x, float y, float _width, float _height);
	Button(aie::Texture *newTexture, float x, float y);
	~Button();

	// Used to Draw the Button
	void Draw(aie::Renderer2D* renderer);

	// Check if Button was presed
	bool Update();

protected:
	bool hover;
	//Font and text for the button.
	aie::Font* currentFont;
	char buttonText[64];

	aie::Texture*		btnImage;
	
		//Button's position, width, and height.
	float posX;
	float posY;
	float width;
	float height;
};

