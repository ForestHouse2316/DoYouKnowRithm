#include <bits/stdc++.h>
using namespace std;
#define f q.front()
#define val first
#define pre second
#define bin first
#define done 1
#define brak 2
int T, depth, loop, offset, in, calc, calcUnit, calcTenth, tracer, result;
vector<int> gg;
vector<pair<bool, int>> history;
bool vis[2][22002];

bool like(int num) {
    if (num == 0) return false;
    for (int i = 0; i <= log(num); ++i) {
        if (num / (int) pow(10, i) % 10 > 1) return false;
    }
    return true;
}

vector<int> googoo(short& top) {
    gg.clear();
    for (int times = (depth==0); times < 10; ++times) {
        calc = in * times + top;
        calcUnit = calc % 10;
        if (calcUnit <= 1) {
            calcTenth = calc / 10;
            if (vis[calcUnit][calcTenth]) continue;

            gg.push_back(calc);
            vis[calcUnit][calcTenth] = true;
        }
    }
    return gg;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    history.reserve(65536);
    gg.reserve(10);
    cin >> T;
    for (int t = 0; t < T; ++t) {
        // init per testcase
        queue<pair<short, int>> q;
        q.emplace(0, -1);
        history.clear();
        depth = -1;
        result = 0;
        offset = 0;
        fill(vis[0], vis[0]+22002, false);
        fill(vis[1], vis[1]+22002, false);

        cin >> in;
        if (like(in)) { // already favorite number
            cout << in << "\n";
            continue;
        }
        while (in % 10 == 0) {
            offset++;
            in /= 10;
        }
        while (!result && depth < 100) {
            depth++;
            loop = q.size();
            while (loop-- && !result) {
                for (int eligible : googoo(f.val)) {
                    if (log(eligible) + depth + 1 > 100) {  // because googoo(f) is ascending order
                        result = brak;
                        break;
                    }
                    if (like(eligible)) {
                        cout << eligible;
                        tracer = f.pre;
                        while (tracer != -1) {
                            cout << history[tracer].bin;
                            tracer = history[tracer].pre;
                        }
                        while (offset--) cout << 0;
                        result = done;
                        break;
                    }
                    q.emplace(eligible / 10, history.size());
                    history.emplace_back(eligible % 10, f.pre);
                }
                q.pop();
            }
        }
        if (result == brak) cout << "BRAK";
        cout << "\n";
    }
}