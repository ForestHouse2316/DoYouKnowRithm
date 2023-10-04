#include <bits/stdc++.h>
using namespace std;
deque<int> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, rotation, times = 0;
    cin >> N; cin >> M;

    for (int n = 1; n <= N; n++) {
        d.push_back(n);
    }

    int target;
    for (int m = 0; m < M; m++) {
        cin >> target;
        if (d.front() == target) d.pop_front();
        else if (d.back() == target) {
            d.pop_back();
            times++;
        }
        else {
            rotation = 0;
            while(d.front() != target) {
                d.push_back(d.front());
                d.pop_front();
                rotation++;
            }

            if (d.size()/2 < rotation && d.size() > 3) {
                // pop from back + move to front
                times += (int) d.size() - rotation;  // If able to pop from back, add -1
            }
            else {
                // pop from front
                times += rotation;
            }
            d.pop_front();
        }
    }
    cout << times;
}