from sys import stdin
from math import factorial

def ways(n, m):
    return (factorial(n+m)/(factorial(n)*factorial(m)))

times = int(stdin.readline())

for i in xrange(times):
    x = stdin.readline().split()
    print(int(ways(float(x[0]), float(x[1])) % (10**9+7)))
