#pragma once 

#include "Graphics.h"

#include <vector>

class MemeField {
public:
	MemeField(int nBombs, int fieldSize_in);
public:
	void Draw(Graphics& gfx);
private:
	class Block {
	public:
		enum class BlockStatus {
			hidden,
			flagged,
			revealed
		};
	public:
		BlockStatus status = BlockStatus::hidden;
		bool hasBomb = false;
	};

private:
	int fieldSize;
	std::vector<Block> block;
};