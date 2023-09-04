t = int(input())
arr = []
for i in range(t):
    arr.append(int(input()))
changed = True
while changed:
    changed = False
    for i in range(t-1):
        if arr[i] > arr[i+1]:
            changed = True
            temp = arr[i]
            arr[i] = arr[i+1]
            arr[i+1] = temp
arr = map(str, arr)
print('\n'.join(arr))
