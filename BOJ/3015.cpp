#include <bits/stdc++.h>
#define height first
#define num second
using namespace std;
typedef pair<int, int> p;
int N;
stack<p> s;
long long sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    int in;
    for (int n = 0; n < N; n++) {
        cin >> in;

        if (s.empty()) s.emplace(in, 1);
        else if (s.top().height > in) {
            // [BIG(s) , single input]
            sum++;
            s.emplace(in, 1);
        }
        else if (s.top().height == in) {
            if ((int) s.size() >= 2) {
                // [BIG(s) , same , same input]
                sum += s.top().num + 1;  // Current duplicate + Prev BIG
            }
            else {
                // [same , same input]
                sum += s.top().num;
            }

            s.top().num++;
        }
        else {
            // [BIG(s) , ~ small(s)/same ~ , single input]
            while (!s.empty() && s.top().height < in) {
                // Remove [~ small(s) ~ , single input]
                sum += s.top().num;
                s.pop();
            }
            if (s.empty()){
                // [ (  ) , single input]
                s.emplace(in, 1);
                continue;
            }

            if (s.top().height == in) {
                if ((int) s.size() >= 2) {
                    // [BIG(s) , same , same input]
                    sum += s.top().num + 1;  // Current duplicate + Prev duplicate
                }
                else {
                    // [same , same input]
                    sum += s.top().num;
                }

                s.top().num++;
            }
            else {
                // [BIG(s) , single input]
                sum++;
                s.emplace(in, 1);
            }
        }
    }
    cout << sum;
}