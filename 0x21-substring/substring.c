#include "substring.h"

/**
 * is_valid_substring - Checks if a substring in s starting from a given index
 *                      is valid, i.e., it contains all words in words array
 *                      exactly once and without any intervening characters.
 * @s: The input string to check for substring.
 * @words: The array of words that the substring must contain.
 * @nb_words: The number of elements in the words array.
 * @word_len: The length of each word in the words array.
 * @start: The starting index of the substring in s.
 * @used: An array to keep track of used words.
 * Return: 1 if the substring is valid, 0 otherwise.
 */
int is_valid_substring(char const *s, char const **words, int nb_words,
                       int word_len, int start, int *used)
{
	int i, w_idx, words_used = 0;

	for (i = 0; i < nb_words; i++)
        	used[i] = 0;
	for (i = start; i < start + nb_words * word_len; i += word_len)
	{
		char *word = strndup(s + i, word_len);
		for (w_idx = 0; w_idx < nb_words; w_idx++)
		{
			if (used[w_idx] == 0 && strcmp(word, words[w_idx]) == 0)
			{
				used[w_idx] = 1;
				words_used++;
				break;
			}
		}

		free(word); /* Free dynamically allocated memory */
	}

	/* Check if all words are used exactly once */
	return (words_used == nb_words ? 1 : 0);
}

/**
 * find_substring - Finds all possible substrings containing a list of
 *                  words within a given string.
 * @s: The input string to scan.
 * @words: The array of words that all substrings must be a
 *         concatenation arrangement of.
 * @nb_words: The number of elements in the words array.
 * @n: A pointer to store the number of elements in the returned array.
 *
 * Return: A dynamically allocated array of indices in s, at which a substring
 *         was found, or NULL if no solution is found. The number of elements
 *         in the returned array is stored in the n parameter.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len = 0, s_len = 0, max_idx = 0, i = 0;
	int *res = NULL, res_size = 0, *used = NULL;

	if (!s || !words[0])
		return (NULL);
	word_len = strlen(words[0]);
	s_len = strlen(s);
	used = (int *)calloc(nb_words, sizeof(int));
	max_idx = s_len - nb_words * word_len;
	for (i = 0; i <= max_idx; i++)
	{
		if (is_valid_substring(s, words, nb_words,
				       word_len, i, used))
		{
			res_size++;
			res = (int *)realloc(res, res_size * sizeof(int));
			res[res_size - 1] = i;
		}
	}

	*n = res_size;

	free(used);

	return (res);
}
