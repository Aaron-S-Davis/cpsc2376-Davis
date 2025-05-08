#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include "Engine.h"

class Game {
public:
	enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
	enum PlayerTurn { P1_TURN, P2_TURN };
	enum Cell { BLANK, X, O };

	//constructs a new game
	Game();

	//game destructor
	~Game() = default;

	//executes move for current player
	void play(int move);

	//checks which player's turn it is
	PlayerTurn turn() const;

	bool checkLine(char a, char b, char c, char d) const;

	//determines if game is still ongoing
	Status status() const;

	void horizontalLine(int width) const;

	int moveCount();

	void draw(Engine* e, int move = -1);

	Game::Cell getCurrentToken() const;

	//provides method for printing the board
	friend std::ostream& operator<<(std::ostream& os, const Game& game);

	//getter
	std::vector<std::vector<char>> getBoard() const;

private:
	std::vector<std::vector<char>> board;
	int playerTurn{ 0 };
};