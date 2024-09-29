#include<time.h>
#include<iostream>

int RandomRange(int min, int max)
{
	return rand() % (max + 1 - min) + min;
}