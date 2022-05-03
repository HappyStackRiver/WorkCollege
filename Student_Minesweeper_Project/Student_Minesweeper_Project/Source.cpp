#include <iostream>
#include "Board.h"
#include <string>
bool update(int x, int y,Board board)//helper function to help access all needed functions from the board class
{
	if (board.getBoardData(x, y) == 'm')
	{
		return true;//mine was hit
	}
	else if (board.getBoardData(x, y) == '0')
	{
		board.recursiveEmptyFill(x, y);// if empty field was hit enter recursive function
	}
	else if (board.getBoardData(x, y) == 'F') 
	{

	}
	else 
	{
		board.minecountTransfer(x, y);//number was hit
	}
	if (board.winLossTracker() == 1) {
		board.printBoard();
		return 1;
	}
	board.printBoard();
	return 0;
}
int main()
{
	Board game = Board();
	bool gameActive = true;

	int xInput;
	int yInput;
	int statusGame;
	std::string buffer;

	while (gameActive)
	{
		game.printBoard();
		std::cout << "Enter X coordinate: ";
		std::cin >> xInput;
		std::cout << "Enter Y coordinate: ";
		std::cin >> yInput;
		statusGame = update(xInput, yInput, game);
		if (statusGame == -1)
		{
			std::cout << "UNLUCKY YOU LOST. PRESS ANY KEY AND ENTER TO EXIT";
			std::cin >> buffer; 
			gameActive = false;
		}
		if (statusGame == 1)
		{
			std::cout << "YOU'RE TOO GOOD! YOU WON! PRESS ANY KEY AND ENTER TO EXIT";
			std::cin >> buffer;
			gameActive = false;
		}
	}
	return 0;
}