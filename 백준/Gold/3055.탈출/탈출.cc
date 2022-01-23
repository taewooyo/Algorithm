#include <bits/stdc++.h>

using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int r, c, ans;
int a[54][54];
pair<int, int> biber, start;
queue<pair<int, int>> q;
int water_visited[54][54], visited[54][54];
bool flag;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        string s; cin >> s;
        for(int j = 0; j < c; j++) {
            a[i][j] = s[j];
            if(s[j] == 'D') biber = {i, j};
            else if(s[j] == 'S') start = {i, j};
            else if(s[j] == '*') {
                q.push({i, j});
                water_visited[i][j] = 1;
            }
        }
    }

    while(q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(water_visited[ny][nx]) continue;
            if(a[ny][nx] == 'X' || a[ny][nx] == 'D') continue;
            water_visited[ny][nx] = water_visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    q.push(start);
    visited[start.first][start.second] = 1;
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        if(y == biber.first && x == biber.second) {
            flag = true;
            ans = visited[y][x];
            break;
        }

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx] == 'X') continue;
            if(!water_visited[ny][nx] || visited[y][x] + 1 < water_visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    if(flag) cout << ans - 1 << '\n';
    else cout << "KAKTUS" << '\n';
    return 0;
}