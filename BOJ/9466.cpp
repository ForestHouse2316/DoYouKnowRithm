#include <bits/stdc++.h>
using namespace std;
int T, N, cnt, currentStu, choose[100005];  // 1-indexed
int visited[100005];  // 1-indexed : used to check circulation of the current DFS, visited[i] = n means we visited it in n-th cycle
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int n = 1; n <= N; n++) {
            cin >> choose[n];
        }
        fill(visited+1, visited+N+1, 0);
        cnt = 0;

        for (int n = 1; n <= N; n++) {  // DFS
            if (visited[n] != 0) continue; // if already visited in current/prev loop

            currentStu = n;
            while (true) {
                visited[currentStu] = n;
                currentStu = choose[currentStu];  // next student
                if (visited[currentStu] == n) {  // met the node visited in current loop
                    while (visited[currentStu] != -1) {
                        cnt++;
                        visited[currentStu] = -1;
                        currentStu = choose[currentStu];
                    }
                    break;
                }
                else if (visited[currentStu] != 0) break; // previously visited node
            }
        }
        cout << N - cnt << '\n';
    }
}