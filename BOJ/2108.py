import math

t = int(input())
arr = []
freq = dict()
sum = 0
for i in range(t):
    iv = int(input())
    sum += iv
    if freq.get(iv) is None:
        freq[iv] = 1
    else:
        freq[iv] += 1
    arr.append(iv)

arr.sort()
print(round(sum / t))
print(arr[int(t/2)])
freql = sorted(list(zip(freq.keys(), freq.values())), key=lambda x: x[1])
most = sorted(filter(lambda x: freql[-1][1] == x[1], freql), key=lambda x: x[0])
if len(most) > 1:
    print(most[1][0])
else:
    print(most[0][0])
print(arr[-1] - arr[0])