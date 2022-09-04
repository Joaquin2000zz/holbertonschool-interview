#include "sandpiles.h"

/**
 * print - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print(int grid[3][3])
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
 * check - check if is neccessary keep reducing the sandpile
 * @grid: 3x3 grid
 * Return: 1 if yes, otherwise, 0
 */
int check(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				printf("=\n");
				print(grid);
				return (1);
			}
		}
	}
	return (0);
}

/**
 * fix - reduce the sandpile
 * @grid: 3x3 grid
 *
 */
void fix(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i > 0)
					grid2[i - 1][j] += 1;
				if (i < 2)
					grid2[i + 1][j] += 1;
				if (j > 0)
					grid2[i][j - 1] += 1;
				if (j < 2)
					grid2[i][j + 1] += 1;
			}
		}
	}
	sandpiles_sum(grid1, grid2);
}

/**
 * sandpiles_sum - adds 2 sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
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
	if (check(grid1))
		fix(grid1, grid2);
}
