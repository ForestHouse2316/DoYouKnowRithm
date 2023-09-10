string = input()
length = len(string)
storage = set()

for size in range(1, length+1):
    for offset in range(length-size+1):
        storage.add(string[offset:offset+size])

print(len(storage))