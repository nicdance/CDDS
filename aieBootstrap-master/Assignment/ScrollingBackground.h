#pragma once
#include "Texture.h"
#include "Renderer2D.h"
#include "Application.h"


struct Position {
	float x;
	float y;

	float width;
	float startX;
};

class ScrollingBackground
{
protected:
public:
	Position position;
	aie::Texture* texture;
	ScrollingBackground();
	ScrollingBackground(float x, float y, aie::Texture *newTexture);
	~ScrollingBackground();
	void Move(float speed, float deltaTime, int multiplier);	// Used to move the background
	void ResetPosition();						// Reset To start position
	void Draw(aie::Renderer2D* renderer);		// Draw The current screen

};

