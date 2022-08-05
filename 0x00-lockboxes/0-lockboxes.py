#!/usr/bin/python3
"""
module which contains canUnlockAll function
"""


def canUnlockAll(boxes):
    """
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1
    and each box may contain keys to the other boxes.
    Write a method that determines if all the boxes can be opened.
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    There can be keys that do not have boxes
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
    """
    i = 0
    keys = []
    length = 0
    if not boxes or len(boxes) == 1:
        return True
    if len(boxes) == 2:
        if sorted(boxes[0]) == sorted(boxes[1]):
            return True
    for box in boxes:
        if box:
            length += 1
    length -= 1
    for box in boxes:
        j = 0
        keys += list(set(box))
        for key in keys:
            keys += boxes[key]
            keys = list(set(keys))
        if keys and i != length and i + 1 not in keys:
            return False
        if i == length:
            return True
        i += 1
    return True
