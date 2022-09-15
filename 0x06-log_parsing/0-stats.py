#!/usr/bin/python3
"""
module which contains a script that reads stdin line by
line and computes metrics

* Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
  <status code> <file size> (if the format is not this one,
  the line must be skipped)
* After every 10 lines and/or a keyboard interruption (CTRL + C),
  print these statistics from the beginning:
    - Total file size: File size: <total size>
    - where <total size> is the sum of all previous <file size>
* Number of lines by status code:
    - possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
    - if a status code doesn’t appear or is not an integer,
      don’t print anything for this status code
    - format: <status code>: <number>
    - status codes should be printed in ascending order
"""
import sys


try:
    buffer = {}
    size = 0
    for i, line in enumerate(sys.stdin):
        code, sizeS = line.split('"')[2][1:].split(' ')
        size += int(sizeS)
        if not buffer.get(code):
            buffer[code] = 1
        else:
            buffer[code] += 1
        if (i + 1) % 10 == 0:
            print("File size: ", size)
            for k in sorted(buffer.keys()):
                to_print = k + " " + str(buffer[k])
                print(to_print)
            buffer = {}
except KeyboardInterrupt:
    print("File size: ", size)
    for k in sorted(buffer.keys()):
        to_print = k + " " + str(buffer[k])
        print(to_print)
