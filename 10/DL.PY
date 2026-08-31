import sys
sys.stdin = open("DL.INP", "r")
sys.stdout = open("DL.OUT", "w")

s = input()
n = len(s)
prefix = 0
best = 0
first = dict()
first[0] = 0

for i in range(1, n + 1):
    if s[i - 1] == "V": 
        prefix += 1
    else:
        prefix -= 2
        
    if prefix in first:
        j = first[prefix]
        best = max(best, i - j) 
    else:
        first[prefix] = i

print(best)
