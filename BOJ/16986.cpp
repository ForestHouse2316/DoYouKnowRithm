#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define a first
#define b second
typedef pair<int, int> pii;

int N, K, table[9][9];
int hands[2][20]; // [Gyeong, Min][nth hand]
int perm[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    if (N < K || N == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 20; ++j) {
            cin >> hands[i][j]; hands[i][j]--; // offset (-1)
        }
    }

    bool succeed = false;
    do {
        int score[3] = {}, curIdx[3] = {}, curOpp = 1, nextOpp; // 0 = GM, 1 = JG, 2 = JM
        while (1) {
            if (curOpp != 0) {
                if (table[perm[curIdx[0]]][hands[curOpp-1][curIdx[curOpp]]] == 2) {
                    score[0]++;
                    if (score[0] == K) {
                        succeed = true;
                        break;
                    }
                    nextOpp = (curOpp == 1 ? 2 : 1);
                }
                else {
                    score[curOpp]++;
                    if (score[curOpp] == K) break;
                    nextOpp = 0;
                }

                curIdx[0]++; curIdx[curOpp]++;
                if (curIdx[0] == N) break;
            }
            else {
                if (table[hands[0][curIdx[1]]][hands[1][curIdx[2]]] == 2) {
                    score[1]++;
                    if (score[1] == K) break;
                    nextOpp = 1;
                }
                else {
                    score[2]++;
                    if (score[2] == K) break;
                    nextOpp = 2;
                }

                curIdx[1]++; curIdx[2]++;
            }
            curOpp = nextOpp;
        }
    } while (!succeed && next_permutation(perm, perm + N));
    cout << (int) succeed;
}