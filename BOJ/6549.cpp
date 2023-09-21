#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define from first
#define height second
ll N;
ll H[100005];
stack<p> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    do {
        cin >> N;
        for (int n = 0; n < N; n++) {
            cin >> H[n];
            // 스택에 푸시하고.. 크기 늘어나는 부분에서 말임
            // 그리고 후에 높이 줄어들면, 그 높이 줄어든거 감당 못하는 것들 최종 크기 결과 내서 pop
        }
    } while(N != 0);
}