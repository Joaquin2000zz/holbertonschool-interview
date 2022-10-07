#!/usr/bin/python3
"""
module which contains validUTF8 function
"""

def validUTF8(data):
    """
    determines if a given data set represents a valid UTF-8 encoding.

    * A character in UTF-8 can be 1 to 4 bytes long
    * The data set can contain multiple characters
    * The data will be represented by a list of integers
    * Each integer represents 1 byte of data, therefore you only
      need to handle the 8 least significant bits of each integer
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    for item in data:
        if item > int('0xff', 16):
            return False
    return True
