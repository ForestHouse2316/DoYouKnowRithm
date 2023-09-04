#include <bits/stdc++.h>
#define R first
#define C second
#define GUNGYE 7
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
// 궁예는 다 보인다 이말이야
using namespace std;
typedef pair<int, int> coord;



// 시시티비의 모든 방향 바로 앞에 벽이 있으면 돌려돌려 돌림판 해주는 것으로 최적화 가능할듯?
// 변경된 칸들의 좌표pair 값을 stack에 넣어 관리하면 정말 밥도둑이 따로 없을 것 같다.
// 그럼 백트래킹 w/ STACK 문제라고 볼 수 있겠다.
// "극한최적화"를 위해 상태트리를 다시 그려봅시다. 카메라 회전하면서 변경되는 부분만 체크하는 편이 아주 훌륭할 터.. => 카메라별 ChangeHistory
// 빠킹독에 의하면, 극한최적화 안 해도 충분히 통과된다고 한다. 참고로 이 코드의 실행시간은 고작 4ms 이다.



int N, M;  // N is row, M is col
int room[8][8];  // Set non-blindSpot as -1
int minBlindSpot = 100;  // Actually, it's maximum value is 64 because max(N*M) == 64
int tnoCamera = 0;

int cameraRotationTime[5] = {4, 2, 4, 4, 1};
// N.1 E.2 S.4 W.8
// NESW => 0123
// [Camera Type][Rotation Time]
int cameraSight[5][4] = {{1,  2 , 4 , 8},
                         {5,  10},
                         {3,  6,  12, 9},
                         {11, 7,  14, 13},
                         {15}};

coord cameraPositions[8];
stack<coord> cameraHistory[8][4];  // [CameraNum][SightDirection]

void log() {
    cout << ".";
}

void checkBlindSpotAndUpdate() {
    int currentBlindSpot = 0;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (!room[n][m]) currentBlindSpot++;
        }
    }
    minBlindSpot = min(minBlindSpot, currentBlindSpot);
}

void sightRollback(stack<coord> &history) {
    while (!history.empty()) {
        coord toRollback = history.top();
        room[toRollback.R][toRollback.C] = 0;
        history.pop();
    }
}

void rotateCamera(int cameraNum) {
    if (cameraNum >= tnoCamera) {
        checkBlindSpotAndUpdate();
        return;
    }

    coord cameraPos = cameraPositions[cameraNum];
    int cameraType = room[cameraPos.R][cameraPos.C] - 1;  // Cuz arr idx starts w/ 0
    for (int rotationTime = 0; rotationTime < cameraRotationTime[cameraType]; rotationTime++) {
        int sight = cameraSight[cameraType][rotationTime];

        // N
        if (sight & 1 && cameraHistory[cameraNum][NORTH].empty()) {
            for (int r = cameraPos.R-1; r >= 0 ; r--) {
                // if 6, break | if 0, set as GUNGYE
                if (room[r][cameraPos.C] == 6) break;
                if (!room[r][cameraPos.C]){
                    room[r][cameraPos.C] = GUNGYE;
                    cameraHistory[cameraNum][NORTH].emplace(r, cameraPos.C);
                }
            }
        }
        else if (!(sight & 1)) {
            sightRollback(cameraHistory[cameraNum][NORTH]);
        }

        // E
        if (sight & 2 && cameraHistory[cameraNum][EAST].empty()) {
            for (int c = cameraPos.C + 1; c < M ; c++) {
                if (room[cameraPos.R][c] == 6) break;
                if (!room[cameraPos.R][c]){
                    room[cameraPos.R][c] = GUNGYE;
                    cameraHistory[cameraNum][EAST].emplace(cameraPos.R,  c);
                }
            }
        }
        else if (!(sight & 2)) {
            sightRollback(cameraHistory[cameraNum][EAST]);
        }

        // S
        if (sight & 4 && cameraHistory[cameraNum][SOUTH].empty()) {
            for (int r = cameraPos.R+1; r < N; r++) {
                if (room[r][cameraPos.C] == 6) break;
                if (!room[r][cameraPos.C]){
                    room[r][cameraPos.C] = GUNGYE;
                    cameraHistory[cameraNum][SOUTH].emplace(r, cameraPos.C);
                }
            }
        }
        else if (!(sight & 4)) {
            sightRollback(cameraHistory[cameraNum][SOUTH]);
        }

        // W
        if (sight & 8 && cameraHistory[cameraNum][WEST].empty()) {
            for (int c = cameraPos.C - 1; c >= 0 ; c--) {
                if (room[cameraPos.R][c] == 6) break;
                if (!room[cameraPos.R][c]){
                    room[cameraPos.R][c] = GUNGYE;
                    cameraHistory[cameraNum][WEST].emplace(cameraPos.R,  c);
                }
            }
        }
        else if (!(sight & 8)) {
            sightRollback(cameraHistory[cameraNum][WEST]);
        }

        rotateCamera(cameraNum+1);

    }

    sightRollback(cameraHistory[cameraNum][NORTH]);
    sightRollback(cameraHistory[cameraNum][EAST]);
    sightRollback(cameraHistory[cameraNum][SOUTH]);
    sightRollback(cameraHistory[cameraNum][WEST]);
}

int main() {
    cin >> N; cin >> M;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> room[n][m];
            if (room[n][m] != 0 && room[n][m] != 6) cameraPositions[tnoCamera++] = make_pair(n, m);
        }
    }

    rotateCamera(0);
    cout << minBlindSpot;

}