#include <bits/stdc++.h>
using namespace std;

int n, root, del;
vector<int> adj[54];

int dfs(int here) {
    int ret = 0;
    int child = 0;
    for (int there : adj[here]) {
        if(there == del) continue;
        ret += dfs(there);
        child++;
    }
    if(child == 0) return 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if(temp == -1) root = i;
        else {
            adj[temp].push_back(i);
        }
    }

    cin >> del;
    if(del == root) {
        cout << 0;
    }
    else {
        int ret = dfs(root);
        cout << ret;
    }
    return 0;
}