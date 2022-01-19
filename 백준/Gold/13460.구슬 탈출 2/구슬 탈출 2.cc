#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int rx, ry, bx, by;
    int depth;
};

int n, m, cnt;
int dx[] = {0, 0, -1, 1}; // 동 서 북 남
int dy[] = {1, -1, 0, 0};
int visit[11][11][11][11];
int hole_x, hole_y, red_x, red_y, blue_x, blue_y;
char _map[11][11];
void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) {
            _map[i][j] = s[j];
            if(s[j] == 'O') {
                hole_x = i; hole_y = j;
            }
            else if(s[j] == 'R') {
                red_x = i; red_y = j;
            }
            else if(s[j] == 'B') {
                blue_x = i; blue_y = j;
            }
        }
    }
}

void move(int &x, int &y, int dir) {
    while(1) {
        if(_map[x][y] == '#') {
            x -= dx[dir];
            y -= dy[dir];
            break;
        }
        else if(_map[x][y] == 'O') {
            break;
        }
        else {
            x += dx[dir];
            y += dy[dir];
        }
    }
}

void pro() {
    int answer = -1;

    queue<Node> q;
    q.push({red_x, red_y, blue_x, blue_y, 0});
    visit[red_x][red_y][blue_x][blue_y] = 1;

    while(!q.empty()) {
        Node node = q.front(); q.pop();
        
        if(node.depth > 10) break;
        if(node.rx == hole_x && node.ry == hole_y) {
            answer = node.depth;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int rx = node.rx + dx[i], ry = node.ry + dy[i];
            int bx = node.bx + dx[i], by = node.by + dy[i];
            
            move(rx, ry, i);
            move(bx, by, i);
            
            // 파란공 빨간공 두개다 떨어지면 안되니깐... 파란공 떨어진경우 예외처리하기
            if(bx == hole_x && by == hole_y) {
                continue;
            }
            
            if(rx == bx && ry == by) {
                // 같은 위치가 안되니 하나씩 뺴주기
                if(i == 0) node.ry < node.by ? ry-- : by--; //  동
                if(i == 1) node.ry < node.by ? by++ : ry++; //  서
                if(i == 2) node.rx < node.bx ? bx++ : rx++; //  북
                if(i == 3) node.rx < node.bx ? rx-- : bx--; //  남
            }

            if(!visit[rx][ry][bx][by]) {
                // cout << rx << ' ' << ry << ' ' << bx << ' ' << by << '\n';
                q.push({rx, ry, bx, by, node.depth + 1});
                visit[rx][ry][bx][by] = 1;
            }
        }
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    pro();
    return 0;
}