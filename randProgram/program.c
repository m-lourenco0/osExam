#include "program.h"
#include <stdio.h>
#include <stdlib.h>

int aleatorio (int x, int y)
{
	int i = x + ( rand() % y );
	return i;
}