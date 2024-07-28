#include <bits/stdc++.h>
using namespace std;

short primes[100005];
int A, B, result=0;

bool isPrime(int n) {
    if (n < 2) return false;
    if (primes[n] != -1) return (bool) primes[n];
    int sqr = (int) sqrt(n);
    for (int i = 2; i <= sqr; ++i) if (n % i == 0) {
        primes[n] = 0; // non-prime
        return false;
    }
    primes[n] = 1; // prime
    return true;
}

int numPrime(int n, int start=1) {
    if (isPrime(n)) return 1;
    int i, sum = 0, sqr = (int) sqrt(n);

    for (i = start+1; i <= sqr && 1 < n; ++i) {
        if (!isPrime(i)) continue; // pass non-prime divider
        while (1 < n && n % i == 0) {
            n /= i;
            sum++;
        }
    }
    if (n == 1) return sum;
    else return sum + numPrime(n, i);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(primes, primes+100005, -1);
    cin >> A >> B;
    for (int n = A; n <= B; ++n) {
        if (isPrime(n)) continue;

        if (isPrime(numPrime(n))) result++;
    }
    cout << result;
}