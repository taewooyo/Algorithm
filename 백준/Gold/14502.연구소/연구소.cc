#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, a[10][10];
bool visited[10][10];
vector<pair<int, int>> w;
vector<pair<int, int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if(a[ny][nx] == 0) dfs(ny, nx);
    }
}

int go() {
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == 2 && !visited[i][j]) dfs(i, j);
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!visited[i][j] && a[i][j] == 0) ret++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) w.push_back({i, j});
        }
    }

    int ret = 0;
    for (int i = 0; i < w.size(); i++) {
        for (int j = i+1; j < w.size(); j++) {
            for (int k = j+1; k < w.size(); k++) {
                a[w[i].first][w[i].second] = 1;
                a[w[j].first][w[j].second] = 1;
                a[w[k].first][w[k].second] = 1;
                ret = max(ret, go());
                a[w[i].first][w[i].second] = 0;
                a[w[j].first][w[j].second] = 0;
                a[w[k].first][w[k].second] = 0;
            }
        }
    }

    cout << ret;
    return 0;
}