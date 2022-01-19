#include <bits/stdc++.h>
using namespace std;

int R, C, chk[26];
char a[24][24];
int ret, ny, nx;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

void go(int y, int x, int num, int cnt) {
    
    ret = max(cnt, ret);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        int next_ = (1 << (int)(a[ny][nx] - 'A'));
        if((num & next_) == 0)
            go(ny, nx, num | next_, cnt+1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> a[i];
    }
    
    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);
    cout << ret << '\n';
    return 0;
}