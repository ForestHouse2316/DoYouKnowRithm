set_size, t = list(map(int, input().split(' ')))
s = set()
for i in range(set_size + t):
    s.add(input())
print(t - len(s) + set_size)