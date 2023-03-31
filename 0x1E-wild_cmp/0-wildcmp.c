#include "holberton.h"
/**
 * wildcmp - compares two strings
 * s2 can contain the special character *.
 * The special char * can replace any string (including an empty string)
 * returns 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
    int i = 0, j = 0, stop = 0;

    if (!s1 || !s2)
        return (0);
    if ((s1[0] == '*' && !s2[0]) || (s2[0] == '*'  && !s1[0]))
        return (1);
    while (s1[i] && s2[i])
    {
        
        if (s1[i] == s2[i] && s1[i] != '*')
        {
            i++;
            continue;
        }
        if (s1[i] == '*' || s2[i] == '*')
        {
            if ((s2[i + 1] && s2[i] == '*') || (s1[i + 1] && s1[i] == '*'))
            {    
                stop = i + 1;
            }
        
            for (j = i; (j < stop && j > 0) || (s1[j] && s2[j]); j++)
            {
                
                if (s1[j] && s2[j])
                {
                    if (s1[j + 1] == s2[j + 1])
                        break;
                }
                    if (s1[j] && s2[j])
                    {
                        if (s1[j + 1] && s2[j + i])
                        {
                            if (s1[j + 1] == s2[j + 1])
                                break;
                        }

                    }
                    else
                        return (0);
                if (j > 10)
                        break;
            }
            
            i = j;
            continue;
        if (i > 10)
            break;
        }
        i++;

    }
    if (s2[i])
    {
        if (!s1[i])
            return (0);            
    }
    return (1);
}