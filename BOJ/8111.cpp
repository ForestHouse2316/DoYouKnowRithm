#include <bits/stdc++.h>
using namespace std;
#define f q.front()
#define val first
#define pre second
#define bin first
//typedef unsigned long long ull;
typedef pair<int, int> pii;
int T, depth, digit, loop, offset, in, logIn, calc;
bool done;
int prev[100][10];
vector<int> gg(10)
vector<pii> history(1000);


int getDigit(int& num, int pos) {
    return (int) (num / pow(10, pos)) % 10;
}

bool like(int num) {
    for (int i = 0; i <= log(num); ++i) {
        if (num / (int) pow(10, i) % 10 > 2) return false;
    }
    return true;
}

vector<int> googoo(int& top) {
    gg.clear();
    for (int times = 0; times < 10; ++times) {
        calc = (int) (in * times + top);
        if (calc % 10 <= 1) gg.push_back(calc);
    }
    return gg;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> in;
        logIn = log(in);
        if (like(in)) { // already favorite number
            cout << in << "\n";
            continue;
        }

        // TODO ~000 shape need to be handled with zero-offset
        queue<pii> q;
        depth = -1;
        q.emplace(0, -1);
        done = false;
        while (!done) {
            depth++;
            loop = q.size();
            while (loop--) {
                for (int eligible : googoo(f.val)) {
                    if (log(eligible) + depth + 1 > 100) break; // because googoo(f) is ascending order
                    if (like(eligible)) {
                        // TODO print stack
                        done = true;
                        break;
                    } // TODO from here... SYNC
                    q.emplace(eligible / 10, history.size() - 1);
                    history.emplace_back(eligible / 10, pre);
                }
                q.pop();
            }
            if (!done) cout << "BRAK\n";

        }

        // 현재 자릿수를 0 또는 1로 만드는 배수를 기준으로 계속 뻗어나감. vis는 없고 모든 경우에 대해 뻗어나가기만 할 뿐임
        //예를 들어 17 이면 정답은 17 * 653인데 가능한 케이스들은 각 자릿수에서 다음과 같다 :
        // 3
        // 5
        // 3 6
        // 일의자리 십의자리는 후보군이 하나이므로 그냥 들어가면 되고
        // 마지막에 3과 6 두  갈래로 나뉘어져 들어갈텐데, 6에서 구사과가 좋아하는 숫자가 나왔으므로 종료, 위로 거슬러 올라가야 하는데
        // 이거는 히스토리를 만들어놓아야 할듯. prev[depth][0-9] 과 같이 하고 최대 depth는 무조건 100 이하인 점을 이용.
        // 높은 depth부터 순차적으로 결과에다가 저장해놓고 한 번에 출력하든가 하면 될듯. 높은 depth = 높은 자릿수 의미.

    }
}