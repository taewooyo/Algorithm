#include <iostream>
using namespace std;

int r, c;
char grid[10][10];
char next_grid[10][10];
bool inRange(int y, int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}

bool isAlive(int y, int x) {
    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    int cnt = 0;
    for(int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(!inRange(ny, nx) || grid[ny][nx] == '.') {
            cnt++;
        }
    }
    return cnt >= 3;
}

pair<int, int> getStartPos() {
    pair<int, int> cur;
    bool flag = false;
    for(int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if(next_grid[row][col] == 'X') {
                flag = true;
                cur.first = row;
                break;
            }
        }
        if(flag) break;
    }

    flag = false;
    for (int col = 0; col < c; col++) {
        for (int row = 0; row < r; row++) {
            if(next_grid[row][col] == 'X') {
                flag = true;
                cur.second = col;
                break;
            }
        }
        if(flag) break;
    }
    return cur;
}

pair<int, int> getLastPos() {
    pair<int, int> cur;
    bool flag = false;
    for (int row = r-1; row >= 0; row--) {
        for (int col = c-1; col >= 0; col--) {
            if(next_grid[row][col] == 'X') {
                cur.first = row;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    flag = false;
    for (int col = c-1; col >= 0; col--) {
        for (int row = 0; row < r; row++) {
            if(next_grid[row][col] == 'X') {
                cur.second = col;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for (int row = 0; row < r; row++) {
        string s;
        cin >> s;
        for (int col = 0; col < c; col++) {
            grid[row][col] = s[col];
        }
    }

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            next_grid[row][col] = '.';
        }
    }

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if(grid[row][col] == '.') continue;
            if(!isAlive(row, col)) {
                next_grid[row][col] = grid[row][col];
            }
        }
    }

    pair<int, int> start = getStartPos();
    pair<int, int> finish = getLastPos();

    for (int row = start.first; row <= finish.first; row++) {
        for (int col = start.second; col <= finish.second; col++) {
            cout << next_grid[row][col];
        }
        cout << '\n';
    }
}