#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define NM 55

int dirs[8][2] = {
    {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int a[NM][NM], groom[NM][NM], next_groom[NM][NM];
int n, m;
void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void Make_groom() {
    groom[n-1][0] = 1;
    groom[n-1][1] = 1;
    groom[n-2][0] = 1;
    groom[n-2][1] = 1;
}

void Move(int dir, int s) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            next_groom[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(groom[i][j]) {
                int ny = ((i + s * dirs[dir][0])) % n;
                int nx = ((j + s * dirs[dir][1])) % n;
                if(ny < 0) ny += n;
                if(nx < 0) nx += n;
                next_groom[ny][nx] = 1;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            groom[i][j] = next_groom[i][j];
        }
    }
}

void Grow() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(groom[i][j]) a[i][j]++;
        }
    }
}

inline bool InRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

void DiagonalGrow() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(groom[i][j]) {

                int count = 0;
                for (int d = 1; d < 8; d += 2) {
                    int ny = i + dirs[d][0];
                    int nx = j + dirs[d][1];
                    if(InRange(ny, nx) && a[ny][nx] > 0) count++;
                }
                a[i][j] += count;
            }
        }
    }
}

void UpdateGroom() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            next_groom[i][j] = 0;
        }
    }    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] >= 2 && groom[i][j] == 0) {
                next_groom[i][j] = 1;
                a[i][j] -= 2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            groom[i][j] = next_groom[i][j];
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << groom[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Pro() {
    Make_groom();
    for(int rep = 1; rep <= m; rep++) {
        int d, s;
        cin >> d >> s;
    
        Move(d - 1, s);    
        Grow();
        DiagonalGrow();
        UpdateGroom();
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += a[i][j];
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
    return 0;
}