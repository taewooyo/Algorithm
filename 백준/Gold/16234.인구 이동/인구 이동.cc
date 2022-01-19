#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int a[104][104], temp[104][104], visited[104][104];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
void bfs(int y, int x) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    int sum = 0;
    q.push({ y, x });
    visited[y][x] = 1;
    sum += a[y][x];
    v.push_back({ y, x });
    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx]) continue;
            if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
                visited[ny][nx] = 1;
                q.push({ ny, nx });
                v.push_back({ ny, nx });
                sum += a[ny][nx];
            }
        }
    }
    for (auto it : v) {
        int y = it.first, x = it.second;
        temp[y][x] = sum / v.size();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ret = 0;
    while (true) {
        bool flag = false;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) temp[i][j] = a[i][j];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) bfs(i, j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != temp[i][j]) {
                    a[i][j] = temp[i][j];
                    flag = true;
                }
            }
        }
        if (!flag) break;
        ret++;
    }
    cout << ret;
    return 0;
}
