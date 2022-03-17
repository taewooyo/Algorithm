#include <bits/stdc++.h>
using namespace std;
int r, c;
int gr, gc, br, bc;
char grid[100][100];
int main() {
    cin >> r >> c;
    cin >> gr >> gc >> br >> bc;

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> grid[i][j];

    int cnt = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(grid[i][j] == 'P') cnt++;

    if(br * bc == cnt) cout << 0;
    else cout << 1;
}