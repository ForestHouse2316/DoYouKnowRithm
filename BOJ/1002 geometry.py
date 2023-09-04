import math
t = int(input())
inputs = []
for i in range(t):
    inputs.append(list(map(int, input().split(' '))))
result = []
for l in inputs:
    x1, y1, r1, x2, y2, r2 = l
    if x1 == x2 and y1 == y2:
        result.append(-1 if r1 == r2 else 0)
        continue
    distance = math.sqrt((x1-x2) ** 2 + (y1-y2) ** 2)
    s_radius = r1 + r2

    rM = max([r1, r2])
    if distance < rM:
        rm = min([r1, r2])
        if rM == distance + rm:
            result.append(1)
        elif rM > distance + rm:
            result.append(0)
        else:
            result.append(2)
        continue

    if s_radius == distance:
        result.append(1)
    elif s_radius > distance:
        result.append(2)
    else:
        result.append(0)
for i in result:
    print(i)