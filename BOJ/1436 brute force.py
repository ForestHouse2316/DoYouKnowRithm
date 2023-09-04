target = int(input())

nth = 1
count = 666
while nth != target:
    count += 1
    if str(count).count('666') >= 1:
        nth += 1
print(count)