#include <bits/stdc++.h>
using namespace std;

int h, w, a[104][104];
queue<pair<int, int>> q;
int visited[104][104];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            a[i][j] = s[j];
            if(s[j] == 'c') a[i][j] = 0;
            else a[i][j] = -1;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w-1; j++) {
            if(a[i][j] == 0) {
                int cnt = 1;
                while(a[i][j+1] == -1) {
                    a[i][j+1] = cnt++;
                    j = j+1;
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}