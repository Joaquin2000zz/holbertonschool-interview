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
 * Return 1 if the substring is valid, 0 otherwise.
 */
int is_valid_substring(char const *s, char const **words, int nb_words,
                       int word_len, int start, int *used)
{
    int i;
    int word_idx;
    int words_used = 0;

    /* Initialize the used array to 0 */
    for (i = 0; i < nb_words; i++)
    {
        used[i] = 0;
    }

    /**
     * Iterate through the string s and check if
     * it contains all words in words array
     */
    for (i = start; i < start + nb_words * word_len; i += word_len)
    {
        char *word = strndup(s + i, word_len); /* Extract word from s */

        for (word_idx = 0; word_idx < nb_words; word_idx++)
        {
            if (used[word_idx] == 0 && strcmp(word, words[word_idx]) == 0)
            {
                used[word_idx] = 1;
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
 * Return A dynamically allocated array of indices in s, at which a substring
 *         was found, or NULL if no solution is found. The number of elements
 *         in the returned array is stored in the n parameter.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int word_len = strlen(words[0]);
    int s_len = strlen(s);
    /* Maximum index to check for substring */
    int max_idx = s_len - nb_words * word_len;
    int *result = NULL;
    int result_size = 0;
    /* Array to keep track of used words */
    int *used = (int *)calloc(nb_words, sizeof(int));

    /* Iterate through the input string s */
    for (int i = 0; i <= max_idx; i++)
    {
        if (is_valid_substring(s, words, nb_words, word_len, i, used))
        {
            /**
             * If a valid substring is found, append its starting index
             * to the result array
             */
            result_size++;
            result = (int *)realloc(result, result_size * sizeof(int));
            result[result_size - 1] = i;
        }
    }

    /* Update the number of elements in the returned array */
    *n = result_size;

    /* Free dynamically allocated memory */
    free(used);

    return (result);
}