#!/usr/bin/python3
"""
module which contains makeChange function
"""


def recChange(coin, total, change):
    """
    looks how many times can add the coin to the total change
    Returns: number of times the coin can be used
    """
    if change + coin <= total:
        return recChange(coin, total, change + coin) + 1
    return 0


def makeChange(coins, total):
    """
    - Return: fewest number of coins needed to meet total
    - If total is 0 or less, return 0
    - If total cannot be met by any number of coins you have, return -1
    - coins is a list of the values of the coins in your possession
    - The value of a coin will always be an integer greater than 0
    - You can assume you have an infinite number of each denomination
      of coin in the list
    - Your solution’s runtime will be evaluated in this task
    """
    if total < 1:
        return 0
    n = 0
    change = 0
    prev = 0
    coins.sort()
    coins = coins[::-1]
    while True:
        if change == total:
            break
        if change > total:
            return -1
        prev = change
        for i, _ in enumerate(coins):
            coin = 0
            j = (i + 1) * - 1
            greather = coins[i]
            lower = coins[j]
            if change + greather <= total:
                times = recChange(greather, total, change)
                coin += greather * times
                n += times
            else:
                if change + lower + coin <= total:
                    coin += lower
                    n += 1
            if change + coin > total:
                return -1
            change += coin
        if prev == change:
            return -1
    return n
