#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "game.h"
#include "Engine.h"
#include "main.h"

void drawWinScreen(Game& game, Engine& engine)
{
	auto status = game.status();
	std::string msg;
	SDL_Color bgColor;
	SDL_Color textColor;
	if (status == Game::PLAYER_1_WINS)
	{
		msg = "Player 1 won in " + std::to_string(game.moveCount()) + " moves!";
		bgColor = { 0,0,0,200 };
		textColor = { 215,25,25,255 };
	}

	else if (status == Game::PLAYER_2_WINS)
	{
		msg = "Player 2 won in " + std::to_string(game.moveCount()) + " moves!";
		bgColor = { 0,0,0,200 };
		textColor = { 210,210,50,255 };
	}
	else
	{
		msg = "DRAW";
		bgColor = { 0,0,0,200 };
		textColor = { 255,255,255,255 };
	}
	engine.drawRectangle(350, 350, 700, 700, bgColor);
	engine.drawText(msg, 350, 350, textColor);
	engine.drawText("Press space to play again. Esc to quit.", 350, 650, textColor);
}

int main() {

	Engine engine;
	Game game;
	bool running = true;
	SDL_Event event;
	int move = 0;

	while (running)
	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					if (game.status() != Game::ONGOING) game = Game();
				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					move = event.motion.x / 100;
					if (game.status() != Game::ONGOING) move = -1;
				}
			}

			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				int move = event.button.x / 100;
				if (game.status() == Game::ONGOING)
				{
					game.play(move);
					engine.playSound();
				}
				//move = event.motion.move;
			}

			else if (event.type == SDL_MOUSEMOTION)
			{
				move = event.motion.x / 100;
				if (game.status() != Game::ONGOING)
				{
					move = -1;
				}
				//move = event.motion.move;
			}
		}




		engine.clear();
		game.draw(&engine, move);

		if (game.status() != Game::ONGOING) drawWinScreen(game, engine);


		engine.flip();
	}

	//while (true) {
	//	std::cout << "Connect Four: Drop pieces in columns to make four in a row.\nCan win horizontally, vertically or diagonally\n";

	//	//creates new game pointer with blank gameboard
	//	Game* game = new Game;
	//	std::string prompt;

	//	while (game->status() == game->ONGOING) {
	//		if (game->turn() == game->P1_TURN) {
	//			prompt = "Choose a column 1-7 (X): ";
	//		}
	//		else if (game->turn() == game->P2_TURN) {
	//			prompt = "Choose a column 1-7 (O): ";
	//		}
	//		//output gameboard after every turn
	//		std::cout << *game;
	//		game->play(getInput(prompt) - 1);
	//	}

	//	//shows final gameboard
	//	std::cout << *game;
	//	//checks game status function for win condition
	//	if (game->status() == game->PLAYER_1_WINS) {
	//		std::cout << "Player 1 (X) wins!\n";
	//	}
	//	else if (game->status() == game->PLAYER_2_WINS) {
	//		std::cout << "Player 2 (O) wins!\n";
	//	}
	//	else if (game->status() == game->DRAW) {
	//		std::cout << "It's a draw!\n";
	//	}

	//	int choice = getInput("1. Play again!\n0. Exit\n");
	//	//deletes current game so a new one can be created
	//	delete game;
	//	if (choice == 1) {
	//		std::cout << "Restarting...\n";
	//		continue;
	//	}
	//	else if (choice == 0) {
	//		break;
	//	}
	//}

	return 0;
}

////basic input validation for integer input
//int getInput(std::string prompt) {
//	std::cout << prompt;
//	int input;
//	std::cin >> input;
//	while (std::cin.fail()) {
//		std::cout << "Error: invalid input.\nTry again: ";
//		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		std::cin >> input;
//	}
//	//Ignore everything after first integer
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	return input;
//}