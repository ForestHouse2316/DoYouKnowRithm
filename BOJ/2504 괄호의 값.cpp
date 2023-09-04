#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    string line;
    int sum = 0;
    bool isValid = true;
    getline(cin, line);

    // First, validate
    stack<char> validationStack;
    for(auto c : line) {
        switch (c) {
            case '(':
            case '[':
                validationStack.push(c);
                break;
            case ')':
                if (validationStack.empty() || validationStack.top() != '(') isValid = false;
                else validationStack.pop();
                break;
            case ']':
                if (validationStack.empty() || validationStack.top() != '[') isValid = false;
                else validationStack.pop();
                break;
        }
    }
    if (!isValid || !validationStack.empty()) {
        cout << 0 << endl;
        return 0;
    }


    // Calculate
    // Consider ( as -1, [ as -2
    for (auto c : line) {
        switch (c) {
            case '(':
                s.push(-1);
                break;
            case '[':
                s.push(-2);
                break;
            case ')':
                if (s.top() == -1) {
                    s.pop();
                    s.push(2);
                } else {
                    int partialSum = 0;
                    while (s.top() > 0) { // while number
                        partialSum += s.top();
                        s.pop();
                    }
                    s.pop(); // remove (
                    s.push(partialSum * 2);
                }
                break;
            case ']':
                if (s.top() == -2) {
                    s.pop();
                    s.push(3);
                } else {
                    int partialSum = 0;
                    while (s.top() > 0) { // while number
                        partialSum += s.top();
                        s.pop();
                    }
                    s.pop(); // remove [
                    s.push(partialSum * 3);

                }
                break;
        }
    }

    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum << endl;
}