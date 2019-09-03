#include "ScrollingBackground.h"

ScrollingBackground::ScrollingBackground()
{
}

//	construction
ScrollingBackground::ScrollingBackground(float x, float y, aie::Texture *newTexture) {
	position = {x,y, (float)newTexture ->getWidth(), x };
	texture = newTexture;
}

ScrollingBackground::~ScrollingBackground()
{
}

// moves the backgrounnd image to give hte effect of scrolling
void ScrollingBackground::Move(float speed, float deltaTime, int multiplier) {
	position.x = position.x - (speed * deltaTime);
	if (position.x < -(position.width)) {
		position.x = position.width*2;
	}
}

void ScrollingBackground::ResetPosition() {
}

// draws the background sprite
void ScrollingBackground::Draw(aie::Renderer2D* renderer) {
	renderer->drawSprite(texture, position.x, position.y, 0.0f, 0.0f, 0.0f, 0.0f, .5f, .5f);
}