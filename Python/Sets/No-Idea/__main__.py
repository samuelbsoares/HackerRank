import sys
from collections import Counter

happy = 0

n, m = map(int, sys.stdin.readline().split())
i = Counter([int(x) for x in sys.stdin.readline().split()])
A = [int(x) for x in sys.stdin.readline().split()]
B = [int(x) for x in sys.stdin.readline().split()]

for a in A:
    happy += i[a]

for b in B:
    happy -= i[b]

print(happy)
