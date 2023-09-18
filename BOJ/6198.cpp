#include <bits/stdc++.h>
using namespace std;
int N;
stack<int> building;
long long sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    int in;
    for (int n = 0; n < N; n++) {
        cin >> in;
        while (!building.empty() && building.top() <= in) {
            building.pop();
        }
        sum += (int) building.size();  // N < 80k , so can be cast to integer
        building.push(in);
    }
    cout << sum;
}