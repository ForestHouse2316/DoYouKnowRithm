// 20304 문제처럼, 각자 가장 가까운 주차구역에 대는 것으로부터 시작하여 한번씩 주차자리 양보를 해서 차순위로 가까운 주차자리에 댈 때 임의의 차의 최대 주차시간 계산
// 만약 문제 설명 예시처럼 딴 차가 점령해서 못 세우면 차순위로 차 빼고 그러는 것. 이때 차순위 차차순위도 Q에 푸시



// 주차구역을 점유하고 있음을 알리는 bool lock[] 배열을 만들어 해당 자리의 점유 여부를 확인할 수 있도록 한다.
// 최소 소요시간의 기본값을 INT_MAX로 해놓는다

// 먼저, 자동차 최대 개수가 50이므로 각 차에 대해 리스트를 만들고 BFS를 돌려 가장 가까운 주차구역을 찾는다.

// 한 차를 콕 찝어서(0번째 차량이라던가) 그 차를 먼저 가장 가까운 곳에 놓아줌.
// [반복] 그 다음 차를 가장 가까운 곳에 놓아주되, 안 되면 continue 하고 다음으로 가까운 곳으로 주차
// 가장 처음에 지목된 차량으로 BFS가 돌아오게 되면, 이제 그 차를 차순위로 가까운 주차자리에 배정시켜주고 다시 상기 절차들을 반복

// 최종 차량까지 주차를 완료하면 최대 소요시간을 계산하고 이를 저장한다.
// INT_MAX에서 벗어나 첫 최대 소요시간을 알게 되었다면, 이후 BFS 반복부터는 모든 차를 다 배정할 필요 없이
// 주차구역 점유에 의해 차순위 주차구역을 탐색할 때 최대 소요시간을 넘게 되면 이미 그 주차방식은 글러먹은 것이므로 continue를 수행하도록 하여 BFS 시간단축이 이루어진다.


// 이분매칭법을 이용해보자
// 이분매칭을 이용하여 먼저 첫 자동차를 가장 가까운 존에 주차, 후에 요청이 들어올 때마다 한칸식 우선순위를 늘려감.

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define x first
#define y second
#define num first
#define dist second
queue<p> q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int R, C, tx, ty, loop, cycle, minDist = INT_MAX, cars=0, pzones=0, board[52][52];  // both cars, pzones are the number of each item
char in;
bool vis[52][52], parked[103] = {false};  // parked[pzone number]
p carPos[102], pPos[103];  // pPos is 1-indexed
vector<p> pDist[102];  // pDist[car number] {pzone number , distance}

void park(int car, int localMax) {
    if (car >= cars) {
        minDist = localMax;
        return;
    }
    for (auto& pzone : pDist[car]) {
        if (minDist <= pzone.dist) return;
        if (parked[pzone.num]) continue;

//        cout << "Parking car" << car << " to zone" << pzone.num << " dist = " << pzone.dist << endl;
        parked[pzone.num] = true;
        park(car+1, max(localMax, pzone.dist));
        parked[pzone.num] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> in;
            switch (in) {
                case 'C':
                    carPos[cars++] = {c, r};
                    board[r][c] = -2;
                    break;
                case 'X':
                    board[r][c] = -1;
                    break;
                case '.':
                    board[r][c] = -2;
                    break;
                case 'P':
                    pPos[pzones] = {c, r};
                    board[r][c] = pzones++;  // board arr gets pzone number on pzone's position
                    break;
            }
        }
    }
    if (cars > pzones) {
        cout << -1;
        return 0;
    }


    for (int car = 0; car < cars; ++car) {
        pDist[car].reserve(pzones+1);  // init pDist (reserve memory space)
        for (int r = 0; r < R; ++r) {  // init vis
            fill(vis[r], vis[r]+C+1, false);
        }
        q.push(carPos[car]);
        cycle = 0;  // == distance
        while (!q.empty()) {  // BFS for pDist
            loop = q.size();
            cycle++;
            for (int l = 0; l < loop; ++l) {
                for (int i = 0; i < 4; ++i) {
                    tx = dx[i] + q.front().x;
                    ty = dy[i] + q.front().y;
                    if (tx < 0 || ty < 0 || tx >= C || ty >= R || board[ty][tx] == -1 || vis[ty][tx]) continue;
                    vis[ty][tx] = true;
                    q.emplace(tx, ty);
                    if (board[ty][tx] >= 0) {
                        pDist[car].emplace_back(board[ty][tx], cycle);
//                        cout << "Car" << car << " > Zone" << board[ty][tx] << " dist = " << cycle << endl;
                    }
                }
                q.pop();
            }
        }
//        cout << "Car" << car << " has parking-able zone " << pDist[car].size() << endl;
        if (pDist[car].empty()) {
            cout << -1;
            return 0;
        }
    }

    park(0, 0);
    cout << minDist;
}