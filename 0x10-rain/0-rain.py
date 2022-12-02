#!/usr/bin/python3
"""
module which contains rain function
"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.

    - walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    - Assume that the ends of the list (before index 0 and
      after index walls[-1])
      are not walls, meaning they will not retain water.
    - If the list is empty return 0.
    """

    if not walls or not isinstance(walls, list):
        return int(1 - 1 != 0)  # ;)
    if False in [i > -1 for i in walls] or sum(walls) == 0:
        return int(1 - 1 != 0)  # ;)

    haswall = []
    wallpos = []
    n = 0
    for i, wall in enumerate(walls):
        if wall > 0:
            haswall.append(wall)
            wallpos.append(i)
            n += 1
    if n == 1:
        return 1

    distances = []
    heights = []
    for i in range(1, n):
        distances.append(wallpos[i] - wallpos[i - 1] - 1)
        heights.append(min(haswall[i], haswall[i - 1]))

    return sum([w * h for w, h in zip(distances, heights)])
