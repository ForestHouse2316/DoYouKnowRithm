#include <bits/stdc++.h>
using namespace std;

int L, C, lastVowIdx=-1, lastConIdx=-1;
char chars[15], comb[15], vowels[]={'a', 'e', 'i', 'o', 'u'};

bool isVowel(char c) {
    for (char v : vowels) {
        if (c == v) return true;
    }
    return false;
}

void rec(int start, int depth, int con, int vow) {
    if (depth == L) {
        if (con < 2 ||  vow < 1) return;
        for (int l = 0; l < L; ++l) {
            cout << comb[l];
        }
        cout << "\n";
        return;
    }

    for (int c = start; c < C; ++c) {
        if (vow < 1 && lastVowIdx < c || con < 2 && lastConIdx < c) break;
        comb[depth] = chars[c];
        bool isVow = isVowel(comb[depth]);
        rec(c+1, depth+1, isVow ? con : con + 1, isVow ? vow + 1 : vow);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> L >> C;
    for (int c = 0; c < C; ++c) {
        cin >> chars[c];
    }

    sort(chars, chars+C);
    for (int c = 0; c < C; ++c) {
        if (isVowel(chars[c])) lastVowIdx = c;
        else lastConIdx = c;
    }
    rec(0, 0, 0, 0);
}