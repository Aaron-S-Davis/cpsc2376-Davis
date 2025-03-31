#include "game.h"

int getInput(std::string prompt);

int main() {

	std::string prompt;

	while (true) {
		std::cout << "Connect Four: Drop pieces in columns to make four in a row.\nCan win horizontally, vertically or diagonally\n";

		Game* game = new Game;

		while (game->status() == game->ONGOING) {
			if (game->turn() == game->P1_TURN) {
				prompt = "Choose a column 1-7 (X): ";
			}
			else if (game->turn() == game->P2_TURN) {
				prompt = "Choose a column 1-7 (O): ";
			}
			std::cout << *game;
			game->play(getInput(prompt) - 1);
		}

		std::cout << *game;
		if (game->status() == game->PLAYER_1_WINS) {
			std::cout << "Player 1 (X) wins!\n";
		}
		else if (game->status() == game->PLAYER_2_WINS) {
			std::cout << "Player 2 (O) wins!\n";
		}
		else if (game->status() == game->DRAW) {
			std::cout << "It's a draw!\n";
		}

		int choice = getInput("1. Play again!\n0. Exit\n");
		delete game;
		if (choice == 1) {
			std::cout << "Restarting...\n";
			continue;
		}
		else if (choice == 0) {
			break;
		}
	}

	return 0;
}

int getInput(std::string prompt) {
	std::cout << prompt;
	int input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Error: invalid input.\nTry again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	//Ignore everything after first integer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}
