t = int(input())
n = []
temp = 0
for i in range(t):
    a = int(input())
    n.append(a)
n.sort()
length = int(len(n))
for i in range (length):
    print(n[i])