#ifndef BOARD_H
#define BOARD_H

class Board
{
	public:
		Board();//two arrays
		void printBoard();
		char getBoardData(int, int);
		void minecountTransfer(int, int);
		void recursiveEmptyFill(int, int);
		int nearbyMineCounter(int, int, int&);
		int winLossTracker();
	private:
		char** userBoard;
		char** minefield;
};
#endif