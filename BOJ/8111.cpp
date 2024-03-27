#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define a first
#define b second
typedef pair<int, int> pii;
short T;
ll in, result[10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> in;
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