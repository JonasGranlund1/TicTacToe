#include <iostream>
#include <array>
#include <string>

int const ROWS = 3;
int const COLS = 3;

void runGame();
void initializeBoard(std::string board[ROWS][COLS]);
void printBoard(std::string board[ROWS][COLS]);
void getUserInput(std::string& userInput, std::string currentPlayer);
void updateBoard(std::string board[ROWS][COLS], std::string currentPlayer, std::string userInput);

int main() {

	runGame();

	return 0;
}

void runGame() {

	std::string board[ROWS][COLS];
	std::string userInput;
	initializeBoard(board);
	bool boardIsFull = false;
	std::string currentPlayer = "X";

	// Main loop
	while (!boardIsFull) {
		printBoard(board);
		getUserInput(userInput, currentPlayer);
		updateBoard(board, currentPlayer, userInput);
		//board[0][0] = "X";
		std::cout << userInput;


		if (currentPlayer == "X") {
			currentPlayer = "O";
		}
		else if (currentPlayer == "O") {
			currentPlayer = "X";
		}
	}
}

void initializeBoard(std::string board[ROWS][COLS]) {
	
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = " ";
		}
	}
}

void printBoard(std::string board[ROWS][COLS]) {
	
	std::cout << "The current board looks like: " << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			
			if (j != 2) {
				std::cout << board[i][j] << " | ";
			}
			else {
				std::cout << board[i][j];
			}
		}
		std::cout << std::endl;
		if (i != 2) {
			std::cout << "- - - - -";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void getUserInput(std::string& userInput, std::string currentPlayer){

	bool inputIsValid = false;

	while (!inputIsValid) {
		std::cout << "It's " << currentPlayer << "'s turn to play." << std::endl;
		std::cout << "Please enter the row THEN the column, each from 0, 1 or 2, separated by a space. " << std::endl;
		std::getline(std::cin, userInput);

		std::cout << std::endl;

		if (userInput.length() > 3) {
			std::cout << "Invalid input: too many characters." << std::endl;
			continue;
		}
		else if (userInput.length() < 3) {
			std::cout << "Invalid input: Too few characters." << std::endl;
			continue;
		}
		if (userInput[0] != '0' && userInput[0] != '1' && userInput[0] != '2') {
			std::cout << "Please only enter numbers between 0-2" << std::endl;
		}
		else if (userInput[2] != '0' && userInput[2] != '1' && userInput[2] != '2'){
			std::cout << "Please only enter numbers between 0-2" << std::endl;		
		}
		else if (userInput[1] != ' ') {
			std::cout << "Please use space as a separator" << std::endl;
		}
		else {
			inputIsValid = true;
		}
	}
}

void updateBoard(std::string board[ROWS][COLS], std::string currentPlayer, std::string userInput){
	std::cout << userInput[0] << userInput[2] << std::endl;

	int row = userInput[0] - '0';
	int col = userInput[2] - '0';


	board[row][col] = currentPlayer;

}
