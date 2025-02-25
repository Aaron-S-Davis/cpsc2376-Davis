#pragma once
#include <vector>
#include <string>
#include <limits>
#include <iostream>

enum class GameState {
	ONGOING,
	PLAYER_1_WINS,
	PLAYER_2_WINS,
	DRAW
};

class ConnectFour {
public:
	static bool checkLine(char a, char b, char c, char d);

	void horizontalLine(int width);

	//Initializes the game board and prepares it for play
	void makeBoard(const std::vector<std::vector<char>>& board);

	//Handles turn logic, allowing players to take actions on their turn
	void play(std::vector<std::vector<char>>& board, const int& col, int& playerTurn);

	//Determines if the game is still ongoing or if there is a winner
	GameState gameStatus(std::vector<std::vector<char>> board);

	int getInput(std::string prompt);
};


