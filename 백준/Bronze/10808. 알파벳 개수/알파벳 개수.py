from collections import OrderedDict, Counter

import sys
import string

word = sys.stdin.readline().rstrip()

c = Counter(word)
c.update(string.ascii_lowercase)

for k, v in OrderedDict(sorted(c.items(), key=lambda x: x[0])).items():
    print(v - 1, end=' ')
