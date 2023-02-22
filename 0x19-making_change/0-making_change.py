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
    if not coins:
        return -1
    ncoins, change = 0, 0
    coins.sort(reverse=True)
    for i, _ in enumerate(coins):
        coin, value = 0, coins[i]
        if change + value <= total:
            times = recChange(value, total, change)
            coin += value * times
            ncoins += times
        change += coin
    return ncoins if ncoins > 0 and change == total else -1
