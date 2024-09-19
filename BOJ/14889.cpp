#include <bits/stdc++.h>
using namespace std;

int N, synergy[20][20], comb[20], t1Sum, t2Sum, minDiff = INT_MAX;
vector<int> t1, t2;

int cross(int i, int j) {
    return synergy[i][j] + synergy[j][i];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> synergy[i][j];
        }
    }
    fill(comb, comb+20, 1);
    fill(comb, comb+(N/2), 0);

    do {
        t1Sum = t2Sum = 0;
        t1.clear(); t2.clear();

        for (int i = 0; i < N; ++i) { // make team
            if (comb[i] == 0) t1.push_back(i);
            else t2.push_back(i);
        }

        for (int i = 0; i < N / 2 - 1; ++i) { // calc synergy btw teammates
            for (int j = i+1; j < N / 2; ++j) {
                t1Sum += cross(t1[i], t1[j]);
                t2Sum += cross(t2[i], t2[j]);
            }
        }

        minDiff = min(minDiff, abs(t1Sum - t2Sum));
        if (minDiff == 0) break;
    } while (next_permutation(comb, comb+N));

    cout << minDiff;
}