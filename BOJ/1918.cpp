#include <bits/stdc++.h>
using namespace std;

string in;
stack<char> op;
queue<char> builder;

void flushPhase() {
    while (!op.empty() && op.top() != '(') {
        builder.push(op.top());
        op.pop();
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> in;

    for (int i = 0; i < in.length(); ++i) {
        switch (in[i]) {
            case '(':
                op.push(in[i]); // (
                break;
            case ')':
                flushPhase();
                op.pop(); // (
                break;
            case '+':
            case '-':
                flushPhase();
                op.push(in[i]); // + or -
                break;
            case '*':
            case '/':
                if (!op.empty() && (op.top() == '*' || op.top() == '/')) { // priority (L -> R)
                    builder.push(op.top());
                    op.pop();
                }
                op.push(in[i]); // * or /
                break;
            default:
                builder.push(in[i]);
                break;
        }
    }
    while (!op.empty()) {
        builder.push(op.top());
        op.pop();
    }
    while (!builder.empty()) {
        cout << builder.front();
        builder.pop();
    }
}