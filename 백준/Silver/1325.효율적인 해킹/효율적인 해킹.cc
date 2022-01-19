#include <bits/stdc++.h>
using namespace std;

int n, m, _max;
vector<int> adj[10004];
bool visited[10004];
vector<pair<int, int>> ret;

int dfs(int here) {
    visited[here] = 1;
    int cnt = 1;
    for(int there : adj[here]) {
        if(visited[there]) continue;
        cnt += dfs(there);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        fill(visited, visited + 10004, 0);
        int cnt = dfs(i);
        _max = max(cnt, _max);
        ret.push_back({i, cnt});
    }
    sort(ret.begin(), ret.end());    
    for (int i = 0; i < ret.size(); i++) {
        if(ret[i].second == _max) {
            cout << ret[i].first << ' ';
        }
    }

    
    return 0;
}