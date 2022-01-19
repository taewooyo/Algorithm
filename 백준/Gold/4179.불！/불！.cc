#include <bits/stdc++.h>
using namespace std;

int r, c, pr, pc, ret;
int fire_visited[1004][1004], person_visited[1004][1004];
char a[1004][1004];
queue<pair<int, int>> q;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, 987654321);
    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < c; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'F') {
                q.push({ i, j });
                fire_visited[i][j] = 1;
            }
            else if (a[i][j] == 'J') pr = i, pc = j;
        }
    }

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (fire_visited[ny][nx] != 987654321 || a[ny][nx] == '#') continue;
            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    person_visited[pr][pc] = 1;
    q.push({ pr, pc });
    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        if (y == r-1 || y == 0 || x == c-1 || x == 0) {
            ret = person_visited[y][x];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (a[ny][nx] == '#' || person_visited[ny][nx]) continue;
            if (fire_visited[ny][nx] <= person_visited[y][x] + 1) continue;
            person_visited[ny][nx] = person_visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    if (ret != 0) cout << ret << "\n";
    else cout << "IMPOSSIBLE\n";
    
    return 0;
}
