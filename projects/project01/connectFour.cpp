#include "connectFour.h"

//Checks for characters and whether or not four of them match
bool ConnectFour::checkLine(char a, char b, char c, char d) {
	return (a != ' ' && a == b && a == c && a == d);
}

//Prints horizontal line for gameboard
void ConnectFour::horizontalLine(int width)
{
	std::cout << " +";
	for (int col = 0; col < width; col++) {
		std::cout << "---+";
	}
	std::cout << '\n';
}

//Initializes the game board and prepares it for play
void ConnectFour::makeBoard(const std::vector<std::vector<char>>& board) {
	size_t width = (board.at(0).empty() ? 0 : board.at(0).size());
	size_t height = board.size();

	//prints column numbers
	std::cout << "   ";
	for (int col = 0; col < width; col++) {
		std::cout << col + 1 << "   ";
	}
	std::cout << '\n';

	//prints row numbers
	for (int row = 0; row < height; row++) {

		//prints line between each row number
		horizontalLine(width);

		std::cout << row + 1 << "|";
		for (int col = 0; col < width; col++) {
			char symbol = board.at(row).at(col);
			std::cout << " " << symbol << " |";
		}
		std::cout << '\n';
	}

	//prints final row line
	horizontalLine(width);
}

//Handles turn logic, allowing players to take actions on their turn
void ConnectFour::play(std::vector<std::vector<char>>& board, const int& col, int& playerTurn) {
	size_t width = board.at(0).size();
	size_t height = board.size();
	int columnIndex = col - 1;

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
			if (playerTurn % 2 == 0) {
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

//Determines if the game is still ongoing or if there is a winner
GameState ConnectFour::gameStatus(std::vector<std::vector<char>> board) {
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
					return GameState::PLAYER_1_WINS;
				}
				else {
					return GameState::PLAYER_2_WINS;
				}
			}
			//Check for vertical win condition
			if (row <= height - 4 && checkLine(cell, board.at(row + 1).at(col), board.at(row + 2).at(col), board.at(row + 3).at(col))) {
				if (board.at(row).at(col) == 'X') {
					return GameState::PLAYER_1_WINS;
				}
				else {
					return GameState::PLAYER_2_WINS;
				}
			}
			//Check for diagonal win condition
			if (row <= height - 4 && col <= width - 4 && checkLine(cell, board.at(row + 1).at(col + 1), board.at(row + 2).at(col + 2), board.at(row + 3).at(col + 3))) {
				if (board.at(row).at(col) == 'X') {
					return GameState::PLAYER_1_WINS;
				}
				else {
					return GameState::PLAYER_2_WINS;
				}
			}
			//Check for diagonal win condition
			if (row >= 3 && col <= width - 4 && checkLine(cell, board.at(row - 1).at(col + 1), board.at(row - 2).at(col + 2), board.at(row - 3).at(col + 3))) {
				if (board.at(row).at(col) == 'X') {
					return GameState::PLAYER_1_WINS;
				}
				else {
					return GameState::PLAYER_2_WINS;
				}
			}
		}
	}

	//check if board is empty
	for (auto row : board) {
		for (int cell : row) {
			if (cell == ' ') {
				return GameState::ONGOING;
			}
		}
	}

	return GameState::DRAW;
}

//Get function with input validation
int ConnectFour::getInput(std::string prompt) {
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