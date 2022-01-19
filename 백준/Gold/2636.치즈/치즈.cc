#include <bits/stdc++.h>
using namespace std;

int n, m, a[104][104];
queue<pair<int, int>> q;
bool visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ans1, ret;

bool bfs() {
    visited[0][0] = 0;
    q.push({0, 0});
    ans1++;
    int ans2 = 0;
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == 0) {
                q.push({ny, nx});
            }
            else {
                a[ny][nx] = 0;
                ans2++;
            }
            visited[ny][nx] = 1;
        }
    }

    if(ans2 == 0) {
        cout << --ans1 << "\n" << ret;
        return true;
    }
    else {
        ret = ans2;
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while(true) {
        fill(&visited[0][0], &visited[0][0] + 104*104, 0);
        if(bfs()) break;
    }

    return 0;
}