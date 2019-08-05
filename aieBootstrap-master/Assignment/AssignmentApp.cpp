#include "AssignmentApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <SFML/Audio.hpp>
#include <random>
#include <iostream>
#include <time.h>

AssignmentApp::AssignmentApp() {

}

AssignmentApp::~AssignmentApp() {

}

bool AssignmentApp::startup() {
	wait = false;

	float circleRadius = 75.0f;
	float circleOffSet = (float)circleRadius*1.5;
	currentGameState = SPLASH_SCREEN;
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	splashFont = new aie::Font("../bin/font/pricedown_bl.ttf", 300);
	mainFont = new aie::Font("../bin/font/consolas.ttf", 32);
	headingFont = new aie::Font("../bin/font/pricedown_bl.ttf", 150);

	optionsBtnTexture = new aie::Texture("../bin/textures/Settings_BTN.png");
	playBtnTexture = new aie::Texture("../bin/textures/Play_BTN.png");
	exitBtnTexture = new aie::Texture("../bin/textures/Close_BTN.png");

	playButton = new Button(playBtnTexture, getWindowWidth() / 2.0f- playBtnTexture->getWidth(), getWindowHeight() / 4.0f);
	optionsButton = new Button(optionsBtnTexture, getWindowWidth() / 2.0f, getWindowHeight() / 4.0f );
	exitButton = new Button(exitBtnTexture, getWindowWidth() / 2.0f + playBtnTexture->getWidth(), getWindowHeight() / 4.0f);
	mainMenuButton = new Button(exitBtnTexture, getWindowWidth() / 2.0f, getWindowHeight() / 4.0f);

	background = new ScrollingBackground[3];
	mainBackground = new aie::Texture("../bin/textures/BG.png");
	for (int i = 0; i < 3; i++)
	{
		background[i] = ScrollingBackground(mainBackground->getWidth() / 2 + (mainBackground->getWidth()*i), 
						getWindowHeight() / 2, mainBackground);
	}

	DynamicArray correctOrder = DynamicArray();
	DynamicArray userEntered = DynamicArray();

	circleBtnTexture = new aie::Texture("../bin/textures/Planet.png");
	circleOffSet = circleBtnTexture->getWidth();
	simonBtn = new CircleButton[4];
	
	simonBtn[0] = CircleButton(0, "../bin/Sound/a.wav", getWindowWidth() / 2.0f+ circleOffSet, getWindowHeight() / 2.0f, circleRadius, circleBtnTexture);
	simonBtn[1] = CircleButton(1, "../bin/Sound/c.wav", getWindowWidth() / 2.0f- circleOffSet, getWindowHeight() / 2.0f, circleRadius, circleBtnTexture);
	simonBtn[2] = CircleButton(2, "../bin/Sound/lowE.wav", getWindowWidth() / 2.0f, getWindowHeight() / 2.0f+ circleOffSet, circleRadius, circleBtnTexture);
	simonBtn[3] = CircleButton(3, "../bin/Sound/highE.wav", getWindowWidth() / 2.0f, getWindowHeight() / 2.0f- circleOffSet, circleRadius, circleBtnTexture);
	
	simonBtn[0].setColour(1.0f, 0.0f, 0.0f, 0.2f); // Red
	simonBtn[1].setColour(1.0f, 1.0f, 0.0f, 0.2f); // Yellow
	simonBtn[2].setColour(0.03f, 0.03f, 1.0f, 0.2f); // Blue
	simonBtn[3].setColour(0.0f, 1.0f, 0.0f, 0.2f); // Green


	buffer.loadFromFile("../bin/Sound/wrong.wav");

	return true;
}

void AssignmentApp::shutdown() {
	delete m_2dRenderer;
	delete splashFont;
	delete mainFont;
	delete headingFont;
	delete mainBackground;
	delete circleBtnTexture;
	delete optionsBtnTexture;
	delete playBtnTexture;
	delete exitBtnTexture;
	delete playButton;
	delete exitButton;
	delete optionsButton;
	delete mainMenuButton;

	delete[] background;
	delete[] simonBtn;
}

void AssignmentApp::update(float deltaTime) {
	// Move Each background image
	for (int i = 0; i < 3; i++)
	{
		background[i].Move(50, deltaTime, i);
	}

	switch (currentGameState)
	{
	case SPLASH_SCREEN:
		updateSplashScreen(deltaTime);
		break;
	case MAIN_MENU:
		updateMainMenu(deltaTime);
		break;
	case GAME_PLAY:
		updateGamePlay(deltaTime);
		break;
	case OPTIONS_MENU:
		updateOptionsMenu(deltaTime);
		break;
	case GAME_OVER:
		updateGameOver(deltaTime);
		break;
	//case SCORE_BOARD:
	//	updateScoreBoard(deltaTime);
	//	break;
	default:
		break;
	}
}

void AssignmentApp::updateSplashScreen(float deltaTime){
	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) {
		quit();
	}
	else if (input->isKeyDown(aie::INPUT_KEY_ENTER)) {
		currentGameState = MAIN_MENU;
	}

}

void AssignmentApp::updateMainMenu(float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) {
		quit();
	}
	else if (input->isKeyDown(aie::INPUT_KEY_P)) {
		currentPlayState = START;
		currentGameState = GAME_PLAY;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_O)) {
		currentGameState = OPTIONS_MENU;
	}
	
	if (playButton->Update())
	{
		time(&start);
		//Replace this with whatever the button should do.
		currentPlayState = START;
		currentGameState= GAME_PLAY;
	}
	if (exitButton->Update())
	{
		//Replace this with whatever the button should do.
		quit();
	}
	if (optionsButton->Update())
	{
		//Replace this with whatever the button should do.
		currentGameState = OPTIONS_MENU;
	}

}

void AssignmentApp::updateOptionsMenu(float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();
	if (mainMenuButton->Update())
	{
		//Replace this with whatever the button should do.
		currentGameState = MAIN_MENU;
	}
}

void AssignmentApp::updateGamePlay(float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) {
		quit();
	}
	else if (input->isKeyDown(aie::INPUT_KEY_G)) {
		correctOrder.clear();
		currentGameState = GAME_OVER;
	}
	int newSelection = 0;
	bool update = false;

	switch (currentPlayState)
	{
	case START:
		for (int i = 0; i < 4; i++)
		{
			simonBtn[i].HoverOff();
		}
		currentPlaying = 0;		// Resets current playing number
		userEntered.clear();	// Resets the user enter options.
		time(&end);
		if (first) {
			if (difftime(end, start) >= waitTime) {
				first = false;
			}
		}
		else {
			time(&start);
			newSelection = rand() % (4);	// Randomly selects a number to be between 0-3 
			correctOrder.pushToEnd(newSelection);	// Pushes selection onto dynamic array
			currentPlayState = PLAYSEQUENCE;	// Changes play state to PLAYSEQUENCE
		}
		wait = false;
		break;
	case PLAYSEQUENCE:
		if (currentPlaying < correctOrder.getCount()){	// Checks to make sure playing in range of lsit
			time(&end);	// Gets the current time and assigns to end
			if (wait) {
				if (difftime(end, start) >= waitTime) {
					simonBtn[correctOrder[currentPlaying]].HoverOff();
					currentPlaying++;
					wait = false;
					time(&start);
				}
			}
			else {
				if (difftime(end, start) >= waitTime) {
					time(&start);
					wait = true;
					simonBtn[correctOrder[currentPlaying]].HoverOn();
					simonBtn[correctOrder[currentPlaying]].PlaySound();
				}
				break;
			}
		}else {
			currentPlayState = PLAYERTURN;
		}
		break;
	case PLAYERTURN:
		for (int i = 0; i < 4; i++)
		{
			if (simonBtn[i].Update()) {
				userEntered.pushToEnd(simonBtn[i].getNumber());
				newSelection = i;
				update = true; 
				i = 4;
			}
		}
		if (update) {
			if (CheckGameover() == 1) {
				PlayWrongAnswerSound();
				currentGameState = GAME_OVER;
			}
			else if (CheckGameover() == 2) {
				simonBtn[newSelection].PlaySound();
				//correctAnswers = userEntered.getCount();
				updateScore = true;
				first = true;
				time(&start);
				currentPlayState = START;
			}
			else {
				simonBtn[newSelection].PlaySound();
				//updateScore = true;
				//correctAnswers = userEntered.getCount();
			}
		}
		break;
	case END:
		break;
	default:
		break;
	}

}

int AssignmentApp::CheckGameover() {
	for (int i = 0; i < userEntered.getCount(); i++)
	{
		if (userEntered[i] != correctOrder[i]) {
			correctOrder.clear();	// Resets the user enter options.
			return 1;
		}
	}
	if (userEntered.getCount() >= correctOrder.getCount()) {
		return 2;
	}
	return 0;
}

void AssignmentApp::PlayWrongAnswerSound() {
	sound.setBuffer(buffer);
	sound.play();
}

void AssignmentApp::updateGameOver(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) {
		quit();
	}
	if (mainMenuButton->Update())
	{
		//Replace this with whatever the button should do.
		currentGameState = MAIN_MENU;
	}
}

void AssignmentApp::updateScoreBoard(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) {
		quit();
	}
	else if (input->isKeyDown(aie::INPUT_KEY_M)) {
		currentGameState = MAIN_MENU;
	}
}

void AssignmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();


	// Draw each background
	for (int i = 0; i < 3; i++)
	{
		background[i].Draw(m_2dRenderer);
	}

	// draw your stuff here!

	switch (currentGameState)
	{
	case SPLASH_SCREEN:
		drawSplashScreen(m_2dRenderer);
		break;
	case MAIN_MENU:
		drawMainMenu(m_2dRenderer);
		break;
	case GAME_PLAY:
		drawGamePlay(m_2dRenderer);
		break;
	case OPTIONS_MENU:
		drawOptionsMenu(m_2dRenderer);
		break;
	case GAME_OVER:
		drawGameOver(m_2dRenderer);
		break;
	case SCORE_BOARD:
		drawScoreBoard(m_2dRenderer);
		break;
	default:
		break;
	}
	
	// done drawing sprites
	m_2dRenderer->end();
}

void AssignmentApp::drawText(aie::Renderer2D* renderer, char textToDisplay[], aie::Font* currentFont, float xOffset, float yOffset){
	float textWidth = currentFont->getStringWidth(textToDisplay);
	float textHeight = currentFont->getStringHeight(textToDisplay);
	float centredPosX = xOffset - (textWidth * 0.5f) + 2;
	float centredPosY = yOffset - (textHeight * 0.5f) + 5;

	renderer->drawText(currentFont, textToDisplay, centredPosX, centredPosY);
}

void AssignmentApp::drawSplashScreen(aie::Renderer2D* renderer) {

	
	drawText(renderer,"Simon", splashFont, getWindowWidth() / 2.0f, getWindowHeight() / 2.0f);
	drawText(renderer, "Press Enter", mainFont, getWindowWidth() / 2.0f, getWindowHeight() / 4.0f);
	drawText(renderer, "Press ESC to quit", mainFont, getWindowWidth() / 2.0f, 20.0f);

}

void AssignmentApp::drawMainMenu(aie::Renderer2D* renderer) {
	drawText(renderer, "Main Menu", headingFont, getWindowWidth() / 2.0f, getWindowHeight() *.75f);

	playButton->Draw(renderer);
	optionsButton->Draw(renderer);
	exitButton->Draw(renderer);
}

void AssignmentApp::drawGamePlay(aie::Renderer2D* renderer) {
	if (updateScore == true) {
		correctAnswers = userEntered.getCount();
		updateScore = false;
	}
	std::string scoreText =  "Score " + std::to_string(correctAnswers);
	char cString[10];
	strcpy(cString, scoreText.c_str());

	drawText(renderer, cString, mainFont, getWindowWidth() / 2.0f, getWindowHeight() *.9f);
	drawText(renderer, "Press G", mainFont, getWindowWidth() / 2.0f, getWindowHeight() / 5.0f);
	
	switch (currentPlayState)
	{
	case START:
		drawText(renderer, "Start", mainFont, getWindowWidth() / 2.0f, getWindowHeight() *.8f);
		break;
	case PLAYSEQUENCE:
		drawText(renderer, "Watch & Listen", mainFont, getWindowWidth() / 2.0f, getWindowHeight() *.8f);		
		break;
	case PLAYERTURN:
		drawText(renderer, "Your Turn", mainFont, getWindowWidth() / 2.0f, getWindowHeight() *.8f);
		break;
	case END:
		break;
	default:
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		simonBtn[i].Draw(renderer);
	}

}

void AssignmentApp::drawOptionsMenu(aie::Renderer2D* renderer) {
	drawText(renderer, "Options Menu", headingFont, getWindowWidth() / 2.0f, getWindowHeight()  *.75f);

	mainMenuButton->Draw(renderer);
}

void AssignmentApp::drawGameOver(aie::Renderer2D* renderer) {

	std::string scoreText = "Score " + std::to_string(correctAnswers);
	char cString[10];
	strcpy(cString, scoreText.c_str());

	drawText(renderer, cString, mainFont, getWindowWidth() / 2.0f, getWindowHeight() *.9f);
	drawText(renderer, "Game Over", splashFont, getWindowWidth() / 2.0f, getWindowHeight() / 2.0f);

	mainMenuButton->Draw(renderer);
}

void AssignmentApp::drawScoreBoard(aie::Renderer2D* renderer) {
	drawText(renderer, "Score", headingFont, getWindowWidth() / 2.0f, getWindowHeight()  *.75f);
	drawText(renderer, "Press M", mainFont, getWindowWidth() / 2.0f, getWindowHeight() / 5.0f);
}