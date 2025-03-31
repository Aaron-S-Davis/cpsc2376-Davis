#include "game.h"

Game::Game() 
	: board(std::vector<std::vector<char>>(6, std::vector<char>(7, ' ')))
{

}

void Game::play(int move) {
	int width = board.at(0).size();
	int height = board.size();
	int columnIndex = move;

	if (columnIndex < 0 || columnIndex >= width) {
		std::cout << "Invalid column\n";
		return;
	}
	if (board.at(0).at(columnIndex) != ' ') {
		std::cout << "Column is full!\n";
		return;
	}

	for (int row = height - 1; row >= 0; row--) {
		if (board.at(row).at(columnIndex) == ' ') {
			if (turn() == P1_TURN) {
				board.at(row).at(columnIndex) = 'X';
			}
			else {
				board.at(row).at(columnIndex) = 'O';
			}
			playerTurn++;
			return;
		}
	}
}

Game::PlayerTurn Game::turn() const {
	if (playerTurn % 2 == 0) {
		return P1_TURN;
	}
	else {
		return P2_TURN;
	}
}

bool Game::checkLine(char a, char b, char c, char d) const {
	return (a != ' ' && a == b && a == c && a == d);
}

Game::Status Game::status() const {
	size_t width = board.at(0).size();
	size_t height = board.size();

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			char cell = board.at(row).at(col);

			//Skips iteration if there is no possibility of a win
			if (cell == ' ') continue;

			//Check for horizontal win condition
			if (col <= width - 4 && checkLine(cell, board.at(row).at(col + 1), board.at(row).at(col + 2), board.at(row).at(col + 3))) {
				if (board.at(row).at(col) == 'X') {
					return PLAYER_1_WINS;
				}
				else {
					return PLAYER_2_WINS;
				}
			}
			//Check for vertical win condition
			if (row <= height - 4 && checkLine(cell, board.at(row + 1).at(col), board.at(row + 2).at(col), board.at(row + 3).at(col))) {
				if (board.at(row).at(col) == 'X') {
					return PLAYER_1_WINS;
				}
				else {
					return PLAYER_2_WINS;
				}
			}
			//Check for diagonal win condition
			if (row <= height - 4 && col <= width - 4 && checkLine(cell, board.at(row + 1).at(col + 1), board.at(row + 2).at(col + 2), board.at(row + 3).at(col + 3))) {
				if (board.at(row).at(col) == 'X') {
					return PLAYER_1_WINS;
				}
				else {
					return PLAYER_2_WINS;
				}
			}
			//Check for diagonal win condition
			if (row >= 3 && col <= width - 4 && checkLine(cell, board.at(row - 1).at(col + 1), board.at(row - 2).at(col + 2), board.at(row - 3).at(col + 3))) {
				if (board.at(row).at(col) == 'X') {
					return PLAYER_1_WINS;
				}
				else {
					return PLAYER_2_WINS;
				}
			}
		}
	}

	//check if board is empty
	for (auto row : board) {
		for (int cell : row) {
			if (cell == ' ') {
				return ONGOING;
			}
		}
	}

	return DRAW;
}

void Game::horizontalLine(int width) const {
	std::cout << " +";
	for (int col = 0; col < width; col++) {
		std::cout << "---+";
	}
	std::cout << '\n';
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
	int width = (game.board.at(0).empty() ? 0 : game.board.at(0).size());
	int height = game.board.size();

	//prints column numbers
	os << "   ";
	for (int col = 0; col < width; col++) {
		os << col + 1 << "   ";
	}
	os << '\n';

	//prints row numbers
	for (int row = 0; row < height; row++) {

		//prints line between each row number
		game.horizontalLine(width);

		os << row + 1 << "|";
		for (int col = 0; col < width; col++) {
			char symbol = game.board.at(row).at(col);
			os << " " << symbol << " |";
		}
		os << '\n';
	}

	//prints final row line
	game.horizontalLine(width);

	return os;
}
