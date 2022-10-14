#include "slide_line.h"


/**
 * fix - fix array
 * @line: int pointer
 * @size: \(._.)/
 * @direction: direction choosed
 */
void fix(int *line, size_t size, int direction)
{
    size_t i = 0, zerodx = 0, flag = 0;
    
    if (direction == SLIDE_LEFT)
    {
        for (; i < size; i++)
        {
            if (!flag && line[i] == 0)
                flag = 1, zerodx = i;
            if (flag && line[i] != 0)
            {
                line[zerodx] = line[i], line[i] = 0, zerodx++;
                if (i + 1 < size - 1 && line[i + 1] != 0)
                    flag = 0;
            }
        }
    }
    else
    {
        zerodx = size -1, i = size - 1, flag = 0;
        for (; (int)i > -1; i--)
        {
            if (!flag && line[i] == 0)
                flag = 1, zerodx = i;
            if (flag && line[i] != 0)
            {
                line[zerodx] = line[i], line[i] = 0, zerodx--;
                if (i - 1 > 0 && line[i - 1] != 0)
                    flag = 0;
            }
        }
    }
}

/**
 * slide_line - slides and merges an array of integers
 * @line: int pointer
 * @size: \(._.)/
 * @direction: direction choosed
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i = 0;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);
    
    fix(line, size, direction);

    if (direction == SLIDE_LEFT)
    {
        for (i = 1; i < size || line[i] != 0; i++)
        {
            if (line[i] == line[i - 1])
                line[i - 1] += line[i], line[i] = 0;
        }
    }
    else
    {
        for (i = size - 2; (int)i > -1 || line[i] != 0; i--)
        {
            if (line[i] == line[i + 1])
                line[i + 1] += line[i], line[i] = 0;
        }
    }

    fix(line, size, direction);
    return(1);
}
