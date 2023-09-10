from math import sqrt
T = int(input())
result = []
for t in range(T):
    difference = 0
    dx, dy, ax, ay = list(map(int, input().split(' ')))
    N = int(input())
    planet = []  # x y r
    for n in range(N):
        x, y, r = list(map(int, input().split(' ')))
        d_dependency = False
        a_dependency = False
        # departure
        distance = sqrt((x - dx) ** 2 + (y - dy) ** 2)
        if distance < r:
            d_dependency = True
        # arrival
        distance = sqrt((x - ax) ** 2 + (y - ay) ** 2)
        if distance < r:
            a_dependency = True
        if d_dependency is not a_dependency:
            difference += 1
    result.append(difference)
for s in result:
    print(s)