#include <stdbool.h>
#include <stdio.h>

void	printGrid(int grid[9][9])
{
	for (int i_ = 0; i_ < 9; i_++)
	{
		for (int j_ = 0; j_ < 9; j_++)
		{
			printf("%d ", grid[i_][j_]);
		}
		printf("\n");
	}
	printf("\n");
}

bool	validColumn(int grid[9][9], int i, int num)
{
	for (int j = 0; j < 9; j++)
	{
		if (grid[j][i] == num)
			return false;
	}
	return true;
}
 
bool	validRow(int grid[9][9], int i, int num)
{
	for (int j = 0; j < 9; j++)
	{
		if (grid[i][j] == num)
			return false;
	}
	return true;
}
 
bool	validBlock(int grid[9][9], int i, int j, int num)
{
	int i_block = i - (i%3);
	int j_block = j - (j%3);

	for (int i_ = 0; i_ < 9; i_++)
	{
		for (int j_ = 0; j_ < 9; j_++)
		{
			if (i_block == (i_-i_%3) && j_block == (j_-j_%3))
			{
				if (grid[i_][j_] == num)
					return false;
			}
		}
	}
	return true;
}
 
bool	solve(int grid[9][9], int i, int j)
{
	if (i == 9)
		return true; 
	if (j >= 9)
		if (solve(grid, i + 1, 0))
			return true;
	if (grid[i][j] != 0)
	{
		if (solve(grid, i, j + 1))
			return true;
	}
	else
	{
		for (int i_ = 1; i_ < 10; i_++)
		{
			if (validColumn(grid, j, i_) && validRow(grid, i, i_) && validBlock(grid, i, j, i_))
			{
				grid[i][j] = i_;
				if (solve(grid, i, j + 1))
					return true;
			}
		}
		grid[i][j] = 0;
	}
	return false;
}
 
int main(){
	int init_grid[9][9] =
	{
		{9,0,0,1,0,0,0,0,5},
		{0,0,5,0,9,0,2,0,1},
		{8,0,0,0,4,0,0,0,0},
		{0,0,0,0,8,0,0,0,0},
		{0,0,0,7,0,0,0,0,0},
		{0,0,0,0,2,6,0,0,9},
		{2,0,0,3,0,0,0,0,6},
		{0,0,0,2,0,0,9,0,0},
		{0,0,1,9,0,4,5,7,0}
	};
	int i = 0;
	int j = 0;
	printf("\n\033[1;31mBase Grid:\033[0;31m\n");
	printGrid(init_grid);
	puts("\033[1;32mGrid Solved:\033[0;32m");
	solve(init_grid, i, j);
	printGrid(init_grid);
}