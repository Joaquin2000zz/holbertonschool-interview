#include "sandpiles.h"
/**
 * printing_grid - prints a grid
 * @grid: grid to be printed
 */
void printing_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sum_piles - function that agregates cell by cell two grids
 * @grid1: grid one
 * @grid2: grid two
 */
static void sum_piles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
	}
}

/**
 * grid_stable - function that determines if a grid is stable
 * @grid1: grid one
 * Return: True if unstable, other wise, false
 */
static bool grid_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (true);
		}
	}
	return (false);
}

/**
 * disperse - function that disperse a grid if cell value above 3
 * @grid1: grid one
 * @grid2: grid two
 */
static void disperse(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (i > 0)
					grid2[i - 1][j] += 1;
				if (j > 0)
					grid2[i][j - 1] += 1;
				if (i < 2)
					grid2[i + 1][j] += 1;
				if (j < 2)
					grid2[i][j + 1] += 1;
				grid1[i][j] -= 4;
			}
		}
	}
	sum_piles(grid1, grid2);
}

/**
 * sandpiles_sum - function that sums two sand piles
 * @grid1: grid one
 * @grid2: grid two
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_piles(grid1, grid2);
	while (grid_stable(grid1))
	{
		printf("=\n");
		printing_grid(grid1);
		disperse(grid1, grid2);
	}
}