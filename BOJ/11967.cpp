#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
queue<p> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
int N, M, x, y, a, b, lights = 0, board[105][105] = {0}, accessible[105][105] = {false};  // 1-indexed
vector<p> switches[105][105];  // switches[Y][X] pair<X, Y>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    board[1][1] = 1;
    accessible[1][1] = true;
    cin >> N >> M;
    for (int m = 0; m < M; m++) {
        cin >> x >> y >> a >> b;
        switches[y][x].emplace_back(a, b);
    }
    // TODO 해당 방에서 작동 가능한 스위치를 모조리 건드리고 불이 켜지면 board 의 값을 lighting 으로 바꾸든가 하여 표시
    // TODO 항상 불이 루트 순서대로 켜질 것이라는 보장이 없다. 그러므로 방의 스위치를 켜면 주변으로 BFS를 수행하여 accessible한 곳과 만나는지 판단할것
    // TODO 또한 그렇게 주변을 조사한 결과 accessible 하다면, 그 타일을 accessible 하다고 바꿀 것

    // TODO 그리고 불 켜진 방에서 BFS 할 때, 출발지가 accessible 하다면 BFS로 탐색한 곳을 다시 accessible 하다고 업데이트 해줄것.
    // TODO 처음에 non-accessible 했는데 다시 accessible 하게 됐을 경우 또한 있기 때문임.

    // TODO accessible 을 true 로 설정하면서 동시에 lights++ 해주기
}