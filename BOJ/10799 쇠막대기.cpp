#include <bits/stdc++.h>
using namespace std;

int main() {
    int holdingSticks = 0;
    int sum = 0;
    bool canBeLaser = false; // True when open parenthesis input
    string line;
    getline(cin, line);
    for (auto c : line) {
        if (c == '(') {
            holdingSticks++;
            canBeLaser = true;
        }
        else if (c == ')') {
            if (canBeLaser) {
                // cut
                sum += holdingSticks-1;
                canBeLaser = false;
            }
            else {
                // count remain
                sum++;
            }
            holdingSticks--;
        }
    }
    cout << sum << endl;
}