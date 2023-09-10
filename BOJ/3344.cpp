#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int remainder = N % 6;
    if (remainder == 2) {
        for (int col = 2; col <= N; col += 2) {
            cout << col << "\n";
        }
        cout << 3 << "\n";
        cout << 1 << "\n";
        for (int col = 7; col <= N; col += 2) {
            cout << col << "\n";
        }
        cout << 5 << "\n";
    } else if (remainder == 3) {
        for (int col = 4; col <= N; col += 2) {
            cout << col << "\n";
        }
        cout << 2 << "\n";
        for (int col = 5; col <= N; col += 2) {
            cout << col << "\n";
        }
        cout << 1 << "\n";
        cout << 3 << "\n";
    } else {
        for (int col = 2; col <= N; col += 2) {
            cout << col << "\n";
        }
        for (int col = 1; col <= N; col += 2) {
            cout << col << "\n";
        }
    }
}

// N-Queen 의 예시 출력문제
/*
꼭짓점에 놓으면 안된다. 거기다가 두면 답이 없어짐 그냥...

/ 겹침 판단법 : x+y 의 값이 같으면 겹치는 것
\ 겹침 판단법 : y-x 의 값이 같으면 겹치는 것

로직 : https://en.wikipedia.org/wiki/Eight_queens_puzzle

*/