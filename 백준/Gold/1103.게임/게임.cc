#include <bits/stdc++.h>

using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int n, m, ans;
char a[54][54];
bool visited[54][54];
int dp[54][54];
void go(int y, int x, int cnt) {
    if(ans == -1) return;
    ans = max(ans, cnt);
    dp[y][x] = cnt;
    visited[y][x] = true;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i] * (a[y][x] - '0');
        int nx = x + dx[i] * (a[y][x] - '0');
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 'H') continue;
        if(visited[ny][nx]) {
            ans = -1;
            continue;
        }
        if(dp[ny][nx] > 0 && dp[ny][nx] > cnt) continue;
        go(ny, nx, cnt + 1);
        visited[ny][nx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }
    
    go(0, 0, 1);
    cout << ans;
    return 0;
}