#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int N, K, L, time, idx;
int graph[100][100];
int visit[100][100];
vector<pair<int, int>> v;

void input() {
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        graph[x - 1][y - 1] = 1;
    }

    cin >> L;
    for(int i = 0; i < L; i++) {
        int x; char c;
        cin >> x >> c;
        if(c == 'D') v.push_back({x, 1});
        if(c == 'L') v.push_back({x, 3});
    }
}

void pro() {
    deque<pair<int, int>> dq;
    dq.push_back({0, 0});
    int dir = 1;

    while(!dq.empty()) {
        time++;
        
        int x = dq.front().first;
        int y = dq.front().second;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(visit[nx][ny] || nx < 0 || ny < 0 || nx == N || ny == N) break;
        if(!graph[nx][ny]) {
            visit[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        else {
            graph[nx][ny] = 0;
        }
        visit[nx][ny] = 1;
        dq.push_front({nx, ny});
        if(time == v[idx].first) {
            dir = (dir + v[idx].second) % 4;
            idx++;
        }
    }
    cout << time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    pro();
    return 0;
}