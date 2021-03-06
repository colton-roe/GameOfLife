#pragma once
#include <string>

class CellGrid
{
public:
	bool** cells;
	bool** buffer;
	int width;
	int height;

	CellGrid(int width, int height);

	void update();
	int getLiveNeighbors(int row, int col);

	void generate(int width, int height);
	void randomize();
	void clear();

	void save(std::string file);
	void load(std::string file);
};