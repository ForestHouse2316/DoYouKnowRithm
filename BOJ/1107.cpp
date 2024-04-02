#include <bits/stdc++.h>
using namespace std;
int N, M, in, minMove, sum, len, counter[7], cached[7] = {0}, channel = -1;
vector<int> v;
bool disabled[12] = {false};

void toInt() {
    channel = 0;
    for (int i = 0; i < 7; ++i) {
        if (counter[i] == -1) break;
        channel += cached[i];
    }
}

void cache(int pos) {
    if (counter[pos] == -1) return;
    cached[pos] = v[counter[pos]] * (int) pow(10, pos);
}

void count(int pos) {
    counter[pos]++;
    if (counter[pos] == v.size()) { // overflow
        counter[pos] = 0;
        if (counter[pos+1] == -1 && v[0] == 0) counter[pos+1]++;
        count(pos+1);
    }
    cache(pos);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    v.reserve(10);
    fill(counter, counter+7, -1);
    cin >> N >> M;
    for (int m = 0; m < M; ++m) {
        cin >> in;
        disabled[in] = true;
    }

    minMove = abs(N - 100);

    // shortcuts
    if (M == 10 || 99 <= N && N <= 101) {
        cout << minMove;
        return 0;
    }
    if (M == 9 && !disabled[0]) {
        cout << min(minMove, abs(N)+1);
        return 0;
    }

    for (int i = 0; i < 10; ++i) {
        if (!disabled[i]) v.push_back(i); // ascending order
    }
    len = (int) log10(N);
    if (len > 0) {
        for (int i = 0; i < len-1; ++i) {
            counter[i] = v.size()-1;
            cache(i);
        }
    }

    while (channel <= N) {
        count(0);
        toInt();
        minMove = min(abs(N-channel) + (int) log10(channel < 1 ? 1 : channel) + 1, minMove);
    }
    cout << minMove;
}