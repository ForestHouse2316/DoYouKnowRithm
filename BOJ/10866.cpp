#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

const int SIZE = MAX * 2 + 1;
int currentSize = 0;
int t = MAX, h = MAX;
int dq[SIZE];

// 본 코드에서는 T가 현재 데이터 끝자락보다 앞에, H가 현재 데이터 끝자락을 가리켜 T와 H의 충돌을 방지
// 당연히 반대로 하여도 무방
// push는 restriction 안 걸려있음

void push_back(int n) {
    // 놓고 점프
    dq[t++] = n;
    currentSize++;
    if (t == SIZE) {
        t = 0;
    }
}

void push_front(int n) {
    // 점프 놓기
    if (h == 0) {
        h = SIZE;
    }
    dq[--h] = n;
    currentSize++;
}

void pop_back() {
    if (currentSize == 0) {
        cout << -1 << endl;
        return;
    }
    currentSize--;
    if (t == 0) {
        t = SIZE;
    }
    cout << dq[--t] << endl;
}

void pop_front() {
    if (currentSize == 0) {
        cout << -1 << endl;
        return;
    }
    currentSize--;
    cout << dq[h++] << endl;
    if (h == SIZE) {
        h = 0;
    }
}

void front() {
    if (currentSize == 0) {
        cout << -1 << endl;
        return;
    }
    cout << dq[h] << endl;
}

void back() {
    if (currentSize == 0) {
        cout << -1 << endl;
        return;
    }
    cout << dq[t-1] << endl;
}

int main() {
    int cmdT;
    cin >> cmdT;
    string cmd;
    while (cmdT--) {
        cin >> cmd;
        if (cmd == "push_front") {
            int n;
            cin >> n;
            push_front(n);
        }
        else if (cmd == "push_back") {
            int n;
            cin >> n;
            push_back(n);
        }
        else if (cmd == "pop_front") {
            pop_front();
        }
        else if (cmd == "pop_back") {
            pop_back();
        }
        else if (cmd == "size") {
            cout << currentSize << endl;
        }
        else if (cmd == "empty") {
            cout << !((bool) currentSize) << endl;
        }
        else if (cmd == "front") {
            front();
        }
        else if (cmd == "back") {
            back();
        }
    }
}