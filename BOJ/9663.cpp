#include <bits/stdc++.h>
using namespace std;


int N;
int placeCount = 0;
bool isQueenPlacedOnCol[15] = {false};  // For speed-up calculation
bool queenBoard[15][15] = {false};  // [X row][Y col]

void setQueenOn(int row, int col, int set) {
    isQueenPlacedOnCol[col] = set;
    queenBoard[row][col] = set;
}

void placeQueen(int row) {
    if (row == N) {
        placeCount++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isQueenPlacedOnCol[col]) continue;  // Filter by column
        bool pass = false;
        for (int up = 1; up <= row; up++) {
            if (col-up >= 0 && queenBoard[row-up][col-up]) pass = true;
            if (col+up < N && queenBoard[row-up][col+up]) pass = true;
        }
        if (pass) continue;
        setQueenOn(row, col, true);
        placeQueen(row+1);
        setQueenOn(row, col, false);
    }
}

int main() {
    cin >> N;

    for (int col = 0; col < (int)N/2; col++) {
        setQueenOn(0, col, true);
        placeQueen(1);
        setQueenOn(0, col, false);
    }
    placeCount *= 2;

    if (N%2) {
        setQueenOn(0, N/2, true);
        placeQueen(1);
        setQueenOn(0, N/2, false);
    }

    cout << placeCount;
}