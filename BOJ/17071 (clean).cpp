#include <bits/stdc++.h>
using namespace std;
int N, K, loop, secLimit, joinSec, minJoinSec, deltaT, currentSec = 0;
int posK[1005];  // posK[sec]
bool visited[2][500005] = {false};  // visited[time%2][pos]
queue<int> q;

int indexOf(int value) {
    int s=0, e=secLimit-1, m;
    while (s <= e) {
        m = (s+e)/2;
        if (posK[m] == value) return m;
        else if (posK[m] < value) s = m+1;
        else e = m-1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    if (N == K) {
        cout << 0;
        return 0;
    }

    // pre-calculated path of the brother
    posK[0] = K;
    for (secLimit = 1; secLimit < 1005 && posK[secLimit - 1] < 500000; secLimit++) {
        posK[secLimit] = posK[secLimit - 1] + secLimit;
    }
    minJoinSec = secLimit;  // actual 'final chance' to catch brother is [secLimit-1]

    q.push(N);
    while (!q.empty() && currentSec < minJoinSec) {
        currentSec++;

        loop = q.size();
        while (loop--) {
            for(int jump : {q.front()-1, q.front()+1, q.front()*2}) {
                if (jump < 0 || jump > 500000 || visited[currentSec%2][jump]) continue;
                visited[currentSec%2][jump] = true;
                q.push(jump);

                joinSec = indexOf(jump);
                // if not a brother's route || too late to catch brother || bigger than minJoinSec
                if (joinSec <= 0 || joinSec < currentSec || joinSec >= minJoinSec) continue;

                deltaT = joinSec - currentSec;
                if (deltaT%2 == 0) minJoinSec = joinSec;

            }
            q.pop();
        }
    }
    if (minJoinSec == secLimit) cout << -1;
    else cout << minJoinSec;
}