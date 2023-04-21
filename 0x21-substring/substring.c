#include "substring.h"
#include <stdio.h>

/**
 * resize - realloc an array without losing the old content
 * @p: pointer to resize
 * @size: new pointer size
 * Return: resized pointer
 */
int *resize(int *p, int size)
{
    int *aux = NULL, i = 0;

    if (!p || size < 1)
        return (NULL);
    aux = malloc(size * sizeof(int));
    if (!aux)
        return (NULL);
    for (; i < size; i++)
        aux[i] = p[i];
    p = realloc(p, sizeof(int) * size);
    if (!p)
        return (NULL);
    for (i = 0; i < size; i++)
        p[i] = aux[i];
    free(aux);
    return p;
}

/**
 * find_substring - finds all the possible substrings containing
 *                  a list of words, within a given string
 * @s: the string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in the array words
 * @n: address at which to store the number of elements in the returned array
 * Return: int * 
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int i = 0, j = 0, k = 0, b = 0, flag = 0, *p = NULL;

    (*n) = 0;
    for (; s[i]; i++)
    {
        for (b = 0; b < nb_words; b++)
        {
            for (j = 0; words[b][j]; j++)
            {
                if (s[i + j] != words[b][j])
                {
                    flag = 0;
                    break;
                }
                else
                    flag = 1;
            }
            if (b == nb_words - 1)
                continue;
            if (flag)
            {
                flag = 0, k++, (*n)++;
                if (!p)
                    p = malloc(sizeof(int) * k);
                else
                    p = resize(p, k);
                if (!p)
                    return (NULL);
                p[k - 1] = i;
                break;
            }
        }
    }
    return !(*n) ? n : p;
}
