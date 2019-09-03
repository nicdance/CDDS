#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Button.h"
#include "CircleButton.h"
#include "ScrollingBackground.h"
#include "DynamicArray.h"

#include <chrono>


#include <string>
#include <cstring>
#include <vector> 
#include <iostream>


//	GameState used to detect the change in state
enum GameState
{
	SPLASH_SCREEN,
	MAIN_MENU,
	OPTIONS_MENU,
	GAME_PLAY,
	GAME_OVER,
	SCORE_BOARD
};

//	PlayState used to reflect the change in game play states
enum PlayState
{
	START,
	PLAYSEQUENCE,
	PLAYERTURN,
	END
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

	int CheckGameover();
	void PlayWrongAnswerSound();

protected:
	float const			waitTime =	500.0f;
	float const			startTime = 1600.0f;
	int					currentPlaying;
	int					correctAnswers = 0;
	bool				updateScore = false;
	bool				wait;
	bool				first = true;
	
	float circleRadius = 75.0f;
	float circleOffSet = (float)circleRadius*1.5;

	//std::string			scoreText;

	time_t				start;
	time_t				end;

	std::clock_t startClock;
	std::clock_t endClock;



	GameState			currentGameState;
	PlayState			currentPlayState;

	DynamicArray		correctOrder;
	DynamicArray		userEntered;


	sf::SoundBuffer		buffer;
	sf::Sound			sound;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			splashFont;
	aie::Font*			mainFont;
	aie::Font*			headingFont;
	aie::Texture*		mainBackground;
	aie::Texture*		circleBtnTexture;
	aie::Texture*		optionsBtnTexture;
	aie::Texture*		playBtnTexture;
	aie::Texture*		exitBtnTexture;
	ScrollingBackground* background;
	Button*				playButton;
	Button*				exitButton;
	Button*				optionsButton;
	Button*				mainMenuButton;
	CircleButton*		simonBtn;
};