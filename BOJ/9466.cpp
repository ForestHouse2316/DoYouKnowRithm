#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define first first
#define second second
int T, N, in, currentStu, choose[100005];  // 1-indexed

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    for (int t = 0; t < T; t++) {
        int remained = 0;
        bool checked[100005] = {false};  // 1-indexed : shows whether [n] is grouped/remained or not
        cin >> N;

        for (int n = 1; n <= N; n++) {
            cin >> in;
            choose[n] = in;
        }

        for (int n = 1; n <= N; n++) {  // DFS start
            if (checked[n]) continue;

            stack<int> s;
            bool visited[100005] = {false};  // 1-indexed : used to check circulation of the current DFS
            checked[n] = true;
            visited[n] = true;
            s.push(n);

            while (true) {
                currentStu = s.top();

                if (checked[choose[currentStu]] && !visited[choose[currentStu]]) {  // indicating grouped student
                    remained += s.size();
                    break;
                }

                if (!visited[choose[currentStu]]) {
                    visited[choose[currentStu]] = true;  // IMPORTANT : Do this before push() if you don't use temp variable like currentStu
                    checked[choose[currentStu]] = true;
                    s.push(choose[currentStu]);  // new student
                }
                else {  // if circulation found
                    int endpoint = choose[currentStu];
                    while (s.top() != endpoint) s.pop();
                    s.pop();

                    remained += s.size();
                    break;
                }
            }
        }
        cout << remained << "\n";
    }
}