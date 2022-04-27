#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#define NM 55

using namespace std;
typedef long long int ll;

int n, m, K;
struct Fireball {
    int m, s, d;
    Fireball(int m, int s, int d): m(m), s(s), d(d) {}
};
vector<Fireball> a[NM][NM], b[NM][NM];
int dirs[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

void Input() {
    cin >> n >> m >> K;
    while(m--) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        a[r - 1][c - 1].push_back(Fireball(m, s, d));
    }
}

void MoveFireballs() {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) b[i][j].clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j].size() == 0) continue;
            for (int k = 0; k < a[i][j].size(); k++) {
                
                Fireball fireball = a[i][j][k];
                int ny = (i + dirs[fireball.d][0] * fireball.s) % n;
                int nx = (j + dirs[fireball.d][1] * fireball.s) % n;
                if(ny < 0) ny += n;
                if(nx < 0) nx += n;
                b[ny][nx].push_back(fireball);
            }
        }
    }
}

void SplitFireball(int y, int x) {
/*
2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
    1. 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
    2. 파이어볼은 4개의 파이어볼로 나누어진다.
    3. 나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
        1. 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
        2. 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
        3. 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
    4. 질량이 0인 파이어볼은 소멸되어 없어진다.
3. 마법사 상어가 이동을 K번 명령한 후, 남아있는 파이어볼 질량의 합을 구해보자.
*/
    int m_sum = 0, s_sum = 0;
    int even = 0, odd = 0;
    for (int i = 0; i < b[y][x].size(); i++) {
        Fireball fireball = b[y][x][i];
        m_sum += fireball.m;
        s_sum += fireball.s;
        
        if(fireball.d % 2 == 0) even++;
        else odd++;
    }
    int dir = 0;
    if(even == 0 || odd == 0) dir = 0;
    else dir = 1;

    for (int i = dir; i < 8; i += 2) {
        int avg = m_sum / 5;
        if(avg == 0) continue;
        a[y][x].push_back(Fireball(avg, s_sum / b[y][x].size(), i));
    }
}

void Pro() {
    while(K--) {
        // 1. 모든 파이어볼 이동하기
        MoveFireballs();
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j].clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(b[i][j].size() == 1) {
                    a[i][j] = b[i][j];
                }
                else {
                    // 2. 2개 이상의 파이어볼 분리하기
                    SplitFireball(i, j);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < a[i][j].size(); k++) {
                ans += a[i][j][k].m;
            }
        }
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
