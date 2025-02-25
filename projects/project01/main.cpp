#include "connectFour.h"

int main() {

	std::vector<std::vector<char>> gameBoard(6, std::vector<char>(7, ' '));
	int playerTurn = 0;
	ConnectFour game;
	GameState state = GameState::ONGOING;

	while (true) {
		std::cout << "Connect Four: Drop pieces in columns to make four in a row.\nCan win horizontally, vertically or diagonally\n";

		while (state == GameState::ONGOING) {
			game.makeBoard(gameBoard);
			game.play(gameBoard, game.getInput("Choose a column 1-7: "), playerTurn);
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
		return 0;
	}

	return 0;
}