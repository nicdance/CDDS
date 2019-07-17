#pragma once
#include "Renderer2D.h"
#include "Application.h"
#include "AssignmentApp.h"
class State
{
public:
	State();
	~State();
	virtual void on_enter() = 0;
	virtual void on_exit() = 0;
	virtual void update(AssignmentApp app, float deltaTime) = 0;
	virtual void draw(aie::Renderer2D* renderer) = 0;
};

