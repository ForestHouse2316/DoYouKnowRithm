/// reference : https://coloredrabbit.tistory.com/124
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> ill;
#define Acc first
#define Sum second
#define merge(x) (x.Sum + (ll) x.Acc)

int R, C, self, shift = false; // for sliding window
ll score[2] = {};
ill dpU[2][2][1005] = {}, dpUL[2][2][1005] = {}, dpUR[2][2][1005] ={}, dpL, dpR; // dp[shift][M/S][col], column is 1-indexed
char msArr[] = "MS", in[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    in[0] = '.';
    cin >> R >> C;
    for (int r = 0; r < R; ++r, shift = !shift) { // row & cached array shift, shift is current window(prev row)
        cin >> (in + 1);
        memset(dpU[!shift], 0, sizeof dpU[!shift]);
        memset(dpUL[!shift], 0, sizeof dpUL[!shift]);
        memset(dpUR[!shift], 0, sizeof dpUR[!shift]);

        for (int ms = 0; ms < 2; ++ms) { // M/S target shift
            dpL = {};
            for (int c = 1; c <= C; ++c) { // col ->
                self = in[c] == msArr[ms];
                if (self) score[ms] += merge(dpU[shift][ms][c]) + merge(dpUL[shift][ms][c - 1]) + merge(dpUR[shift][ms][c + 1]) + merge(dpL);

                dpU[!shift][ms][c].Sum = merge(dpU[shift][ms][c]);
                dpU[!shift][ms][c].Acc = dpU[shift][ms][c].Acc + self;

                dpL.Sum += dpL.Acc;
                dpL.Acc += self;

                dpUL[!shift][ms][c].Sum = merge(dpUL[shift][ms][c - 1]) + merge(dpU[shift][ms][c]) + dpL.Sum;
                dpUL[!shift][ms][c].Acc = dpUL[shift][ms][c - 1].Acc + dpU[shift][ms][c].Acc + dpL.Acc; // dpL.Acc contains (+ self)
            }

            dpR = {};
            for (int c = C; c >= 1; --c) { // col <-
                self = in[c] == msArr[ms];

                dpR.Sum += dpR.Acc;
                dpR.Acc += self;

                dpUR[!shift][ms][c].Sum = merge(dpUR[shift][ms][c + 1]) + dpU[!shift][ms][c].Sum + dpR.Sum;
                dpUR[!shift][ms][c].Acc = dpUR[shift][ms][c + 1].Acc + dpU[shift][ms][c].Acc + dpR.Acc; // dpR.Acc contains (+self)
            }
        }
    }


    cout << score[0] << ' ' << score[1];
}