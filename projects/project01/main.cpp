#include "connectFour.h"

int main() {

	
	int playerTurn = 0;
	std::string prompt;
	ConnectFour game;
	GameState state = GameState::ONGOING;

	while (true) {
		std::cout << "Connect Four: Drop pieces in columns to make four in a row.\nCan win horizontally, vertically or diagonally\n";
		std::vector<std::vector<char>> gameBoard(6, std::vector<char>(7, ' '));

		while (state == GameState::ONGOING) {
			if (playerTurn % 2 == 0) {
				prompt = "Choose a column 1-7 (X): ";
			}
			else if (playerTurn % 2 == 1) {
				prompt = "Choose a column 1-7 (O): ";
			}
			game.makeBoard(gameBoard);
			game.play(gameBoard, game.getInput(prompt), playerTurn);
			state = game.gameStatus(gameBoard);
		}

		game.makeBoard(gameBoard);
		if (state == GameState::PLAYER_1_WINS) {
			std::cout << "Player 1 (X) wins!\n";
		}
		else if (state == GameState::PLAYER_2_WINS) {
			std::cout << "Player 2 (O) wins!\n";
		}
		else {
			std::cout << "It's a draw!\n";
		}

		int choice = game.getInput("1. Play again!\n0. Exit\n");
		if (choice == 1) {
			std::cout << "Restarting...\n";
			gameBoard.clear();
			state = GameState::ONGOING;
			continue;
		}
		else if (choice == 0) {
			return 0;
		}
	}

	return 0;
}