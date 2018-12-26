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
	public:
		void Draw(Graphics& gfx, const int pos1Dmapped);
		void Draw(Graphics& gfx, const Vei2& gridPos);
	};

private:
	int fieldSize;
	std::vector<Block> block;
};