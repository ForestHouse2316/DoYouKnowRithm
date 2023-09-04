import math

# def get_prime_list(K, N):  # N 이상의 소수 K개
#     primes = []
#     i = N
#     while len(primes) < K:
#         if i % 2 != 0:  # 짝수가 아니면
#             for n in range(3, int(math.sqrt(i))+1, 2):
#                 if i % n == 0:
#                     break
#             else:
#                 primes.append(i)
#         i += 1
#     return primes

def make_box(num, gap):
    return list(range(1, 1 + (num - 1) * gap + 1, gap))


def list2str(arr):
    s = ""
    for i in arr[:-1]:
        s += f"{i} "
    return s + str(arr[-1])


K_in, N_in = list(map(int, input().split(' ')))
result = list2str(list(range(1, N_in+1)))


for prime in [2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239][:K_in - 1]:
    result += '\n' + list2str(make_box(N_in, prime))

print(result, end='')
