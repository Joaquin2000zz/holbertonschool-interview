#include "palindrome.h"
#include <stdio.h>
/**
 * _pow - raises n to 10
 * @n: number to be raised
 * @k: times that n gonna be raised
 * Return: 1 if is it and 0 otherwise
 */
unsigned long _pow(unsigned long n, unsigned long k)
{
    if (k != 0)
        return (_pow(n, k - 1) * 10);
    else
        return (1);    
}

/**
 * ndigits - checks quantity of digits of some integer n 
 * @n: number to check
 * Return: number of digits
 */
unsigned long ndigits(unsigned long n)
{
    if (n / 10)
        return (ndigits(n / 10) + 1);
    else
        return (1);    
}


/**
 * is_palindrome - checks if n is palindrome
 * @n: is number to check
 * Return: 1 if is it and 0 otherwise
 */
int is_palindrome(unsigned long n)
{

    unsigned long digits, l = 0, r = 1, i = 0, powl;

    l += ndigits(n), digits = l / 2;
    l --;
    for (; i <= digits; i++)
    {
        powl = _pow(10, l);
        if ((n / powl) % 10 != (n / r) % 10)
            return (0);
        else
            r *= 10, l--;
    }
    return (1);
}
