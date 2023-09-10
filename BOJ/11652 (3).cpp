#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> arr[n];
    }
    sort(arr, arr+N);
    int currentCount=1, maxCount=0;
    ll maxCountedNum=LLONG_MIN;
    for (int n = 1; n < N; n++) {
        if (arr[n] != arr[n-1]) {
            // If cardNumber changed
            if (currentCount > maxCount) {
                maxCountedNum = arr[n-1];
                maxCount = currentCount;
            }
            currentCount = 1;
        }
        else currentCount++;
    }
    if (currentCount > maxCount) maxCountedNum = arr[N-1];
    cout << maxCountedNum;
}

/*
 * Sort() has O(NlogN) time complexity. (In std c++)
 * Insertion => O(1), because it's just a static array.
 * So this code's time complexity is O(NlogN)
 */