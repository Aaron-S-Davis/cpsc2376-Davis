## **Board Game Tracker**
A program for managing and keeping track of board games in storage or lent out. Each board game has a title and each customer can have a board game(s). The user can add and remove board games and lend out board games to customers.

Key Nouns: 
BoardGame
name
Customer 
first name
last name
BoardGameTracker 
board games

Actions: 
Add board game
remove board game
lend board game
return board game
add customer
remove customer


```mermaid
classDiagram
	class BoardGame {
		+string gameName
		+getDescription() string
	}
	class Customer {
		+borrowedGames : vector<BoardGame>
		+string firstName
		+string lastName
		+getDescription() string
	}
	class BoardGameTracker {
		+boardGames : vector~BoardGame~
		+customers : vector~Customer~
		+addBoardGame(boardGame : BoardGame) void
		+removeBoardGame(gameName : string) void
		+addCustomer(customer : Customer) void
		+removeCustomer(firstName : string, lastName : string) void
		+lendBoardGame(gameName : string, firstName : string, lastName : string) void
		+returnBoardGame(gameName : string, firstName : string, lastName : string) void
		+listBoardGames() void
	}
	BoardGameTracker --> BoardGame : manages
	BoardGameTracker --> Customer : manages
	Customer --> BoardGame : uses
```
