import math
import readline
import sys

def sum_even_fib(num):
    fib = [1, 2]
    sum = 0
    while fib[-1] < num:
        if fib[-1] % 2 == 0:
            sum += fib[-1]
        fib.append(fib[-1]+fib[-2])
    return sum

data = sys.stdin.read()
data = data.split()
leng = int(data[0])
data = data[1:]
data = list(map(int, data))

for item in range(leng):
    print(sum_even_fib(data[item]))
