#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#define NM 5
#define N 4

using namespace std;
typedef long long int ll;

int ans;
struct Fish {
    int num, dir;
    Fish() {}
    Fish(int num, int dir) : num(num), dir(dir) {}
};
Fish a[NM][NM];
int dirs[8][2] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };

struct Shark {
    int y, x, score, dir;
    Shark() {}
    Shark(int y, int x, int score, int dir) : y(y), x(x), score(score), dir(dir) {}
}; 
Shark teenShark;

inline bool InRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

void print() {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j].num << ' ';
        }
        cout << '\n';
    }
}

inline bool CanGo(int y, int x) {
    return InRange(y, x) && a[y][x].num != -1 && a[y][x].dir != -1;
}

void MoveFish() {
    // 2. 작은 번호 물고기 움직이기
    //  2.1. 이동할 수 있는 칸은 빈칸, 다른 물고기가 있는 칸
    //  2.2. 이동할 수 없는 칸은 상어, 범위 밖
    //  2.3. 물고기 방향이 이동할 수 있을 때까지 45도 반시계회전
    //  2.4. 갈수없으면, 이동불가
    //  2.5. 물고기가 잇는 곳으로가면 자리 교환
    for (int num = 1; num <= N * N; num++) {

        bool flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                if (a[i][j].num == num) {
                    for (int d = 0; d < 8; d++) {
                        int nd = (a[i][j].dir + d) % 8;
                        int ny = i + dirs[nd][0];
                        int nx = j + dirs[nd][1];

                        if (!InRange(ny, nx)) continue;
                        if (ny == teenShark.y && nx == teenShark.x) continue;
                        if(CanGo(ny, nx)) a[i][j] = Fish(num, nd);
                        
                        flag = true;
                        swap(a[i][j], a[ny][nx]);
                        break;
                    }
                    if(flag) break;
                }

            }
            if(flag) break;
        }
    }
}

inline bool SharkGo(int y, int x) {
    return InRange(y, x) && (a[y][x].dir != -2 && a[y][x].num != -2);
}

inline bool IsFinish() {
    for (int i = 1; i < 4; i++) {
        int ny = teenShark.y + dirs[teenShark.dir][0] * i;
        int nx = teenShark.x + dirs[teenShark.dir][1] * i;
        if(SharkGo(ny, nx)) return false;
    }
    return true;
}

void MoveShark() {
    // 3. 청소년 상어 움직이기
    //  3.1. 한번에 여러 칸 이동가능
    //  3.2. 물고기가 있다면, 물고기 먹고 그 물고기 방향 갖는다.
    //  3.3. 물고기가 없는 칸 이동불가, 상어가 이동할 수 있는 칸이 없으면 공간에 벗어나기!
    if (IsFinish()) {
        ans = max(ans, teenShark.score);
        return;
    }

    for (int i = 1; i < 4; i++) {
        int ny = teenShark.y + dirs[teenShark.dir][0] * i;
        int nx = teenShark.x + dirs[teenShark.dir][1] * i;
        if(!SharkGo(ny, nx)) continue;

        Fish b[N][N];
        Shark tempShark = teenShark;
        for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) b[j][k] = a[j][k];

        Fish next_Fish = a[ny][nx];
        a[ny][nx] = Fish(-1, -1);
        a[teenShark.y][teenShark.x] = Fish(-2, -2);
        teenShark.y = ny; teenShark.x = nx;
        teenShark.dir = next_Fish.dir;
        teenShark.score += next_Fish.num;

        MoveFish();
        MoveShark();

        for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) a[j][k] = b[j][k];
        teenShark = tempShark;
    }
}

void Input() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num, dir;
            cin >> num >> dir;
            a[i][j] = Fish(num, dir - 1);
        }
    }    
}

void Pro() {
    // 1. 청소년 상어(0,0)에서 물고기 먹고 물고기 방향 갖기
    teenShark = Shark(0, 0, a[0][0].num, a[0][0].dir); 
    a[0][0] = Fish(-1, -1);
    // 2. 작은 번호 물고기 움직이기
    MoveFish();
    // 3. 청소년 상어 움직이기
    MoveShark();
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Pro();
    return 0;
}
