#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"

enum GameState
{
	SPLASH_SCREEN,
	MAIN_MENU,
	OPTIONS_MENU,
	GAME_PLAY,
	GAME_OVER,
	SCORE_BOARD
};

class AssignmentApp : public aie::Application {
public:

	AssignmentApp();
	virtual ~AssignmentApp();

	virtual bool startup();
	virtual void shutdown();

	// Update Functions. The individual state Update functions are called on update
	virtual void update(float deltaTime);
	void updateSplashScreen(float deltaTime);
	void updateMainMenu(float deltaTime);
	void updateGamePlay(float deltaTime);
	void updateOptionsMenu(float deltaTime);
	void updateGameOver(float deltaTime);
	void updateScoreBoard(float deltaTime);

	// draw Functions. The individual state Draw functions are called on Draw
	virtual void draw();
	void drawSplashScreen(aie::Renderer2D* renderer);
	void drawMainMenu(aie::Renderer2D* renderer);
	void drawGamePlay(aie::Renderer2D* renderer);
	void drawOptionsMenu(aie::Renderer2D* renderer);
	void drawGameOver(aie::Renderer2D* renderer);
	void drawScoreBoard(aie::Renderer2D* renderer);

	void drawText(aie::Renderer2D* renderer, char textToDisplay[], aie::Font* currentFont, float xOffset, float yOffset);

protected:
	GameState currentGameState;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			splashFont;
	aie::Font*			mainFont;
	aie::Font*			headingFont;
	Button*				playButton;
	Button*				exitButton;
	Button*				optionsButton;
	Button*				mainMenuButton;
};