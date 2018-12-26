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

	for (int nspawned = 0; nspawned < nBombs; ++nspawned)
	{
		Vei2 pos;
		do {
			pos.x = xDist(rng);
			pos.y = yDist(rng);
		} while (block.at(pos.y*fieldSize + pos.x).hasBomb);
		block[pos.y*fieldSize + pos.x].hasBomb = true;
	}
}

void MemeField::Draw(Graphics & gfx)
{
	Vei2 pos;
	for (int x = 0; x < fieldSize; ++x)
		for (int y = 0; y < fieldSize; ++y)
		{
			pos.x = x * SpriteCodex::tileSize;
			pos.y = y * SpriteCodex::tileSize;
			SpriteCodex::DrawTile0(pos, gfx);
		}
}
