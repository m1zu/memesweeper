#pragma once

#include <vector>

class MemeField {
public:
	MemeField(int nBombs, int fieldSize_in);
public:

private:
	class Block {
	public:
		enum class BlockStatus {
			hidden,
			flagged,
			revealed
		};
		BlockStatus status = BlockStatus::hidden;
		bool hasBomb = false;
	};

private:
	int fieldSize;
	std::vector<Block> block;
};