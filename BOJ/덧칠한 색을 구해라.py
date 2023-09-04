# 덧칠한 색을 구하는 것보다 덧칠을 받은 녀석에게서 덧칠한 놈을 찾는 게 더 쉬운 방법으로 보인다.

# 0x0 부터 시작하여 색을 찾음.
# 인식되는 사각형 영역 내부에 있는 모든 숫자는 덧칠한 색이다.
# 덧칠한 색이 피덧칠 색일 수도 있으니 조사는 모두 한다.

# 모든 모서리를 조사하는 방식은, 각 끝 점을 찾는 것이지만 여기선 무조건 사각형이니까 범위 좁히는 방식으로 사용하는 편이 나을 것이다.

# Board Composition
N = int(input())
board = []
for t in range(N):
    board.append(list(input()))  # 숫자가 있으면 0이 빠져서 문자로 연산하기로 함
print(board)

# 사각형 조사 후 침범자 찾아내기 with 안전빵 SET!
used_color = set()
paint_color = set()

for y in range(N):
    for x in range(N):
        # 기본적으로 배경색을 조사하고 있다고 가정
        current_back_color = board[y][x]
        if current_back_color in used_color or current_back_color == '0':
            continue
        used_color.add(current_back_color)
        l = 0
        r = 0
        t = 0
        b = 0
        for t_y in range(N):
            if current_back_color in board[t_y]:
                t = t_y
                break
        for b_y in range(N-1, -1, -1):
            if current_back_color in board[b_y]:
                b = b_y
                break
        for l_x in range(N):  # 최적화를 위해 t~b 만 조사
            if current_back_color in [board[var_y][l_x] for var_y in range(t, b + 1)]:
                l = l_x
                break
        for r_x in range(N-1, -1, -1):
            if current_back_color in [board[var_y][r_x] for var_y in range(t, b + 1)]:
                r = r_x
                break
        for c_y in range(t, b+1):
            for c_x in range(l, r+1):
                current_color = board[c_y][c_x]
                if current_color != current_back_color:
                    paint_color.add(current_color)
print("덧칠한놈 = ", paint_color)
print(len(used_color) - len(paint_color))