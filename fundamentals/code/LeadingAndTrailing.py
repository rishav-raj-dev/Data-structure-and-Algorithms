
from math import log10, floor
def power(x, y, n):
    if (y == 0): 
        return 1
    if (y % 2 == 1): return power(x, y-1, n) * x % n
    return power(x*x % n, y//2, n)%n

T = int(input())
while T > 0:
    inputs = input().split()
    n = int(inputs[0])
    k = int(inputs[1])
    trailing = int(power(n, k, 1e3))
    
    # P = n * n * n ... k times
    # log10(P) = k * log10(n)
    leading = k*log10(n)
    fractional_part = leading - floor(leading)
    leading_digits = int(pow(10, fractional_part) * 100.0)
    ans = str(leading_digits).zfill(3) + "..." + str(trailing).zfill(3)

    print(ans)
    T-=1    