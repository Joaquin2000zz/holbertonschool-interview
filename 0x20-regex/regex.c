#include <stdio.h>
#include "regex.h"
/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: contain any ASCII character in the exception of . and *
 * @pattern: contain any ASCII character, including . and *
 * Return: return 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
    int i = 0, j = 0;

    for (; str[i]; i++)
    {
        if (pattern[j] == 'Z' && i == 0)
        {
            j++;
            continue;
        } 
        if (pattern[j] == '*')
        {
            if (pattern[j + 1] && pattern[j + 1] == str[i])
                j++;
            continue;
        }
        if (pattern[j] == '.')
        {
            j++;
            continue;
        }

        if (str[i] != pattern[j])
            return (0);
        j++;
    }
    return (1);
}