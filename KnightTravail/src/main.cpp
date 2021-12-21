#include "knight/Knight.h"

#include <iostream>
#include <assert.h>
#include <stack>
int main()
{
	std::unique_ptr<KnightTravail::Knight> knight = std::make_unique<KnightTravail::Knight>();

	knight->KnightTravail();

	return 0;
}