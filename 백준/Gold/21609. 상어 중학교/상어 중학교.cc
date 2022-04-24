#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define NM 21

using namespace std;
typedef long long int ll;

int ans;
int n, m;
int a[NM][NM], b[NM][NM];
bool visited[NM][NM], rainbowVisited[NM][NM];
struct Group {
    int y, x; // 기준점
    int rainbow; // 무지개블록 갯수
    int size; // 총 그룹의 크기

    Group(int y, int x, int rainbow, int size): y(y), x(x), rainbow(rainbow), size(size) {};

    bool operator < (const Group& g) const {
        if (size != g.size) return size > g.size;
        if (rainbow != g.rainbow) return rainbow > g.rainbow;
        if (y != g.y) return y > g.y;
        return x > g.x;
    }
};

vector<Group> groups;
queue<pair<int, int>> Q;
int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

inline bool InRange(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

void Bfs(int i, int j, int color) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) rainbowVisited[i][j] = false;
    Q.push({i, j});
    visited[i][j] = true;
    int cnt = 1, rainbow = 0;

    while(!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dirs[i][0];
            int nx = x + dirs[i][1];

            if(!InRange(ny, nx) || visited[ny][nx] || rainbowVisited[ny][nx]) continue;
            if(a[ny][nx] == 0) { // 무지개 블록인 경우
                rainbowVisited[ny][nx] = true;
                Q.push({ny, nx});
                cnt++;
                rainbow++;
            }
            else if(a[ny][nx] == color) { // 같은 색인 경우
                visited[ny][nx] = true;
                Q.push({ny, nx});
                cnt++;
            }
        }
    }
    if(cnt >= 2) groups.push_back(Group(i, j, rainbow, cnt));
}

Group GetBigGroup() { // 가장 큰 그룹 찾기
    groups.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited[i][j]) continue;
            if(a[i][j] == -1 || a[i][j] == -2 || a[i][j] == 0) continue;
            Bfs(i, j, a[i][j]);
        }
    }
    sort(groups.begin(), groups.end());
    if(groups.size()) return groups[0];
    return Group(-1, -1, -1, -1);
}

void RemoveGroup(Group group) { // 찾은 그룹 제거
    Q.push({group.y, group.x});
    int color = a[group.y][group.x];
    a[group.y][group.x] = -2;

    while(!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dirs[i][0];
            int nx = x + dirs[i][1];
            if(!InRange(ny, nx)) continue;
            if(a[ny][nx] == 0 || a[ny][nx] == color) {
                Q.push({ny, nx});
                a[ny][nx] = -2;
            }
        }
    }
}

void Gravity() { // 중력 작용
    for (int j = 1; j <= n; j++) {
        int last = n+1;
        for (int i = n; i >= 1; i--) {
            if(a[i][j] == -2) continue;
            if(a[i][j] == -1) {
                last = i;
                continue;
            }
            a[--last][j] = a[i][j];
            if(last != i) a[i][j] = -2;
        }
    }
}

void Rotate() { // 회전하기
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) b[i][j] = -2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] = a[j][n-i+1];
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = b[i][j];
}

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

void Pro() {
    while(true) {
        Group group = GetBigGroup();
        if(group.size < 2) break;
        ans += group.size * group.size;
        RemoveGroup(group);
        Gravity();
        Rotate();
        Gravity();
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Pro();
    return 0;
}