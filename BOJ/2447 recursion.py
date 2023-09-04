size = int(input())
canvas = [[' ']*size for x in range(size)]
def star(dim: int, x: int, y: int):
    if dim == 1:
        canvas[y][x] = '*'
    else:
        shrunk = dim//3
        star(shrunk, x, y)
        star(shrunk, x+shrunk, y)
        star(shrunk, x+shrunk*2, y)
        star(shrunk, x, y+shrunk)
        star(shrunk, x, y+shrunk*2)
        star(shrunk, x + shrunk*2, y+shrunk)
        star(shrunk, x + shrunk, y + shrunk*2)
        star(shrunk, x + shrunk*2, y + shrunk*2)
star(size, 0, 0)
for x in canvas:
    print(''.join(x))