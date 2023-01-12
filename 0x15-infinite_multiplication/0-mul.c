#include "holberton.h"
#include <stdlib.h>

/**
 * Error - prints Error
 */
void Error(void)
{
	char *error = "Error\n\0";
	int i;

	for (i = 0; error[i]; i++)
		_putchar(error[i]);
	exit(98);
}

/**
 * _digits - checks if all chars are digits
 * @args: arguments for program.
 * Return: 1 Ok,  0 otherwise.
 */
int _digits(char **args)
{
	int i, j;

	for (i = 1; i <= 2; i++)
		for (j = 0; args[i][j]; j++)
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (0);
		}
	return (1);
}
/**
 * _calloc- initializes memory spaces with zero.
 * @str1: string 1.
 * @str2: string 2, concatenated to 1
 *
 * Return: pointer to the concatenated.
 */
void *_calloc(unsigned int str1, unsigned int str2)
{
	unsigned int i;
	char *new;

	if (str1 == 0 || str2 == 0)
		return (NULL);

	new = malloc(str1 * str2);
	if (new == NULL)
		return (NULL);

	for (i = 0; i < (str1 * str2); i++)
		*(new + i) = 0;

	return (new);
}
/**
 * main - multiplies 2 positive numbers.
 * @argc: vector size.
 * @argv: vector of arguments
 * Return: result or Error.
 */

int main(int argc, char **argv)
{
	int i, j, k, len, len_s1 = 0, len_s2 = 0;
	char *s1 = *(argv + 1), *s2 = *(argv + 2);
	int *a, *b, *ans;

	if (argc != 3 || _digits(argv) != 1)
		Error();
	if (*s1 == '0' || *s2 == '0')
		_putchar('0');
	while (*(*(argv + 1) + len_s1))
		len_s1++;
	while (*(*(argv + 2) + len_s2))
		len_s2++;
	len = len_s1 + len_s2 + 1;
	a = (int *) malloc(len_s1 * sizeof(int));
	b = (int *) malloc(len_s2 * sizeof(int));
	ans = _calloc(len, sizeof(int));
	if (a == NULL || b == NULL || ans == NULL)
		Error();
	for (i = len_s1 - 1, j = 0; i >= 0; i--, j++)
		*(a + j) = *(s1 + i) - '0';
	for (i = len_s2 - 1, j = 0; i >= 0; i--, j++)
		*(b + j) = *(s2 + i) - '0';
	for (i = 0; i < len_s2; i++)
		for (j = 0; j < len_s1; j++)
			*(ans + i + j) = *(ans + i + j) + *(b + i) * *(a + j);
	for (i = 0; i < len_s1 + len_s2; i++)
	{
		k = *(ans + i) / 10, *(ans + i) = *(ans + i) % 10;
		*(ans + i + 1) = *(ans + i + 1) + k; }
	for (i = len_s1 + len_s2; i >= 0; i--)
		if (*(ans + i) > 0)
			break;
	for (; i >= 0; i--)
		_putchar(*(ans + i) + '0');
	_putchar('\n');
	free(a), free(b), free(ans);
	return (0);
}
