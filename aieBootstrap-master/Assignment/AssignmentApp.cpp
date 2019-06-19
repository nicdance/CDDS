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
	mainFont = new aie::Font("../bin/font/consolas.ttf", 32);
	headingFont = new aie::Font("../bin/font/consolas.ttf", 100);

	menuButton = new Button("Play", 400, 400, 120, 50);

	return true;
}

void AssignmentApp::shutdown() {
	delete mainFont;
	delete headingFont;
	delete m_2dRenderer;
	delete menuButton;
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

	if (menuButton->Update())
	{
		//Replace this with whatever the button should do.
		currentGameState=GAME_PLAY;
	}
}


void AssignmentApp::updateOptionsMenu(float deltaTime) {
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

void AssignmentApp::drawSplashScreen(aie::Renderer2D* renderer) {
	renderer->drawText(headingFont, "Simon", 530, 310);
	renderer->drawText(headingFont, "Press Enter", 530, 210);
	m_2dRenderer->drawText(mainFont, "Press ESC to quit", 0, 0);
}

void AssignmentApp::drawMainMenu(aie::Renderer2D* renderer) {
	renderer->drawText(headingFont, "Main Menu", 530, 310);
	renderer->drawText(headingFont, "Press P or O", 530, 210);
	m_2dRenderer->drawText(mainFont, "Press ESC to quit", 0, 0);

	menuButton->Draw(renderer);
}

void AssignmentApp::drawGamePlay(aie::Renderer2D* renderer) {
	renderer->drawText(headingFont, "Game Play", 530, 310);
	renderer->drawText(headingFont, "Press G", 530, 210);
	m_2dRenderer->drawText(mainFont, "Press ESC to quit", 0, 0);
}

void AssignmentApp::drawOptionsMenu(aie::Renderer2D* renderer) {
	renderer->drawText(headingFont, "Options Menu", 530, 310);
	renderer->drawText(headingFont, "Press M", 530, 210);
	m_2dRenderer->drawText(mainFont, "Press ESC to quit", 0, 0);
}

void AssignmentApp::drawGameOver(aie::Renderer2D* renderer) {
	renderer->drawText(headingFont, "Game Over", 530, 310);
	renderer->drawText(headingFont, "Press S", 530, 210);
	m_2dRenderer->drawText(mainFont, "Press ESC to quit", 0, 0);
}

void AssignmentApp::drawScoreBoard(aie::Renderer2D* renderer) {
	renderer->drawText(headingFont, "Score", 530, 310);
	renderer->drawText(headingFont, "Press M", 530, 210);
	m_2dRenderer->drawText(mainFont, "Press ESC to quit", 0, 0);
}