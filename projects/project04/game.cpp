#include "game.h"

Game::Game() : board(std::vector<std::vector<char>>(6, std::vector<char>(7, BLANK))) {}

void Game::play(int move) {
	size_t width = board.at(0).size();
	size_t height = board.size();
	int columnIndex = move;

	if (columnIndex < 0 || columnIndex >= width) {
		std::cout << "Invalid column\n";
		return;
	}
	if (board.at(0).at(columnIndex) != BLANK) {
		std::cout << "Column is full!\n";
		return;
	}

	for (size_t row = height - 1; row >= 0; row--) {
		if (board.at(row).at(columnIndex) == BLANK) {
			if (turn() == P1_TURN) {
				board.at(row).at(columnIndex) = X;
			}
			else {
				board.at(row).at(columnIndex) = O;
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

			//skips iteration if there is no possibility of a win
			if (cell == BLANK) continue;

			//check for horizontal win condition
			if (col <= width - 4 && checkLine(cell, board.at(row).at(col + 1), board.at(row).at(col + 2), board.at(row).at(col + 3))) {
				if (board.at(row).at(col) == X) {
					return PLAYER_1_WINS;
				}
				else {
					return PLAYER_2_WINS;
				}
			}
			//check for vertical win condition
			if (row <= height - 4 && checkLine(cell, board.at(row + 1).at(col), board.at(row + 2).at(col), board.at(row + 3).at(col))) {
				if (board.at(row).at(col) == X) {
					return PLAYER_1_WINS;
				}
				else {
					return PLAYER_2_WINS;
				}
			}
			//check for diagonal win condition
			if (row <= height - 4 && col <= width - 4 && checkLine(cell, board.at(row + 1).at(col + 1), board.at(row + 2).at(col + 2), board.at(row + 3).at(col + 3))) {
				if (board.at(row).at(col) == X) {
					return PLAYER_1_WINS;
				}
				else {
					return PLAYER_2_WINS;
				}
			}
			//check for diagonal win condition
			if (row >= 3 && col <= width - 4 && checkLine(cell, board.at(row - 1).at(col + 1), board.at(row - 2).at(col + 2), board.at(row - 3).at(col + 3))) {
				if (board.at(row).at(col) == X) {
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
			if (cell == BLANK) {
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

int Game::moveCount() {
	int sum = 0;
	size_t width = board.at(0).size();
	size_t height = board.size();
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			sum += board[row][col] == X;
		}
	}
	return sum;
}

void Game::draw(Engine* e, int move)
{
	int tokenRadius = 30;
	Cell current = getCurrentToken();
	for (int row = 0; row < board.size(); ++row) {
		for (int col = 0; col < board.at(0).size(); ++col) {
			int cx = 50 + 100 * col;
			int cy = 50 + 100 * row;
			e->drawRectangle(cx, cy, 90, 90, { 20,25,154,255 });
			if (board[row][col] != BLANK)
				//shadows
				e->drawCircle(cx + 5, cy + 5, tokenRadius, { 0,0,0,64 });
			if (board[row][col] == X)
				//player 1
				e->drawCircle(cx, cy, tokenRadius, { 215,25,25,255 });
			else if (board[row][col] == O)
				//player 2
				e->drawCircle(cx, cy, tokenRadius, { 210,210,50,255 });
			//vertical circle shadows for hovering
			else if (move == col) {
				if (current == X) e->drawCircle(cx, cy, tokenRadius, { 215,25,25,128 });
				else e->drawCircle(cx, cy, tokenRadius, { 210,210,50,125 });
			}
		}
	}
}

Game::Cell Game::getCurrentToken() const {
	int count = 0;
	for (const auto& row : board) {
		for (auto cell : row) {
			if (cell != BLANK)
				++count;
		}
	}
	return (count % 2 == 0) ? X : O;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
	size_t width = (game.board.at(0).empty() ? 0 : game.board.at(0).size());
	size_t height = game.board.size();

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
			char symbol = ' ';
			if (game.board[row][col] == game.X) {
				symbol = 'X';
			}
			else if (game.board[row][col] == game.O) {
				symbol = 'O';
			}
			os << " " << symbol << " |";
		}
		os << '\n';
	}

	//prints final row line
	game.horizontalLine(width);

	return os;
}

