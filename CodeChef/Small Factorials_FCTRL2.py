t = int(input())
sum1 = 1
for i in range(t):
    n = int(input())
    for j in range(1,n+1):
        sum1 *= j
    print(sum1)
    sum1 = 1