def count_wrong_tiles(board):
    count_a = 0
    zero_point = [board[0][0], 'W' if board[0][0] == 'B' else 'B']
    for v in range(8):
        for h in range(8):
            if board[v][h] != zero_point[(v + h) % 2]:
                count_a += 1

    count_b = 0
    zero_point = [board[0][0], 'W' if board[0][0] == 'B' else 'B']
    for v in range(8):
        for h in range(8):
            if board[v][h] != zero_point[(v + h + 1) % 2]:
                count_b += 1
    if count_a == 0 or count_b == 0:
        raise Exception
    return min(count_a, count_b)


def cut_board(board, from_x, from_y):
    combined = []
    for line in board[from_y:from_y+8]:
        combined.append(line[from_x:from_x+8])
    return combined


V, H = list(map(int, input().split(' ')))
lines = []
re_paint = []
for i in range(V):
    lines.append(input())

for y in range(V+1 - 8):
    for x in range(H+1 - 8):
        try:
            re_paint.append(count_wrong_tiles(cut_board(lines, x, y)))
        except Exception:
            print(0)
            exit(0)
print(min(re_paint))