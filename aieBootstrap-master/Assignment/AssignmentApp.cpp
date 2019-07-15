#include "AssignmentApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

AssignmentApp::AssignmentApp() {

}



AssignmentApp::~AssignmentApp() {

}

bool AssignmentApp::startup() {
	float circleRadius = 75.0f;
	float circleOffSet = circleRadius*1.5;
	currentGameState = SPLASH_SCREEN;
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	splashFont = new aie::Font("../bin/font/pricedown_bl.ttf", 300);
	mainFont = new aie::Font("../bin/font/consolas.ttf", 32);
	headingFont = new aie::Font("../bin/font/pricedown_bl.ttf", 150);

	playButton = new Button("Play Game", getWindowWidth() / 2.0f, getWindowHeight() / 2.0f - 100.0f, 200.0f, 50.0f);
	optionsButton = new Button("Options", getWindowWidth() / 2.0f, getWindowHeight() / 2.0f - 155.0f, 200.0f, 50.0f);
	exitButton = new Button("Exit Game", getWindowWidth() / 2.0f, getWindowHeight() / 2.0f - 210.0f, 200.0f, 50.0f);
	mainMenuButton = new Button("Go Back", getWindowWidth() / 2.0f, getWindowHeight() / 2.0f - 100.0f, 200.0f, 50.0f);

	background = new ScrollingBackground[3];
	mainBackground = new aie::Texture("../bin/textures/cloud.png");
	for (int i = 0; i < 3; i++)
	{
		background[i] = ScrollingBackground(mainBackground->getWidth() / 2 + (mainBackground->getWidth()*i), 
						getWindowHeight() / 2, mainBackground);
	}

	circleOne = new CircleButton(1,getWindowWidth() / 2.0f+ circleOffSet, getWindowHeight() / 2.0f, circleRadius);
	circleOne->setColour(1.0f,0.0f,0.0f, 0.2f);
	circleTwo = new CircleButton(2, getWindowWidth() / 2.0f- circleOffSet, getWindowHeight() / 2.0f, circleRadius);
	circleTwo->setColour(0.0f, 1.0f, 0.0f, 0.2f);
	circleThree = new CircleButton(3, getWindowWidth() / 2.0f, getWindowHeight() / 2.0f+ circleOffSet, circleRadius);
	circleThree->setColour(0.0f, 0.0f, 1.0f, 0.2f);
	circleFour = new CircleButton(4, getWindowWidth() / 2.0f, getWindowHeight() / 2.0f- circleOffSet, circleRadius);
	circleFour->setColour(1.0f, 1.0f, 0.0f, 0.2f);

	return true;
}

void AssignmentApp::shutdown() {
	delete m_2dRenderer;
	delete splashFont;
	delete mainFont;
	delete headingFont;
	delete mainBackground;
	delete playButton;
	delete exitButton;
	delete optionsButton;
	delete mainMenuButton;
	delete circleOne;
	delete circleTwo;
	delete circleThree;
	delete circleFour;
	delete[] background;
}

void AssignmentApp::update(float deltaTime) {

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
	case SCORE_BOARD:
		updateScoreBoard(deltaTime);
		break;
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

	// Move Each background image
	for (int i = 0; i < 3; i++)
	{
		background[i].Move(50, deltaTime, i);
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
		currentGameState = GAME_PLAY;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_O)) {
		currentGameState = OPTIONS_MENU;
	}
	
	if (playButton->Update())
	{
		//Replace this with whatever the button should do.
		currentGameState=GAME_PLAY;
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
		currentGameState = GAME_OVER;
	}

	if (circleOne->Update())
	{
		//Replace this with whatever the button should do.
		sequence.push_back(circleOne->getNumber());
	}
	if (circleTwo->Update())
	{
		//Replace this with whatever the button should do.

		sequence.push_back(circleTwo->getNumber());
	}
	if (circleThree->Update())
	{
		//Replace this with whatever the button should do.

		sequence.push_back(circleThree->getNumber());
	}
	if (circleFour->Update())
	{
		//Replace this with whatever the button should do.

		sequence.push_back(circleFour->getNumber());
	}
}
void AssignmentApp::updateGameOver(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) {
		quit();
	}
	else if (input->isKeyDown(aie::INPUT_KEY_S)) {
		currentGameState = SCORE_BOARD;
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
	
	// Draw each background
	for (int i = 0; i < 3; i++)
	{
		background[i].Draw(renderer);
	}
	
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
	drawText(renderer, "Score", mainFont, getWindowWidth() / 2.0f, getWindowHeight() *.9f);
	drawText(renderer, "Press G", mainFont, getWindowWidth() / 2.0f, getWindowHeight() / 5.0f);

	circleOne->Draw(renderer);
	circleTwo->Draw(renderer);
	circleThree->Draw(renderer);
	circleFour->Draw(renderer);
}

void AssignmentApp::drawOptionsMenu(aie::Renderer2D* renderer) {
	drawText(renderer, "Options Menu", headingFont, getWindowWidth() / 2.0f, getWindowHeight()  *.75f);

	mainMenuButton->Draw(renderer);
}

void AssignmentApp::drawGameOver(aie::Renderer2D* renderer) {
	drawText(renderer, "Game Over", splashFont, getWindowWidth() / 2.0f, getWindowHeight() / 2.0f);
	drawText(renderer, "Press S", mainFont, getWindowWidth() / 2.0f, getWindowHeight() / 5.0f);
}

void AssignmentApp::drawScoreBoard(aie::Renderer2D* renderer) {
	drawText(renderer, "Score", headingFont, getWindowWidth() / 2.0f, getWindowHeight()  *.75f);
	drawText(renderer, "Press M", mainFont, getWindowWidth() / 2.0f, getWindowHeight() / 5.0f);
}