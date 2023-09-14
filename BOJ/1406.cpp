#include <bits/stdc++.h>
using namespace std;
list<char> charSeq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int M;
    cin >> str;
    for (char c : str) {
        charSeq.push_back(c);
    }
    auto it = charSeq.end();
    auto del = it;
    cin >> M;
    char ch;
    for (int m = 0; m < M; m++) {
        cin >> ch;
        switch (ch) {
            case 'L':
                if (it != charSeq.begin()) it--;
                break;
            case 'D':
                if (it != charSeq.end()) it++;
                break;
            case 'B':
                if (it != charSeq.begin()) {
                    del = --it;
                    it++;
                    charSeq.erase(del);
                }
                break;
            case 'P':
                cin >> ch;
                charSeq.insert(it, ch);
                break;
        }
    }
    for (char c : charSeq) {
        cout << c;
    }
}