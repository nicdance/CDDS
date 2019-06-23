#include "AssignmentApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

AssignmentApp::AssignmentApp() {

}

AssignmentApp::~AssignmentApp() {

}

bool AssignmentApp::startup() {
	currentGameState = SPLASH_SCREEN;
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	splashFont = new aie::Font("../bin/font/pricedown_bl.ttf", 300);
	mainFont = new aie::Font("../bin/font/consolas.ttf", 32);
	headingFont = new aie::Font("../bin/font/pricedown_bl.ttf", 150);

	playButton = new Button("Play Game", getWindowWidth() / 2, getWindowHeight() / 2 - 100, 200, 50);
	optionsButton = new Button("Options", getWindowWidth() / 2, getWindowHeight() / 2 - 155, 200, 50);
	exitButton = new Button("Exit Game", getWindowWidth() / 2, getWindowHeight() / 2 - 210, 200, 50);

	mainMenuButton = new Button("Go Back", getWindowWidth() / 2, getWindowHeight() / 2 - 100, 200, 50);
	return true;
}

void AssignmentApp::shutdown() {
	delete mainFont;
	delete headingFont;
	delete m_2dRenderer;
	delete playButton;
	delete mainMenuButton;
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

	//Calculating the centred text position is a bit fiddly.
	float textWidth = currentFont->getStringWidth(textToDisplay);
	float textHeight = currentFont->getStringHeight(textToDisplay);
	float centredPosX = xOffset - (textWidth * 0.5f) + 2;
	float centredPosY = yOffset - (textHeight * 0.5f) + 5;

	renderer->drawText(currentFont, textToDisplay, centredPosX, centredPosY);
}
void AssignmentApp::drawSplashScreen(aie::Renderer2D* renderer) {
	drawText(renderer,"Simon", splashFont, getWindowWidth() / 2, getWindowHeight() / 2);
	drawText(renderer, "Press Enter", mainFont, getWindowWidth() / 2, getWindowHeight() / 3);
	drawText(renderer, "Press ESC to quit", mainFont, getWindowWidth() / 2, 20);
}

void AssignmentApp::drawMainMenu(aie::Renderer2D* renderer) {
	drawText(renderer, "Main Menu", headingFont, getWindowWidth() / 2, getWindowHeight() / 2);

	playButton->Draw(renderer);
	optionsButton->Draw(renderer);
	exitButton->Draw(renderer);
}

void AssignmentApp::drawGamePlay(aie::Renderer2D* renderer) {
	drawText(renderer, "Game Play", headingFont, getWindowWidth() / 2, getWindowHeight() / 2);
	drawText(renderer, "Press G", mainFont, getWindowWidth() / 2, getWindowHeight() / 3);
}

void AssignmentApp::drawOptionsMenu(aie::Renderer2D* renderer) {
	drawText(renderer, "Options Menu", headingFont, getWindowWidth() / 2, getWindowHeight() / 2);

	mainMenuButton->Draw(renderer);
}

void AssignmentApp::drawGameOver(aie::Renderer2D* renderer) {
	drawText(renderer, "Game Over", headingFont, getWindowWidth() / 2, getWindowHeight() / 2);
	drawText(renderer, "Press S", mainFont, getWindowWidth() / 2, getWindowHeight() / 3);
}

void AssignmentApp::drawScoreBoard(aie::Renderer2D* renderer) {
	drawText(renderer, "Score", headingFont, getWindowWidth() / 2, getWindowHeight() / 2);
	drawText(renderer, "Press M", mainFont, getWindowWidth() / 2, getWindowHeight() / 3);
}