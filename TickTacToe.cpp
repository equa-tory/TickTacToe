#include <iostream>
using namespace std;

void IgnoreCinErr()
{
	if (cin.fail())
	{
		cin.clear();
		std::cin.ignore(32767, '\n');
	}
}

#include"input.h"
#include"rand.h"
#include"check.h"
#include"map.h"

int main()
{
	srand(time(0));

	// Variables
	int opponentSelection;
	int x, y;
	char map[3][3];
	bool isRunning = true;
	int moves = 0;


	// Fill map with n (none)
	ClearMap(map);
	
	// Opponent input
	cout << "Select opponent (1-ai, 2-local player):";
	do
	{
		cin >> opponentSelection;
		IgnoreCinErr();
	}
	while (opponentSelection != 1 && opponentSelection != 2);
	system("cls");

	// First render
	PrintMap(map);

	// GAME
	while (isRunning)
	{
		// Players' move
		do
		{
			x = InputX();
			y = InputY();
		} while (map[x][y] != 'n');
		moves++;
		if (moves >= 9) {
			cout << "Draw!\n";
			break;
		}
		
		isRunning = SetMark(map, x, y, 'x');
		if (!isRunning) break;

		// Opponents' move
		if (opponentSelection == 1)
		{
			// AI
			do
			{
				x = RandomRange(0, 2);
				y = RandomRange(0, 2);
			} while (map[x][y] != 'n');

			isRunning = SetMark(map, x, y, 'o');
			if (!isRunning) break;
		}
		else
		{
			// Player
			do
			{
				x = InputX();
				y = InputY();
			} while (map[x][y] != 'n');

			isRunning = SetMark(map, x, y, 'o');
			if (!isRunning) break;
		}
		moves++;
		if (moves >= 9) {
			cout << "Draw!\n";
			break;
		}
	}
	
	system("pause");
	return 0;
}