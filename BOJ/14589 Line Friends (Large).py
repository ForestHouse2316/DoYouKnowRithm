LENGTH = 0
COOR = 1
L = 0
R = 1

N = int(input())  # (길이, (Li, Ri))
lines = [None]  # 선분을 첫 번째부터 시작
for i in range(N):
    Li, Ri = map(int, input().split())
    lines.append((Ri - Li, (Li, Ri)))

lines.sort(key=lambda x: x[LENGTH], reverse=True)
