#!/usr/bin/python3
"""
module which contains pascal_triangle function
"""


def pascal_triangle(n):
    """
    returns a list of lists of integers
    representing the Pascal’s triangle of n
    """
    triangle = []
    if n <= 0:
        return triangle
    triangle.append([1])
    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
        row += [1]
        triangle.append(row)
    return triangle
