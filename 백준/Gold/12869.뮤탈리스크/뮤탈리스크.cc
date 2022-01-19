#include <bits/stdc++.h>
using namespace std;

int convert[][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {1, 9, 3},
    {1, 3, 9},
    {3, 1, 9},
    {3, 9, 1}
};
struct Node {
    int a, b, c;
};
int n;
queue<Node> q;
int visited[64][64][64];
int a[3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    

    q.push({a[0], a[1], a[2]});
    visited[a[0]][a[1]][a[2]] = 1;

    while(q.size()) {
        Node node = q.front();
        q.pop();
        if(visited[0][0][0]) break;
        for (int i = 0; i < 6; i++) {
            int na = max(0, node.a - convert[i][0]);
            int nb = max(0, node.b - convert[i][1]);
            int nc = max(0, node.c - convert[i][2]);
            if(visited[na][nb][nc]) continue;
            q.push({na, nb, nc});
            visited[na][nb][nc] = visited[node.a][node.b][node.c] + 1;
        }
    }
    cout << visited[0][0][0] - 1;
    return 0;
}