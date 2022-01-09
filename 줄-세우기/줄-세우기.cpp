#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int in[32004];
vector<int> adj[32004];
queue<int> q;
int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].emplace_back(b);
        in[b]++;
    }
    for(int i = 1; i <= n; i++) if(!in[i]) q.push(i);

    while(q.size()) {
        int here = q.front();
        q.pop();
        cout << here << " ";
        for(int there: adj[here]) {
            in[there]--;
            if(!in[there]) q.push(there);
        }
    }
    return 0;
}