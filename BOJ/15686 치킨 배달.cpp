#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> coord;

int N, M;
int village[50][50];  // village map
vector<coord> storeCoord;
vector<coord> houseCoord;
int minChickenDist = 0;

int absDist(coord a, coord b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N; cin >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> village[i][j];
            switch (village[i][j]) {
                case 1:
                    houseCoord.emplace_back(i, j);
                    break;
                case 2:
                    storeCoord.emplace_back(i, j);
                    break;
            }
        }
    }


    vector<int> combination(storeCoord.size(), 1);  // Store selecting combination
    fill(combination.begin(), combination.begin() + storeCoord.size() - M, 0);  // 1 mean select
    do {
        bool init = true;
        vector<int> minDist(houseCoord.size());
        // For each store
        for (int s = 0; s < storeCoord.size(); s++) {
            // If s-th store is selected
            if (combination[s] == 1) {
                if (init) {
                    init = false;
                    for (int h = 0; h < houseCoord.size(); h++) {
                        minDist[h] = absDist(storeCoord[s], houseCoord[h]);
                    }
                }
                else {
                    for (int h = 0; h < houseCoord.size(); h++) {
                        minDist[h] = min(minDist[h], absDist(storeCoord[s], houseCoord[h]));
                    }
                }
            }
        }
        if (minChickenDist == 0) {
            for (auto d : minDist) {
                minChickenDist += d;
            }
        }
        else {
            int sum = 0;
            for (auto d : minDist) {
                sum += d;
            }
            minChickenDist = min(minChickenDist, sum);
        }
    } while (next_permutation(combination.begin(), combination.end()));

    cout << minChickenDist;
}

