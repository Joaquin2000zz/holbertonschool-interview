#!/usr/bin/python3
"""
module which contains rotate_2d_matrix function
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees clockwise.

    - Do not return anything. The matrix must be edited in-place.
    - You can assume the matrix will have 2 dimensions and will not be empty.
    """
    for i, v in enumerate(matrix):
        for j, _ in enumerate(v):
            if i == j:
                break
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i, v in enumerate(matrix):
        matrix[i] = v[:: -1]
