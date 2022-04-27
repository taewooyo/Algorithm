#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#define NM 505

using namespace std;
typedef long long int ll;

int a[NM][NM], b[5][5];
int y, x;
int n, ans, len = 1, dir = 0;
int dirs[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int ratioDust[5][5] = {
    {0, 0, 2, 0, 0},
    {0, 10, 7, 1, 0},
    {5, 0, 0, 0, 0},
    {0, 10, 7, 1, 0},
    {0, 0, 2, 0, 0}
};

void Rotate() { // 좌 하 우 상 // 반시계
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) b[i][j] = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            b[i][j] = ratioDust[j][5 - i - 1];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ratioDust[i][j] = b[i][j];
        }
    }
}

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }    
}

inline bool InRange(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x<= n;
}

void AddDust(int y, int x, int dust) {
    if(!InRange(y, x)) ans += dust;
    else a[y][x] += dust;
}

void Move() {
    y += dirs[dir][0];
    x += dirs[dir][1];
    int addDust = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dust = a[y][x] * ratioDust[i][j] / 100;
            AddDust(y + i - 2, x + j - 2, dust);
            addDust += dust;
        }
    }
    AddDust(y + dirs[dir][0], x + dirs[dir][1], a[y][x] - addDust);
}

void MoveTornado() {
    y = n / 2 + 1, x = n / 2 + 1;
    while(!(y == 1 && x == 1)) {
        for (int i = 0; i < len; i++) {
            Move();
            if(y == 1 && x == 1) break;
        }
        dir = (dir + 1) % 4;
        Rotate();
        if (dir == 0 || dir == 2) len++;
    }
}

void Pro() {
    MoveTornado();
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Pro();
    return 0;
}
