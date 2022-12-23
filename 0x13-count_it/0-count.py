#!/usr/bin/python3
"""
module which contains count_words function
"""
import requests
import sys

def count_words(subreddit, word_list, next=None, result=None):
    """
    recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count
    as javascript, but java should not).
    """

    url = 'https://www.reddit.com/r/' + subreddit + '/hot.json'
    if not next and not result:
        r = requests.get(url,
                         headers={'User-agent': 'your bot 0.1'},
                         allow_redirects=False)
        result = {word: 0 for word in word_list}
        sys.setrecursionlimit(1500)
    else:
        url += '?after=' + next
        r = requests.get(url,
                         headers={'User-agent': 'your bot 0.1'},
                         allow_redirects=False)
    r = r.json().get('data')
    next = r.get('after')
    hot = r.get('children')

    for data in hot:
        title_words = data.get('data').get('title').lower().split()
        for title in title_words:
            for word in word_list:
                if title == word.lower():
                    result[title] += 1

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

        for key in new_res:
            for name in new_res.get(key):
                print(name + ':', key)
                result[name] = key
