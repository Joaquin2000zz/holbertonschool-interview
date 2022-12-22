#!/usr/bin/python3
"""
module which contains count_words function
"""
import requests


def count_words(subreddit, word_list):
    """
    recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count
    as javascript, but java should not).

    """

    r = requests.get('https://www.reddit.com/r/' + subreddit + '/hot.json',
                     headers={'User-agent': 'your bot 0.1'})
    data = r.json().get('data').get('children')
    n = len(data)
    result = {}

    def req(data, i, n, result):
        """
        recursion needed
        """
        if i < n:
            for word in word_list:
                word = word.lower()
                if word in data[i].get('data').get('title').lower():
                    if not result.get(word):
                        result[word] = 1
                    else:
                        result[word] += 1
                else:
                    if not result.get(word):
                        result[word] = 0

            return req(data, i + 1, n, result)
        return result
    result = req(data, 0, n, result)

    keys = list(result.keys())
    keys.sort()
    new_res = {}
    for key in keys:
        num = result.get(key)
        if not new_res.get(num):
            new_res[num] = [key]
        else:
            new_res[num].append(key)

    result = {}
    for key in new_res:
        for name in new_res.get(key):
            print(name + ' :', key)
            result[name] = key

    return result
