#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

Board::Board()
{
	int x = 30; //X coordinate length
	int y = 16; //Y coordinate length
	int z = 99; //number of mines

	int a; //x coordinate for mine
	int b; //y coordinate for mine

	userBoard = new char* [x];//an array of 30 spaces for user; X coordinate
	minefield = new char* [y];//an array of 30 spaces for minefield; X coordinate

	for (int i = 0; i < 30; i++)//for loop to fill board in Y coordinate direction
	{
		userBoard[i] = new char[x];
		minefield[i] = new char[x];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			userBoard[i][j] = 'E';//closest thing to a box fills in the board
			minefield[i][j] = 'E';//closest thing to a box fills in the board
		}
	}

	for (int k = 0; k < z; k++)//for loop that assigns k(99 mines) to the board in random places
	{
		while (true)
		{
			a = rand() % x;
			b = rand() % y;

			if (minefield[a][b] != 'm')//checks to see if there is a mine at the random place
			{
				minefield[a][b] = 'm';//assigns a mine to random location
				break;
			}

		}
	}
	for (int l = 0; l < x; l++)
	{
		for (int p = 0; p < y; p++)
		{
			if (minefield[l][p] != 'm')
			{
				int minecount = 0;
				nearbyMineCounter(x - 1, y - 1, minecount);
				nearbyMineCounter(x, y - 1, minecount);
				nearbyMineCounter(x + 1, y - 1, minecount);
				nearbyMineCounter(x - 1, y, minecount);
				nearbyMineCounter(x + 1, y, minecount);
				nearbyMineCounter(x - 1, y + 1, minecount);
				nearbyMineCounter(x, y + 1, minecount);
				nearbyMineCounter(x + 1, y + 1, minecount);
				char c = '0' + minecount;//this works because at any given space, there is only 9 spots able to be filled in a 3x3, and ascii character sets allows this to work
				minefield[l][p] = c;
			}
		}
	}
}
void Board::printBoard()
{
	int yside = 0;
	std::cout << "- 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16" << std::endl;
	for (int x = 0; x < 30; x++)
	{
		std::cout << yside << " ";
		for (int y = 0; y < 16; y++)
		{
			std::cout << userBoard[x][y] << " ";//prints user board
		}
		yside++;
		std::cout << std::endl;
	}
}
char Board::getBoardData(int x, int y)//helper function retrieves the data at the minefield at x and y
{
	int sizex = 30;
	int sizey = 16;

	if (x < sizex && y < sizey && x >= 0 && y >= 0)
	{
		return minefield[x][y];
	}

	return 'F';//has to return something, so if the inputs are out of bounds, will return F and this will be used later for catching errors

}
void Board::minecountTransfer(int x, int y)//copy minecount from the minefield to the user board
{
	minefield[x][y] = userBoard[x][y];//assuming minefield at x,y has a minecount, transfer it over 
}
void Board::recursiveEmptyFill(int x, int y)
{
	int sizex = 30;
	int sizey = 16;
	if (x >= 0 && y >= 0 && x < sizex && y < sizey)
	{
		if (minefield[x][y] == '0' && userBoard[x][y] == 'E') {
			userBoard[x][y] = '0';
			recursiveEmptyFill(x - 1, y - 1);
			recursiveEmptyFill(x, y - 1);
			recursiveEmptyFill(x + 1, y - 1);
			recursiveEmptyFill(x - 1, y);
			recursiveEmptyFill(x + 1, y);
			recursiveEmptyFill(x - 1, y + 1);
			recursiveEmptyFill(x, y + 1);
			recursiveEmptyFill(x + 1, y + 1);
		}
		else {
			minecountTransfer(x, y);
		}
	}
}
int Board::nearbyMineCounter(int xloc, int yloc, int& mines)//helper function for adding minecounts to the board
{
	int sizex = 30;
	int sizey = 16;
		if(xloc >= 0 && xloc < sizex && yloc >= 0 && yloc < sizey)
		{
			if (minefield[xloc][yloc] == 'm')
			{
				mines++;
			}
		}
		return 0;
}
int Board::winLossTracker()
{
	int sizex = 30;
	int sizey = 16;

	for (int x = 0; x < sizex; x++)
	{
		for (int y = 0; x < sizey; y++)
		{
			if (userBoard[x][y] == 'E') {
				if (minefield[x][y] != 'm')
				{
					return 0; //game is still active
				}
				if (minefield[x][y] == 'm')
				{
					return -1;//game has been lost
				}
			}
		}
	}
	return 1; //game has been won
}