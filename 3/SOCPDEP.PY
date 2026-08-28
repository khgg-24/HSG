import math
import sys

def sang_nto(N):
    is_prime = [True] * (N + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(math.sqrt(N)) + 1):
        if is_prime[i]:
            for j in range(i * i, N + 1, i):
                is_prime[j] = False

    return is_prime

def doi_xung(n):
    s = str(n)

    return s == s[::-1]

def ktra(A, B):
    start = math.ceil(math.sqrt(A))
    end = math.floor(math.sqrt(B))
    is_prime = sang_nto(end)
    dem = 0

    for i in range(start, end + 1):
        if is_prime[i] and doi_xung(i):
            dem += 1

    print(dem)

sys.stdin = open("SOCPDEP.INP", "r")
sys.stdout = open("SOCPDEP.OUT", "w")
a, b = map(int, input().split())

ktra(a, b)