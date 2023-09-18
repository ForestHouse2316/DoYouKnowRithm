#include <bits/stdc++.h>
#define index first
#define value second
using namespace std;
typedef pair<int, int> p;

int N;
stack<int> tower;
stack<p> temp;
int result[500005] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    int in;
    for (int n = 0; n < N; n++) {
        cin >> in;
        tower.push(in);
    }

    for (int n = N; n > 0; n--) {
        while(!temp.empty() && tower.top() > temp.top().value) {
            result[temp.top().index] = n;
            temp.pop();
        }
        temp.emplace(n, tower.top());
        tower.pop();
    }

    for (int n = 1; n <= N ; n++) {
        cout << result[n] << " ";
    }
}