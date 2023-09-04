t = int(input())
history = []
def get_temp_pos(first, second):
    l = [first, second]
    if 1 not in l:
        return 1
    if 2 not in l:
        return 2
    if 3 not in l:
        return 3
def move(depth, fr, to):
    if depth != 1:
        move(depth-1, fr, get_temp_pos(fr, to))
    history.append(f'{fr} {to}')
    if depth != 1:
        move(depth-1, get_temp_pos(fr, to), to)
move(t, 1, 3)
print(len(history))
for line in history:
    print(line)