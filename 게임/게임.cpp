#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, ans;
char a[51][51];
bool visited[51][51];
int dp[51][51];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool dfs(int y, int x, int cnt) {
    if(ans == -1) return true;
    ans = max(ans, cnt);
    visited[y][x] = true;
    dp[y][x] = cnt;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i] * (a[y][x] - '0');
        int nx = x + dx[i] * (a[y][x] - '0');

        if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 'H') continue;
        if(visited[ny][nx]) {
            ans = -1;
            return true;
        }
        if(dp[ny][nx] > 0 && cnt < dp[ny][nx]) continue;
        if(dfs(ny, nx, cnt + 1)) return true;
    }
    visited[y][x] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++) a[i][j] = s[j];
    }
    dfs(0, 0, 1);
    cout << ans;
}