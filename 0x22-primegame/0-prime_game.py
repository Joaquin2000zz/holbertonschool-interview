#!/usr/bin/python3
"""
module which contains isWinner function
"""


def isWinner(x, nums):
    """
    Maria and Ben are playing a game. Given a set of consecutive integers
    starting from 1 up to and including n, they take turns choosing a
    prime number from the set and removing that number and its multiples
    from the set. The player that cannot make a move loses the game.

    They play x rounds of the game, where n may be different for each round.
    Assuming Maria always goes first and both players play optimally,
    determine who the winner of each game is.

    @x:  number of rounds
    @nums: is an array of n
    """
    if x < 1 or not nums or False in [isinstance(x, int) for x in nums]:
        return None

    def is_prime(num):
        """
        Utility function to check if a number is prime
        """
        if num <= 1:
            return False
        if num == 2 or num == 3:
            return True
        if num % 2 == 0:
            return False
        for i in range(3, int(num ** .5) + 1, 2):
            if num % i == 0:
                return False
        return True

    def remove_multiples(primes, num):
        """
        Utility function to remove multiples of a given prime number
        """
        for i in range(num, len(primes), num):
            primes[i] = 0

    wins = {'Maria': 0, 'Ben': 0}  # to keep track of wins for each player

    for i in range(x):  # iterate over each round
        n = nums[i]
        # initialize list to keep track of prime numbers
        primes = [1] * (n + 1)
        primes[0] = primes[1] = 0  # 0 and 1 are not prime

        player = 'Maria'  # Maria always goes first
        while True:
            move = None
            for num in range(2, n + 1):
                # check if the number is still available
                if primes[num] == 1 and is_prime(num):
                    move = num
                    break
            if move is None:  # no prime number left, game over
                break
            # remove multiples of the chosen prime
            remove_multiples(primes, move)
            player = 'Ben' if player == 'Maria' else 'Maria'

        # update wins count
        wins['Ben' if player == 'Maria' else 'Maria'] += 1

    # determine the winner with the most wins
    if wins['Maria'] > wins['Ben']:
        return 'Maria'
    elif wins['Maria'] < wins['Ben']:
        return 'Ben'
    else:
        return None  # if the winner cannot be determined
