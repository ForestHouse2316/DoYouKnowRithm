TOP = 0
RIGHT = 1
BOTTOM = 2
LEFT = 3


def move_ball(x, y, direction):  # return 0 when it is a hole
    count = 0
    while True:
        if direction == TOP:
            y -= 1
        elif direction == RIGHT:
            x += 1
        elif direction == BOTTOM:
            y += 1
        elif direction == LEFT:
            x -= 1

        if x == hX and y == hY:
            return 0
        elif board[y][x] == '#':
            return move_back_once(x, y, direction) + [count]
        else:
            count += 1

def move_back_once(x, y, direction):
    if direction == TOP:
        return [x, y + 1]
    elif direction == RIGHT:
        return [x - 1, y]
    elif direction == BOTTOM:
        return [x, y - 1]
    elif direction == LEFT:
        return [x + 1, y]



def stack_search():
    stack = [[rX, rY, bX, bY, -1]]  # content => [rX, rY, bX, bY, direction]

    def recursive():
        global min_movement
        directions = [TOP, RIGHT, BOTTOM, LEFT]
        if stack[-1][4] != -1:  # except initial
            directions.remove(stack[-1][4])  # except previous direction
        for direction in directions:
            blue_move_result = move_ball(stack[-1][2], stack[-1][3], direction)
            if blue_move_result == 0:
                continue
            red_move_result = move_ball(stack[-1][0], stack[-1][1], direction)
            if red_move_result == 0:
                min_movement = min(min_movement, len(stack))
                continue
            if len(stack) == 10:  # include initial elem
                continue
            stack.append(red_move_result[:2] + blue_move_result[:2] + [direction])  # stack append point
            if stack[-1][0] == stack[-1][2] and stack[-1][1] == stack[-1][3]:  # if both are overlapped
                if blue_move_result[2] > red_move_result[2]:  # if blue moved more, back blue once
                    stack[-1][2], stack[-1][3] = move_back_once(stack[-1][2], stack[-1][3], direction)
                else:
                    stack[-1][0], stack[-1][1] = move_back_once(stack[-1][0], stack[-1][1], direction)
            recursive()
        stack.pop()
        return
    recursive()  # execute recursion


min_movement = 11
board_xy_info = list(map(lambda x: int(x), input().split(' ')))  # Y X
board = []  # board[Y][X]
for i in range(board_xy_info[0]):
    board.append(list(input()))
rX, rY, bX, bY, hX, hY = 0, 0, 0, 0, 0, 0
for Y in range(board_xy_info[0]):
    for X in range(board_xy_info[1]):
        current = board[Y][X]
        if current == 'R':
            rX = X
            rY = Y
        elif current == 'B':
            bX = X
            bY = Y
        elif current == 'O':
            hX = X
            hY = Y
stack_search()
print(-1 if min_movement == 11 else min_movement)