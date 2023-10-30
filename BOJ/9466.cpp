#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define first first
#define second second
int T, N, in, currentStu, choose[100005];  // 1-indexed
int visited[100005] = {0};  // 1-indexed : used to check circulation of the current DFS

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    for (int t = 0; t < T; t++) {
        int remained = 0, myIndex[100005] = {0};  // 1-indexed : shows whether [n] is grouped/remained or not
        cin >> N;

        for (int n = 1; n <= N; n++) {
            cin >> in;
            choose[n] = in;
        }

        for (int n = 1; n <= N; n++) {  // DFS start
            // if visited[i] == n, it means we visited that node in current loop
            if (myIndex[n]) continue;

            stack<int> s;
            visited[n] = n;
            s.push(n);
            myIndex[n] = s.size();  // myIndex value starts with 1

            while (true) {
                currentStu = s.top();

                if (myIndex[choose[currentStu]] > 0 && visited[choose[currentStu]] != n) {  // previous loop visited => indicating grouped student
                    remained += s.size();
                    break;
                }

                if (visited[choose[currentStu]] != n) {
                    visited[choose[currentStu]] = n;  // IMPORTANT : Do this before push() if you don't use temp variable like currentStu
                    s.push(choose[currentStu]);  // push newly chosen student
                    myIndex[choose[currentStu]] = s.size();
                }
                else {  // if circulation found
                    int endpoint = choose[currentStu];
//                    while (s.top() != endpoint) s.pop();  // TODO 커스텀 스택 만들어서 endpoint가 어디에 위치하는지 쿼리한 후 remain을 빠르게 구하거나 자신의 인덱스를 저장하는 배열을 또 만들어 바로 구하도록 함
//                    s.pop();
//                    remained += s.size();
                    remained += myIndex[endpoint] - 1;
                    break;
                }
            }
        }
        cout << remained << "\n";
    }
}