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
        try:
            r = requests.get(url,
                             headers={'User-agent': 'your bot 0.1'},
                             allow_redirects=False)
            if not r.status_code == 200:
                return None
        except Exception:
            return
        result = {word.lower(): 0 for word in word_list}
        sys.setrecursionlimit(9999)
    else:
        url += '?after=' + next
        try:
            r = requests.get(url,
                             headers={'User-agent': 'your bot 0.1'},
                             allow_redirects=False)
            if not r.status_code == 200:
                return None
        except Exception:
            return
    try:
        r = r.json().get('data')
    except Exception:
        return None

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

        num_keys = list(new_res.keys())
        num_keys.sort()
        num_keys = num_keys[::-1]

        for key in num_keys:
            if key == 0:
                continue
            names = new_res.get(key)
            for name in names:
                print(name + ':', key)
                result[name] = key
