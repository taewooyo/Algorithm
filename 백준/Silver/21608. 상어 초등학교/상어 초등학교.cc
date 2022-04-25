#include <iostream>
#include <cmath>
#include <tuple>
using namespace std;

typedef tuple<int, int, int, int> Node;
int n;
int grid[21][21];
int target_num[401];
bool friends[401][401];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool IsFriend(int num1, int num2) {
    return friends[num1][num2];
}

bool InRange(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

Node GetCurrNode(int target, int y, int x) {
    int friend_cnt = 0, blank_cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (InRange(ny, nx)) {
            if (grid[ny][nx] == 0)
                blank_cnt++;
            else if (IsFriend(target, grid[ny][nx]))
                friend_cnt++;
        }
    }
    return make_tuple(-friend_cnt, -blank_cnt, y, x);
}

void Move(int target) {
    Node best_node = make_tuple(0, 0, n+1, n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == 0) {
                Node curr = GetCurrNode(target, i, j);

                if (best_node > curr)
                    best_node = curr;
            }
        }
    }
    int y, x;
    tie(ignore, ignore, y, x) = best_node;
    grid[y][x] = target;
}

int Score(int y ,int x) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(InRange(ny, nx) && IsFriend(grid[y][x], grid[ny][nx]))
            cnt++;
    }
    return (int)pow(10, cnt-1);
}

int GetScore() {
    int score = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            score += Score(i, j);
        }
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n*n; i++) {
        cin >> target_num[i];
        for (int j = 1; j <= 4; j++) {
            int friend_num;
            cin >> friend_num;
            friends[target_num[i]][friend_num] = true;
        }
    }

    for (int i = 1; i <= n * n; i++)
        Move(target_num[i]);

    int answer = GetScore();
    cout << answer;

}