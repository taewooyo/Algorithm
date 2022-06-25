#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, P, X;
int num_flag[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}
};

void Input() {
    cin >> N >> K >> P >> X;
}

int diff_one(int x, int y) {
    int res = 0;
    for (int i = 0; i < 7; i++)
        res += num_flag[x][i] != num_flag[y][i];
    return res;
}

int diff(int x, int y) {
    int res = 0;
    for (int rep = 0; rep < K; rep++) {
        res += diff_one(x % 10, y % 10);
        x /= 10;
        y /= 10;
    }
    return res;
}

void Pro() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        if (diff(i, X) <= P) ans++;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}