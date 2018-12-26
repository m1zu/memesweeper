#include "Memefield.h"
#include <assert.h>
#include <random>
#include "Vei2.h"
#include "SpriteCodex.h"

MemeField::MemeField(int nBombs, int fieldSize_in)
	:
	fieldSize(fieldSize_in),
	block(fieldSize*fieldSize)
{
	assert(nBombs > 0);
	assert(fieldSize > 0);
	assert(nBombs < fieldSize*fieldSize);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, fieldSize - 1);
	std::uniform_int_distribution<int> yDist(0, fieldSize - 1);

	for (int nSpawned = 0; nSpawned < nBombs; ++nSpawned)
	{
		Vei2 pos;
		do {
			pos.x = xDist(rng);
			pos.y = yDist(rng);
		} while (!block.at(pos.y*fieldSize + pos.x).hasBomb);
		block[pos.y*fieldSize + pos.x].hasBomb = true;
	}
}

void MemeField::Draw(Graphics & gfx)
{
	for (int i = 0; i < fieldSize*fieldSize; ++i)
	{
		block[i].
	}
}
