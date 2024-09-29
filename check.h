#include<iostream>

char HorizontalCheck(char map[3][3])
{
	for (int y = 0; y < 3; y++)
	{
		if (map[0][y] == map[1][y] && map[2][y] == map[1][y]) return map[1][y];
	}
	return ' ';
}

char VerticalCheck(char map[3][3])
{
	for (int x = 0; x < 3; x++)
	{
		if (map[x][0] == map[x][1] && map[x][2] == map[x][1]) return map[x][1];
	}
	return ' ';
}

char CrossCheck(char map[3][3])
{
	if (map[0][0] == map[1][1] && map[1][1] == map[2][2]) return map[1][1];
	else if (map[0][2] == map[1][1] && map[1][1] == map[2][0]) return map[1][1];
	
	return ' ';
}

char CheckStatus(char map[3][3])
{
	char tmp_status, full_status = ' ';

	tmp_status = VerticalCheck(map);
	if (tmp_status != ' ') full_status = tmp_status;

	tmp_status = HorizontalCheck(map);
	if (tmp_status != ' ') full_status = tmp_status;

	tmp_status = CrossCheck(map);
	if (tmp_status != ' ') full_status = tmp_status;

	return full_status;
}