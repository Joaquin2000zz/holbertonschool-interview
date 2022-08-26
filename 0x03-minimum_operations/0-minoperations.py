#!/usr/bin/python3
"""
0-minoperations module which contains minOperations(n)
"""


def minOperations(n):
    """
    Given a number n, write a method that calculates the fewest number
    of operations needed to result in exactly n H characters in the file.
    
    Returns an integer
    If n is impossible to achieve, return 0
    """

    if not isinstance(n, int) or n < 2:
        return 0

    File = 1
    copy = None
    On = 0
    
    i = 0
    
    flag = 1

    while 1:
        i += 2 if flag else 1

        if flag:
            copy = File
            File += copy
            flag = 0
            On += 2
        else:
            File += copy
            flag = 0 if ((File + 1) * 2) > n else 1
            On += 1
        if File > n:
            return 0
        if File == n:
            return On
