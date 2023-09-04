#include <bits/stdc++.h>
using namespace std;

int N, S;
int wholeSet[20];
stack<int> sum;
int num;

void sumAll(int offset) {
    sum.push(sum.top() + wholeSet[offset]);
    num += sum.top() == S;

    for (int i = offset+1; i < N; i++) {
        sumAll(i);
    }
    sum.pop();
}

int main() {
    cin >> N;
    cin >> S;
    sum.push(0);
    for (int i = 0; i < N; i++) {
        cin >> wholeSet[i];
    }
    for (int i = 0; i < N; i++) {
        sumAll(i);
    }
    cout << num;
}