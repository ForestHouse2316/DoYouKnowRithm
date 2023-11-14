#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
#define first first
#define second second
int N, K, loop, secLimit, joinSec, minJoinSec, deltaT, dist[500005], currentSec = 0, minDoubleDelayTime;
int posK[1005];  // posK[sec]
bool visited[500005] = {false};
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

    // pre-calculated path of young brotherrrr
    posK[0] = K;
    for (secLimit = 1; secLimit < 1005 && posK[secLimit - 1] < 500000; secLimit++) {
        posK[secLimit] = posK[secLimit - 1] + secLimit;
    }
    minJoinSec = secLimit;  // actual 'final chance' to catch brother is [secLimit-1]
//    cout << "LIMIT : " << secLimit << endl;


    q.push(N);
//    visited[N] = true;
    while (!q.empty() && currentSec < minJoinSec) {
        currentSec++;

        loop = q.size();
        while (loop--) {
            for(int jump : {q.front()-1, q.front()+1, q.front()*2}) {
                if (jump < 0 || jump > 500000 || visited[jump]) continue;
                visited[jump] = true;

                joinSec = indexOf(jump);
                deltaT = joinSec - currentSec;
//                if (joinSec > 0) cout << jump << ">> join on " << joinSec << "s, time left " << deltaT << "s" << endl;

                if (deltaT == 0 && currentSec <= minJoinSec) {
                    cout << currentSec;
                    return 0;
                }
                else if (deltaT > 0 && joinSec < minJoinSec) {  // if binSearch succeeded && it's a future junction && smaller than min
                    if (deltaT % 2 == 0) minJoinSec = joinSec;  // use back and forth waiting method
                    else {
                        // odd second(s) waiting, use *2 waiting method
                        minDoubleDelayTime = (jump + 1) / 2 + 1;
                        if (minDoubleDelayTime%2 == 0) minDoubleDelayTime += 1;
                        if (minDoubleDelayTime <= deltaT) minJoinSec = joinSec;
                    }
                    // If NOT, we cannot be in current position after remained time before her brother came
                    // Second condition is about waiting trick that uses *2 to waiting. (e.g. from 3 to 3: 3>2>4>3 takes 3 seconds)
                }
                
                q.push(jump);
            }
            q.pop();
        }
    }
    if (minJoinSec == secLimit) cout << -1;
    else cout << minJoinSec;
}