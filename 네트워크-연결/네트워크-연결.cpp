#include <bits/stdc++.h>
using namespace std;

struct Node {
    int u, v, w;
    Node(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator <(const Node& node) const {
        return w < node.w;
    }
};

int uf[1004];
int n, m;
vector<Node> edges;
int ret;
int find(int a) {
    return uf[a] < 0 ? a : uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    uf[b] = a;
    return true;
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(uf, uf + 1004, -1);
    cin >> n >> m;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++) {
        Node node = edges[i];
        if(merge(node.u, node.v)) {
            ret += node.w;
        }
    }

    cout << ret;
    return 0;
}