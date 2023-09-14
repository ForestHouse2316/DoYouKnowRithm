#include <bits/stdc++.h>
using namespace std;
list<int> people;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N;
    cin >> K;
    for (int n = 1; n <= N; n++) {
        // Init linked list
        people.push_back(n);
    }

    cout << "<";
    auto it = people.begin();
    list<int>::iterator del;
    for (int n = 0; n < N; n++) {
        for (int i = 0; i < (K - 1) % people.size(); i++) {
            if (++it == people.end()) it = people.begin();
        }
        cout << *it << (n == N - 1 ? "" : ", ");
        del = it;
        if (++it == people.end()) it = people.begin();
        people.erase(del);
    }
    cout << ">";
}