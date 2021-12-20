#include "knight/Knight.h"

#include <iostream>
#include <assert.h>

int main()
{
	KnightTravail::Knight* knight = nullptr;
	assert(knight = new KnightTravail::Knight());

	knight->KnightTravail();

	delete knight;
	return 0;
}