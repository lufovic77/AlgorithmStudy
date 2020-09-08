n , m = input().split()
n = int(n)
m = int(m)
arr = []
for i in range(0, n):
    tmp = int(input())
    arr.insert(i,tmp)
for i in range(0, m):
    a, b = input().split()
    a = int(a)
    b = int(b)
    c = arr[a-1:b]
    c.sort()
    print(c[0])

