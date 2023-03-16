#!/usr/bin/python3
"""
module which contains island_perimeter function
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid:

    @grid: is a list of list of integers:
    - 0 represents water
    - 1 represents land
    - Each cell is square, with a side length of 1
    - Cells are connected horizontally/vertically (not diagonally).
    - grid is rectangular, with its width and height not exceeding 100
    - The grid is completely surrounded by water
    - There is only one island (or nothing).
    - The island doesn’t have “lakes” (water inside that isn’t connected
      to the water surrounding the island).
    """
    p = 0
    if not grid and not isinstance(grid, list):
        return
    n, m = len(grid) - 1, len(grid[0]) - 1

    for i, row in enumerate(grid):
        for j, col in enumerate(row):
            if col == 1:
                cell = 4
                if j == 0 or j != m:
                    cell -= 1 if row[j + 1] == 1 else 0
                    if i == 0 or i != n:
                        cell -= 1 if grid[i + 1][j] == 1 else 0
                    if i == n or i != 0:
                        cell -= 1 if grid[i - 1][j] == 1 else 0
                if j == m or j != 0:
                    cell -= 1 if row[j - 1] == 1 else 0
                p += cell
    return p
