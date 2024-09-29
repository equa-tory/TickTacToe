#include <iostream>

void PrintMap(char map[3][3])
{
	// Vertical
	for (int i = 0; i < 3; i++)
	{
		// Horizontal
		for (int j = 0; j < 3; j++) {
			// Print cell
			if (map[j][i] != 'n') std::cout << map[j][i];
			else std::cout << ' ';

			// Print hor break
			if (j < 2) std::cout << "|";
			else std::cout << "\n";
		}
		// Print ver break
		if (i < 2) std::cout << "-----\n";
	}
	std::cout << std::endl;
}
void ClearMap(char map[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[i][j] = 'n';
		}
	}
}

bool SetMark(char map[3][3], int x, int y, char sym)
{
	map[x][y] = sym;
	system("cls");
	PrintMap(map);

	// Check for possible win
	char status;
	status = CheckStatus(map);
	if (status != 'n')
	{
		cout << "====================================\n";
		cout << status << " has won!\n";
		return false;
	}
}