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

        // ���� �ڸ����� 0 �Ǵ� 1�� ����� ����� �������� ��� �����. vis�� ���� ��� ��쿡 ���� ������⸸ �� ����
        //���� ��� 17 �̸� ������ 17 * 653�ε� ������ ���̽����� �� �ڸ������� ������ ���� :
        // 3
        // 5
        // 3 6
        // �����ڸ� �����ڸ��� �ĺ����� �ϳ��̹Ƿ� �׳� ���� �ǰ�
        // �������� 3�� 6 ��  ������ �������� ���ٵ�, 6���� ������� �����ϴ� ���ڰ� �������Ƿ� ����, ���� �Ž��� �ö󰡾� �ϴµ�
        // �̰Ŵ� �����丮�� �������ƾ� �ҵ�. prev[depth][0-9] �� ���� �ϰ� �ִ� depth�� ������ 100 ������ ���� �̿�.
        // ���� depth���� ���������� ������ٰ� �����س��� �� ���� ����ϵ簡 �ϸ� �ɵ�. ���� depth = ���� �ڸ��� �ǹ�.

    }
}