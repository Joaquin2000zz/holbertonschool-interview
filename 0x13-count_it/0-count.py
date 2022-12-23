#!/usr/bin/python3
"""
module which contains count_words function
"""
import requests


def count_words(subreddit, word_list, next=None, result=None):
    """
    recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count
    as javascript, but java should not).
    """

    url = 'https://www.reddit.com/r/' + subreddit + '/hot.json'
    if not next:
        r = requests.get(url,
                         headers={'User-agent': 'your bot 0.1'})
        result = {}
    else:
        url += '?after=' + next
        r = requests.get(url,
                         headers={'User-agent': 'your bot 0.1'})
    r = r.json().get('data')
    next = r.get('after')
    hot = r.get('children')

    for data in hot:
        for word in word_list:
            word = word.lower()
            if word in data.get('data').get('title').lower():
                if not result.get(word):
                    result[word] = 1
                else:
                    result[word] += 1
            else:
                if not result.get(word):
                    result[word] = 0

    if next:
        result = count_words(subreddit, word_list, next, result)
    else:
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
