#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[5][5], visited[5][5];
void go(int y, int x) {
    if(y == 4) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < m; j++) {
                if(visited[i][j] == 1) temp = temp * 10 + a[i][j];
                else {
                    sum += temp;
                    temp = 0;
                }
            }
            sum += temp;
        }

        for (int i = 0; i < m; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if(visited[j][i] == 2) temp = temp * 10 + a[j][i];
                else {
                    sum += temp;
                    temp = 0;
                }
            }
            sum += temp;
        }
        ret = max(ret, sum);
        return;
    }

    if(x == 4) {
        go(y+1, 0);
        return;
    }

    visited[y][x] = 1;
    go(y, x+1);
    visited[y][x] = 2;
    go(y ,x+1);
}

int main(){ 
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    go(0, 0);
    cout << ret;
}